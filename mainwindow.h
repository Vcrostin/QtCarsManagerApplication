#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <algorithm>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_find_clicked();

    void on_pushButton_write_clicked();

    void on_Button_Change_File_clicked();

    void on_pushButton_Filename_Choose_clicked();

private:

    void clicked_func();
    void on_pushButton_find_clicked_func();
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
