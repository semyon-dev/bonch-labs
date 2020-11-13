#include <stdio.h>
#include <math.h>
#include "source.h"

const int n = 3; // длина массива

int main() {
    srand(time(0));

    double a[n];
    double b[n];
    double c[n];

    printf("Output arr a:\n");
    random_array(a, n);
    print_array(a, n);

    printf("Output arr b:\n");
    random_array(b, n);
    print_array(b, n);

    printf("Output arr c:\n");
    random_array(c, n);
    print_array(c, n);

    double x[n], y[n];
    double res1 = 0;
    double res2 = 0;

    for (int i = 0; i < n; i++) {
        res1 = 0;
        for (int j = 1; j <= n; j++) {
            res1 += (a[i] * b[i]);
        }
        res2 = 0;
        for (int j = 1; j <= n; j++) {
            res2 += (b[i] * c[i]);
        }

        x[i] = (a[i] * b[i]) - sqrt(res1);
        y[i] = (b[i] * c[i]) - sqrt(res2);
    }

    printf("Result:\n");
    printf("Array X: \n");
    print_array(x, n);
    printf("Array Y: \n");
    print_array(y, n);
    return 0;
}