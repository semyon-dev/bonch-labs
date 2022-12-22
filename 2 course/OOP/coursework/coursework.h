#pragma once
#include <vector>

#include <QtWidgets/QMainWindow>
#include "ui_coursework.h"

#include "DataBase.h"

class coursework : public QMainWindow
{
    Q_OBJECT

public:
    coursework(QWidget *parent = Q_NULLPTR);

private:
    void clearTable();
    void tableSlotInit();
    void updateTable();
    void synchronize();

    Ui::courseworkClass ui;

    std::vector<int> ratio_table;
    DataBase bd;
    int sellect_row;
    QString find_str;

private slots:
    void slot_sellect(QModelIndex, QModelIndex);

    void slot_load_bd_in_file();
    void slot_write_bd_in_file();

    void slot_add_bd_line();
    void slot_delete_bd_line();
    void slot_merge_bd();

    void slot_bd_find();
};
