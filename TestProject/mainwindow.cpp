#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int fNum, sNum, result;

void MainWindow::on_btnAdd_clicked()
{
    fNum = ui->txtFirstNum->text().toInt();
    sNum = ui->txtSecondNum->text().toInt();
    result = fNum + sNum;
    ui->txtResult->setText(QString::number(result));
}


void MainWindow::on_btnSubtract_clicked()
{

    fNum = ui->txtFirstNum->text().toInt();
    sNum = ui->txtSecondNum->text().toInt();
    result = fNum - sNum;
    ui->txtResult->setText(QString::number(result));

}


void MainWindow::on_btnDevide_clicked()
{
    fNum = ui->txtFirstNum->text().toInt();
    sNum = ui->txtSecondNum->text().toInt();
    result = fNum / sNum;
    ui->txtResult->setText(QString::number(result));
}


void MainWindow::on_butMultiply_clicked()
{
    fNum = ui->txtFirstNum->text().toInt();
    sNum = ui->txtSecondNum->text().toInt();
    result = fNum * sNum;
    ui->txtResult->setText(QString::number(result));
}

