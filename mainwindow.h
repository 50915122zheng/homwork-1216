#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QClipboard>
#include <QApplication>
#include <QTextCursor>
#include <QTextDocumentFragment>
#include <QTextBlock>
#include <QTextCharFormat>



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void saveFile();
    void close();
    //copy
    void copy();
    //paste
    void paste();
    //cut
    void cut();



private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
