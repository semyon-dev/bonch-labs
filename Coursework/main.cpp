#include <iostream>
#include <cmath>
#include <fstream>
#include <climits>
#include <string>

using namespace std;

constexpr char const *graph_handl =
        "set zero 0.0\n"
        "set term pop\n"
        "unset colorbox\n"
        "set xlabel \"t\"\n"
        "set ylabel \"u\"\n"
        "set grid front\n"
        "unset grid\n"
        "set size ratio 0.75\n"
        "set xrange [5     : 50    ]\n"
        "set zeroaxis\n"
        "set datafile missing \"NaN\"\n"
        "plot [5     : 50    ] '-' notitle with lines lt rgb \"#0000ff\"\n";


ofstream graph_in;
ofstream graph_out;

constexpr double t_start = 5;
constexpr double t1 = 10;
constexpr double t2 = 15;
constexpr double t3 = 45;
constexpr double t_end = 50;

// пункт A
double input_formula(double t) {
    static constexpr double a = 20;
    static constexpr double b = 0.5;
    static constexpr double c = 17;
    if (t <= t1) {
        return 0;
    } else if (t1 < t && t <= t2) {
        return a * (t - t1);
    } else if (t2 < t && t <= t3) {
        return a * (t2 - t1) - b * (t - t2);
    } else if (t > t3) {
        return a * (t2 - t1) - b * (t3 - t1) - c * (t - t3);
    }
    return 0;
}

// пункт B и C
double calc(uint64_t step, double &t_middle) {

    double dt = (t_end - t_start) / step;
    double max_exit = -999999999999999.0;
    double min_exit = 999999999999999.0;
    double max_exit_t = 0;
    double min_exit_t = 0;

    static constexpr double a = 5;
    static constexpr double b = 0.05;
    static constexpr double input1 = 10.0;
    double exit = 0;
    double t = t_start;
    for (uint64_t i = 0; i < step; i++) {
        double input = input_formula(t);
        cout << "input: " << input << endl;
        graph_in << t << " " << input << endl;

        if (input <= input1) {
            exit = a;
        } else if (input > input1) {
            exit = b * input * input; // bUвх^2
        }

        graph_out << t << " " << exit << endl;
        cout << "exit: " << exit << endl;

        if (exit > max_exit) {
            max_exit = exit;
            max_exit_t = t;
        }
        if (exit < min_exit) {
            min_exit = exit;
            min_exit_t = t;
        }

        t_middle = max_exit_t - min_exit_t;

        t += dt;
    }
    // Разность между минимальным и
    // максимальным значениями выходного сигнала
    return max_exit - min_exit;
}

void draw(const string &path_graph) {
    string param = "gnuplot  -persist " + path_graph;
    if (system((param).c_str()) == 0) {
        cout << "Открытие графика..." << endl;
    } else {
        cout << "Ошибка! Не удалось открыть график!" << endl;
    }
}

int main() {
    setbuf(stdout, NULL);
    string line;
    ifstream in("intro.txt"); // окрываем файл для чтения
    if (in.is_open()) {
        while (getline(in, line)) {
            cout << line << endl;
        }
    }
    in.close();     // закрываем файл

    uint64_t n_custom = 0; // колличество интервалов времени
    cout << "Введите колличество интервалов времени: ";
    cin.exceptions(istream::failbit | istream::badbit);
    input_reguest:
    try {
        cin >> n_custom;
        if (n_custom <= 1)
            throw n_custom;
    }
    catch (...) {
        cout << "Неверный формат ввода. Попробуйте еще раз: ";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        goto input_reguest;
    }

    string path_graph_in = "gnuplot_graph_in.txt";      // путь до графика
    string path_graph_out = "gnuplot_graph_out.txt";    // путь до графика

    graph_in.open(path_graph_in);
    graph_out.open(path_graph_out);

    if (!graph_in.is_open())
        cout << "Ошибка при создании file graph in: " << path_graph_in << endl;
    if (!graph_out.is_open())
        cout << "Ошибка при создании file graph out: " << path_graph_out << endl;

    graph_in << "set title \"In graph\"\n";
    graph_in << graph_handl;
    graph_out << "set title \"Out graph\"\n";
    graph_out << graph_handl;

    uint64_t N = n_custom;
    constexpr double eps = 0.01;
    double delta = eps + 1;       // Задание начального значения погрешности
    constexpr uint64_t n_max = 1000;
    double t0;
    double t;
    double u_max;
    while (delta >= eps && N <= n_max) {
        u_max = calc(N, t);
        if (N != n_custom) {
            delta = abs((t0 - t) / t);
        }
        t0 = t;
        N *= 2;
    }
    if (delta > n_max) {
        cout << "Заданная точность не достигнута" << endl;
        cout << "Фактическая погрешнoсть = " << delta << endl;
    } else {
        N = N / 2;
        cout << "Разность между минимальным и максимальным значениями выходного сигнала " << u_max << endl;
        cout << "Заданная точность достигнута при N= " << N << endl;
        cout << "Фактическая погрешность " << delta << endl;
    }

    graph_in.close();
    graph_out.close();

    draw(path_graph_in);
    draw(path_graph_out);

    return 0;
}