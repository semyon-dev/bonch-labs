#include "coursework.h"
#include <QStandardItemModel>
#include <QFile>
#include <QTableWidget>
#include <QFileDialog>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

coursework::coursework(QWidget* parent)
    : QMainWindow(parent), sellect_row(-1)
{

    ui.setupUi(this);

    connect(ui.actionAdd, SIGNAL(triggered()), this, SLOT(slot_add_bd_line()));
    connect(ui.actionDelete, SIGNAL(triggered()), this, SLOT(slot_delete_bd_line()));
    connect(ui.actionMerge, SIGNAL(triggered()), this, SLOT(slot_merge_bd()));
    connect(ui.actionLoad, SIGNAL(triggered()), this, SLOT(slot_load_bd_in_file()));
    connect(ui.actionSave, SIGNAL(triggered()), this, SLOT(slot_write_bd_in_file()));
    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(slot_bd_find())); // find button
}


//private
void coursework::clearTable()
{
    if (ui.tableView->model() == nullptr)
        return;
    delete ui.tableView->model();
}

void coursework::tableSlotInit()
{
    QItemSelectionModel* sm = ui.tableView->selectionModel();
    connect(sm, SIGNAL(currentRowChanged(QModelIndex, QModelIndex)),
        this, SLOT(slot_sellect(QModelIndex, QModelIndex)));
}

void coursework::updateTable()
{
    clearTable();
    ratio_table.clear();

    QStandardItemModel* model = new QStandardItemModel;
    QStandardItem* item;

    QStringList horizontalHeader;
    horizontalHeader.append(u8"Название");
    horizontalHeader.append(u8"Производитель");
    horizontalHeader.append(u8"Цена");
    horizontalHeader.append(u8"Разрешение");
    horizontalHeader.append(u8"Диагональ");
    horizontalHeader.append(u8"Умный");

    model->setHorizontalHeaderLabels(horizontalHeader);


    for (size_t i_bd = 0, i_vt = 0; i_bd < bd.getSize(); i_bd++)
    {
        if (find_str == "" || bd[i_bd].name.indexOf(find_str) != -1|| bd[i_bd].firm.indexOf(find_str) != -1)
        {
            ratio_table.push_back(i_bd);

            item = new QStandardItem(bd[i_bd].name);
            model->setItem(i_vt, 0, item);

            item = new QStandardItem(bd[i_bd].firm);
            model->setItem(i_vt, 1, item);

            item = new QStandardItem(QString::number(bd[i_bd].price));
            model->setItem(i_vt, 2, item);

            item = new QStandardItem(bd[i_bd].resolution);
            model->setItem(i_vt, 3, item);

            item = new QStandardItem(QString::number(bd[i_bd].diagonal));
            model->setItem(i_vt, 4, item);

            item = new QStandardItem(QString::number(bd[i_bd].smart));
            model->setItem(i_vt, 5, item);


            i_vt++;
        }
    }

    ui.tableView->setModel(model);

    ui.tableView->resizeRowsToContents();
    ui.tableView->resizeColumnsToContents();

    tableSlotInit();
}
void coursework::synchronize()
{
    for (size_t i = 0; i < ui.tableView->model()->rowCount(); i++)
    {

        auto index = ui.tableView->model()->index(i, 0);
        bd[ratio_table[i]].name = ui.tableView->model()->data(index).toString();

        index = ui.tableView->model()->index(i, 1);
        bd[ratio_table[i]].firm = ui.tableView->model()->data(index).toString();

        index = ui.tableView->model()->index(i, 2);
        bd[ratio_table[i]].price = ui.tableView->model()->data(index).toInt();

        index = ui.tableView->model()->index(i, 3);
        bd[ratio_table[i]].resolution = ui.tableView->model()->data(index).toString();

        index = ui.tableView->model()->index(i, 4);
        bd[ratio_table[i]].diagonal = ui.tableView->model()->data(index).toInt();

        index = ui.tableView->model()->index(i, 5);
        bd[ratio_table[i]].smart = ui.tableView->model()->data(index).toBool();
    }
}


//slots
void coursework::slot_sellect(QModelIndex r, QModelIndex)
{
    sellect_row = r.row();
}

void coursework::slot_load_bd_in_file()
{
    QString file_name = QFileDialog::getOpenFileName(this, tr(u8"Open file"),
        "",
        tr("JSON (*.json)"));
    if (file_name == "")
        return;


    find_str = "";

    bd.loadFromFile(file_name);
    updateTable();
}
void coursework::slot_write_bd_in_file()
{
    if (ui.tableView->model() == nullptr)
        return;

    QString file_name = QFileDialog::getSaveFileName(this, tr(u8"Save file"),
        "",
        tr("JSON (*.json)"));
    if (file_name == "")
        return;

    synchronize();
    bd.saveToFile(file_name);
}

void coursework::slot_add_bd_line()
{
    synchronize();
    bd.pushBack(TV());
    updateTable();

    ui.tableView->scrollTo(ui.tableView->model()->index(ui.tableView->model()->rowCount()-1, 0));
}

void coursework::slot_delete_bd_line()
{
    if (sellect_row == -1)
    {
        return;
    }

    synchronize();
    bd.erase(ratio_table[sellect_row], size_t(ratio_table[sellect_row])+1);
    updateTable();
}

void coursework::slot_merge_bd()
{
    if (ui.tableView->model() == nullptr)
        return;

    QString file_name = QFileDialog::getOpenFileName(this, tr("Open file"),
        "",
        tr("JSON (*.json)"));
    if (file_name == "")
        return;

    synchronize();
    find_str = "";
    bd.margeFromFile(file_name);
    updateTable();
}

void coursework::slot_bd_find()
{
    find_str = ui.lineEdit->text();
    synchronize();
    updateTable();
}
