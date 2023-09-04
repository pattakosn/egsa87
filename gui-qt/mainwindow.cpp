#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include "egsa87.h"

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


void MainWindow::on_to_decimal_clicked()
{
    QString input = ui->input_text->toPlainText();

    QStringList list = input.split(" ");
    std::vector<double> number_list;
    foreach( QString str, list){
        number_list.push_back(str.toDouble());
    }

    QString output;
    for ( size_t i = 0; i < list.size(); i+=2) {
        coords result = wgs84_to_egsa87(coords{number_list[i], number_list[i+1]});
        output += QString::fromStdString(std::to_string(result.phi) + " " + std::to_string(result.lambda) + ",");
    }
    ui->output_text->setPlainText(output);
}


void MainWindow::on_to_EGSA87_clicked()
{
    QString input = ui->input_text->toPlainText();

    QStringList list = input.split(" ");
    std::vector<double> number_list;
    foreach( QString str, list){
        number_list.push_back(str.toDouble());
    }

    QString output;
    for ( size_t i = 0; i < list.size(); i+=2) {
        coords result = egsa87_to_wgs84(coords{number_list[i], number_list[i+1]});
        output += QString::fromStdString(std::to_string(result.phi) + " " + std::to_string(result.lambda) + ",");
    }
    ui->output_text->setPlainText(output);
}

