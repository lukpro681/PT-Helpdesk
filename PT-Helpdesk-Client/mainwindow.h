#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include <QVersionNumber>
#include <QDir>
#include <QStandardPaths>
#include "reportdialog.h"
#include "reportview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_reportButton_clicked();

    void on_actionAbout_triggered();

    void on_actionShow_basic_report_triggered();

    void on_actionShow_advanced_report_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
