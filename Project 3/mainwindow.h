#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "model.h"

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
    void on_createButton_clicked();

    void on_pushButton_4_clicked();

    void on_removeButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
