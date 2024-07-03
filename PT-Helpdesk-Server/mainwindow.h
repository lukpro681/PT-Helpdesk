#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include <cstdlib>
#include <QMessageBox>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QNetworkInterface>
#include <QSystemTrayIcon>
#include <QAction>
#include <QActionEvent>
#include <QMenu>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <QCloseEvent>
#include <QUdpSocket>
#include <QHostInfo>
#include <QSysInfo>
#include "detailsdialog.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void showNormal()
    {
        this->showNormal();
    }

    QList<QString>getCases();
    void addCaseToTable(const QString &sender, const QString &type, const QString &desc);

protected:
    void closeEvent(QCloseEvent *event) override;
    void changeEvent(QEvent *event) override;


private slots:

    void newConnection();
    void readData();
    void showData(const QString& sender, const QString& type, const QString& desc);
    void visibility();
    void closeTray();
    void captureData();
    void showMessage(const QString& sender, const QString& type, const QString& desc);

    void on_activeCaseWidget_cellClicked(int row, int column);

    void onCloseCaseRequest(int row, const QString &from, const QString &type, const QString &description);


signals:
    void messageReceived(const QString& sender, const QString& type, const QString& desc);


private:
    QCloseEvent *closeTrayIcon;
    bool isMinimized;

    Ui::MainWindow *ui;
    QTcpServer *tcpServer;
    QUdpSocket *udpSocket;
    QList<QTcpSocket*> clients;
    QSystemTrayIcon *trayIcon;
    QMenu *menuTray;
    QList<QString> messages;
};
#endif // MAINWINDOW_H
