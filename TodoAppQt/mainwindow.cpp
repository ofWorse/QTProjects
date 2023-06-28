#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QStandardPaths>
#include <QMessageBox>
#include <QTextStream>

// constr
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile file(path);

    if(!file.open(QIODevice::ReadWrite))
        QMessageBox::information(0, "error", file.errorString());

    QTextStream in(&file); // поток для чтения файла

    while(!in.atEnd()) {
        QListWidgetItem *item = new QListWidgetItem(in.readLine(), ui->listWidget);
        ui->listWidget->addItem(item);
        item->setFlags(item->flags() | Qt::ItemIsEditable);
    }
    file.close();
}

// destr
MainWindow::~MainWindow()
{
    delete ui;

    QFile file(path);

    if(!file.open(QIODevice::ReadWrite))
        QMessageBox::information(0, "error", file.errorString());

    QTextStream out(&file); // поток для чтения файла

    // запихиваем элементы из списка в файл
    for(int i = 0; i < ui->listWidget->count(); i++)
        out << ui->listWidget->item(i)->text() << "\n";

    file.close();
}


void MainWindow::on_btnAdd_clicked()
{
    // создали новый элемент для занесения в виджет
    QListWidgetItem *item = new QListWidgetItem(ui->txtTask->text(), ui->listWidget);
    if(item->text() == "")
        return;
    ui->listWidget->addItem(item);
    item->setFlags(item->flags() | Qt::ItemIsEditable); // дает возможность редактировать введенный в список элемент
    ui->txtTask->clear();
    ui->txtTask->setFocus(); // устанавливает курсор обратно в textTask
}


void MainWindow::on_btnRemove_clicked()
{
    QListWidgetItem *item = ui->listWidget->takeItem(ui->listWidget->currentRow());
    delete item;
}


void MainWindow::on_btnRemoveAll_clicked()
{
    ui->listWidget->clear();
}

