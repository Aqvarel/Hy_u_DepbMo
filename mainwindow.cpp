#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "entrypoint.h"

#include "QMessageBox"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800, 600);


    connect(ui->convert, &QPushButton::clicked, this, &MainWindow::onConvertClicked);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onConvertClicked(){
    getData();
    doOperation(Valid,&context);
    if(context.flag != good){
        errors();
    }else{
        doOperation(Convert,&context);
        showAnswer();
    }
}

void MainWindow::getData(){
    std::string str = ui -> fromBase ->text().toStdString();
    context.input = str.c_str();
    context.fromBase = ui ->comboBox ->currentText().toInt();
    context.toBase = ui ->comboBox_2 ->currentText().toInt();
}

void MainWindow::showAnswer() {
    ui->toBase->setText(context.answer);
}

void MainWindow::errors(){
    switch(context.flag){
    case error_first:
        QMessageBox::critical(this, "Error", "Incorrect input");
        break;
    case error_second:
        QMessageBox::critical(this, "Error", "number > 4bytes");
        break;
    }
}


