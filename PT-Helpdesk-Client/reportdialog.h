#ifndef REPORTDIALOG_H
#define REPORTDIALOG_H

#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QMessageBox>
#include <QHostInfo>
#include <QHostAddress>
#include <QSysInfo>
#include <QTableWidget>
#include <QCheckBox>
#include <QThread>
#include <QProcess>

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

    void on_addOptionalReport_clicked();

    void on_findButton_clicked();

    void on_addHostsButton_clicked();

private:
    QTcpSocket* tcpSocket;
    Ui::reportDialog *ui;
    QString systemInfo;

    void sendMessagesToHosts(const QList<QString> &hosts);
    void findHosts();
    void updateHostStatus(const QString &host, QTableWidgetItem *statusItem);
};


class MessageSender : public QObject
{
    Q_OBJECT

public:
    MessageSender(const QString &host, QObject *parent = nullptr);

public slots:
    void process();

signals:
    void finished();

private:
    QString host;
};




class PingWorker : public QObject
{
    Q_OBJECT

public:
    PingWorker(const QString &host, QTableWidgetItem *statusItem, QObject *parent = nullptr);

public slots:
    void process();

signals:
    void finished();

private:
    QString host;
    QTableWidgetItem *statusItem;
};

#endif // REPORTDIALOG_H


