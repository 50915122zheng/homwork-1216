#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
    connect(ui->action_1,SIGNAL(triggered()),this,SLOT(saveFile()));
    //close the program when the close button is clicked
    connect(ui->actionClose,SIGNAL(triggered()),this,SLOT(close()));
    //copy
    connect(ui->actionCopy,SIGNAL(triggered()),this,SLOT(copy()));
    //paste
    connect(ui->actionPaste,SIGNAL(triggered()),this,SLOT(paste()));
    //cut
    connect(ui->actionCut,SIGNAL(triggered()),this,SLOT(cut()));



}

MainWindow::~MainWindow()
{
    delete ui;

}
void MainWindow::saveFile(){
    QString file = QFileDialog::getSaveFileName(this,"Save File");
    QFile sFile(file);
    if(sFile.open(QFile::WriteOnly | QFile::Text)){
        QTextStream out(&sFile);
        out << ui->textEdit->toPlainText();
        sFile.flush();
        sFile.close();
    }
}
void MainWindow::close(){
    QApplication::quit();
}

void MainWindow::copy(){
    ui->textEdit->copy();
}

void MainWindow::paste(){
    ui->textEdit->paste();
}

void MainWindow::cut(){
    ui->textEdit->cut();
}
