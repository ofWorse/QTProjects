/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *txtFirstNum;
    QLineEdit *txtSecondNum;
    QPushButton *btnAdd;
    QPushButton *btnSubtract;
    QPushButton *btnDevide;
    QPushButton *butMultiply;
    QLabel *label_3;
    QLineEdit *txtResult;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(445, 324);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 80, 91, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 110, 101, 21));
        txtFirstNum = new QLineEdit(centralwidget);
        txtFirstNum->setObjectName(QString::fromUtf8("txtFirstNum"));
        txtFirstNum->setGeometry(QRect(180, 80, 91, 23));
        txtSecondNum = new QLineEdit(centralwidget);
        txtSecondNum->setObjectName(QString::fromUtf8("txtSecondNum"));
        txtSecondNum->setGeometry(QRect(180, 110, 91, 23));
        btnAdd = new QPushButton(centralwidget);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setGeometry(QRect(60, 160, 80, 23));
        btnSubtract = new QPushButton(centralwidget);
        btnSubtract->setObjectName(QString::fromUtf8("btnSubtract"));
        btnSubtract->setGeometry(QRect(150, 160, 80, 23));
        btnDevide = new QPushButton(centralwidget);
        btnDevide->setObjectName(QString::fromUtf8("btnDevide"));
        btnDevide->setGeometry(QRect(240, 160, 80, 23));
        butMultiply = new QPushButton(centralwidget);
        butMultiply->setObjectName(QString::fromUtf8("butMultiply"));
        butMultiply->setGeometry(QRect(330, 160, 80, 23));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 210, 71, 21));
        txtResult = new QLineEdit(centralwidget);
        txtResult->setObjectName(QString::fromUtf8("txtResult"));
        txtResult->setGeometry(QRect(180, 210, 91, 23));
        txtResult->setReadOnly(true);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "First Number: ", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Second Number: ", nullptr));
        btnAdd->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        btnSubtract->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        btnDevide->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        butMultiply->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Result: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
