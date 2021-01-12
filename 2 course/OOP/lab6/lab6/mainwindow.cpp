#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onClick);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onClick()
{
    QString s = ui->comboBox->currentText();
    bool ok, ok2;
    long num1 = ui->lineEdit->text().toLong(&ok, 10);
    long num2 = ui->lineEdit_2->text().toLong(&ok2, 10);
    if (ok == false || ok2 == false) {
        QMessageBox msgBox;
        msgBox.setText("Введенные данные должны быть числами!");
        msgBox.exec();
    }

    long result;
    if (s == "+") {
        result = num1+num2;
    } else if (s == "-") {
        result = num1-num2;
    }  else if (s == "*") {
        result = num1*num2;
    }  else if (s == "/") {
        if (num2 == 0){
            QMessageBox msgBox;
            msgBox.setText("На ноль делить нельзя!");
            msgBox.exec();
            return;
        }
        result = num1/num2;

    }
    ui->lineEdit_3->setText(QString::number(result));
}

