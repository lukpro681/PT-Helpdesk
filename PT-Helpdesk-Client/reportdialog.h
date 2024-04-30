#ifndef REPORTDIALOG_H
#define REPORTDIALOG_H

#include <QDialog>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QMessageBox>
#include <QHostInfo>
#include <QHostAddress>
#include <QSysInfo>

namespace Ui {
class reportDialog;
}

class reportDialog : public QDialog
{
    Q_OBJECT

public:
    explicit reportDialog(QWidget *parent = nullptr);
    void send();
    void verify(QString,QString,QString);
    ~reportDialog();

private slots:

    void on_pushButton_clicked();

private:
    QTcpSocket* tcpSocket;
    Ui::reportDialog *ui;
};

#endif // REPORTDIALOG_H
