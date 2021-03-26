#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

int mFunc (const QString& arg1, const QString& arg2, const QString& arg3);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_2->hide();
    ui->widget->hide();
    ui->widget_3->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_toolButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    ui->lineEdit_3->setText(dir);
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->lineEdit->text().isEmpty() || ui->lineEdit_3->text().isEmpty()) {
        ui->widget_2->setEnabled(false);
        ui->widget_3->show();
    } else {
        ui->widget_2->setEnabled(false);
        ui->widget->show();
    }
}

void MainWindow::on_buttonBox_accepted()
{
    ui->buttonBox->clear();
    QString arg1 = ui->lineEdit_3->text();
    QString arg2 = ui->lineEdit->text();
    QString arg3 = ui->lineEdit_2->text();
    int it = mFunc(arg1, arg2, arg3);
    QString temp = "<html><head/><body><p align=\"center\">Операция выполнена. Обработано ";
    temp.append(QString::number(it));
    temp.append(" объектов</p></body></html>");
    ui->label_4->setText(temp);
    ui->pushButton_2->show();

}

void MainWindow::on_buttonBox_rejected()
{
    ui->widget->hide();
    ui->widget_2->setEnabled(true);
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->widget_3->hide();
    ui->widget_2->setEnabled(true);
    ui->lineEdit->setFocus();
}
