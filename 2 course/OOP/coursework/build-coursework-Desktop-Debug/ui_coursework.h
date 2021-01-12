/********************************************************************************
** Form generated from reading UI file 'coursework.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COURSEWORK_H
#define UI_COURSEWORK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_courseworkClass
{
public:
    QAction *actionSave;
    QAction *actionLoad;
    QAction *actionAdd;
    QAction *actionDelete;
    QAction *actionMerge;
    QWidget *centralWidget;
    QTableView *tableView;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *courseworkClass)
    {
        if (courseworkClass->objectName().isEmpty())
            courseworkClass->setObjectName(QString::fromUtf8("courseworkClass"));
        courseworkClass->resize(859, 607);
        actionSave = new QAction(courseworkClass);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionLoad = new QAction(courseworkClass);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionAdd = new QAction(courseworkClass);
        actionAdd->setObjectName(QString::fromUtf8("actionAdd"));
        actionDelete = new QAction(courseworkClass);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        actionMerge = new QAction(courseworkClass);
        actionMerge->setObjectName(QString::fromUtf8("actionMerge"));
        centralWidget = new QWidget(courseworkClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 40, 811, 451));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(660, 10, 161, 23));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 10, 631, 20));
        courseworkClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(courseworkClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 859, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        courseworkClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(courseworkClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        courseworkClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(courseworkClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        courseworkClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(actionSave);
        menu->addAction(actionLoad);
        menu_2->addAction(actionAdd);
        menu_2->addAction(actionDelete);
        menu_2->addAction(actionMerge);
        mainToolBar->addSeparator();

        retranslateUi(courseworkClass);

        QMetaObject::connectSlotsByName(courseworkClass);
    } // setupUi

    void retranslateUi(QMainWindow *courseworkClass)
    {
        courseworkClass->setWindowTitle(QCoreApplication::translate("courseworkClass", "coursework", nullptr));
        actionSave->setText(QCoreApplication::translate("courseworkClass", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        actionLoad->setText(QCoreApplication::translate("courseworkClass", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        actionAdd->setText(QCoreApplication::translate("courseworkClass", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        actionDelete->setText(QCoreApplication::translate("courseworkClass", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        actionMerge->setText(QCoreApplication::translate("courseworkClass", "\320\241\320\273\320\270\321\217\320\275\320\270\320\265", nullptr));
        pushButton->setText(QCoreApplication::translate("courseworkClass", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        menu->setTitle(QCoreApplication::translate("courseworkClass", "\320\244\320\260\320\271\320\273", nullptr));
        menu_2->setTitle(QCoreApplication::translate("courseworkClass", "\320\221\320\224", nullptr));
    } // retranslateUi

};

namespace Ui {
    class courseworkClass: public Ui_courseworkClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURSEWORK_H
