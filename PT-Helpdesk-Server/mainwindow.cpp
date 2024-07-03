#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->activeCaseWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->completeCaseWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(this, SIGNAL(messageReceived(QString,QString,QString)),this,SLOT(showMessage(QString,QString,QString)));
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(4830);
    connect(udpSocket,SIGNAL(readyRead()), this, SLOT(captureData()));

    tcpServer = new QTcpServer(this);
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(newConnection()));
    if(!tcpServer->listen(QHostAddress::Any, 4829))
    {
        QMessageBox::critical(this, tr("Error"),tr("Cannot start the listener: ") + tcpServer->errorString());
        return;
    }

    menuTray = new QMenu(this);
    QAction *visibilityAction = new QAction(tr("show/hide"),this);
    QAction *quitAction = new QAction(tr("Close"),this);
    connect(visibilityAction, SIGNAL(triggered()),this,SLOT(visibility()));
    connect(quitAction, SIGNAL(triggered()),this,SLOT(closeTray()));

    menuTray->addAction(visibilityAction);
    menuTray->addAction(quitAction);

    trayIcon = new QSystemTrayIcon(QIcon("PTIcon.ico"),this);
    trayIcon->setContextMenu(menuTray);
    trayIcon->show();


    connect(qApp, SIGNAL(aboutToQuit()),this,SLOT(onAboutToQuit()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

QList<QString> MainWindow::getCases(){
    return messages;
}

void MainWindow::addCaseToTable(const QString &sender, const QString &type, const QString &desc)
{

    int row = ui->activeCaseWidget->rowCount();
    ui->activeCaseWidget->insertRow(row);
    ui->activeCaseWidget->setItem(row, 0, new QTableWidgetItem(type));
    ui->activeCaseWidget->setItem(row, 1, new QTableWidgetItem(sender));
    ui->activeCaseWidget->setItem(row, 2, new QTableWidgetItem(tr("Open")));
    ui->activeCaseWidget->setItem(row, 3, new QTableWidgetItem(desc));

}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(trayIcon->isVisible())
    {
        hide();
        event->ignore();
    }
    else
    {
        event->accept();
    }
}

void MainWindow::changeEvent(QEvent *event)
{
    if(event->type() == QEvent::WindowStateChange) {
        QWindowStateChangeEvent *stateChangeEvent = static_cast<QWindowStateChangeEvent*>(event);
        if(stateChangeEvent->oldState() & Qt::WindowMinimized) {
            isMinimized = false;
        } else if (stateChangeEvent->oldState() & Qt::WindowNoState && windowState() & Qt::WindowMinimized) {
            isMinimized = true;
        }
    }
    QMainWindow::changeEvent(event);
}

void MainWindow::newConnection()
{
    qDebug() << "new connection";
    QTcpSocket *client = tcpServer->nextPendingConnection();
    clients.append(client);
    connect(client, SIGNAL(readyRead()), this,SLOT(readData()));
}

void MainWindow::readData()
{
    qDebug() << "Reading data";
    QTcpSocket *client = qobject_cast<QTcpSocket*>(sender());
    if(client)
    {
        qDebug() << "Client found";
         QString data = QString::fromUtf8(client->readAll());
        qDebug() << "Data received";
         QStringList caseMessage = data.split("\n");
        qDebug() << "Reading message parts";
         qDebug() << caseMessage;
        if (caseMessage.size() >= 3)
         {
             qDebug() << "case message size >=3";
            QString senderName = caseMessage[1];
             QString caseType = caseMessage[0];
            QString caseDesc;
             for(int i = 2; i < caseMessage.size(); i++) {
                caseDesc += caseMessage[i] + "\n";
            }
             qDebug() << "Case received Emitting signal 'messageReceived'...";
            emit messageReceived(senderName, caseType, caseDesc);

             qDebug() << "case received: READ_DATA";
             qDebug() << "From: " << senderName;
             qDebug() << "Type: " << caseType;
             qDebug() << "Description: " << caseDesc;

         }
    }

}

void MainWindow::showData(const QString &sender, const QString &type, const QString &desc)
{

}

void MainWindow::visibility()
{
    if(isVisible())
    {
        isMinimized = false;
        hide();
        qApp->setQuitLockEnabled(true);
    }
    else {
        isMinimized = true;
        show();
    }
}

void MainWindow::closeTray()
{
    qApp->setQuitLockEnabled(false);
    qApp->quit();
}

void MainWindow::captureData()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        QHostAddress senderAddress;
        quint16 senderPort;

        datagram.resize(udpSocket->pendingDatagramSize());

        udpSocket->readDatagram(datagram.data(), datagram.size(), &senderAddress, &senderPort);
    }
}

void MainWindow::showMessage(const QString &sender, const QString &type, const QString &desc)
{
    qDebug() << "Handling received case... HANDLE_MESSAGE";
    qDebug() << "Received Case:";
    qDebug() << "From: " << sender;
    qDebug() << "Type: " << type;
    qDebug() << "Description: " << desc;

    addCaseToTable(sender, type, desc);

    QString Case = "From: " + sender + "\n"
                                            "Type: " + type + "\n"
                                  "Description: " + desc;


    QMessageBox msgBox;

    msgBox.setIcon(QMessageBox::Information);
    msgBox.setWindowIcon(QIcon("PTIcon.ico"));
    msgBox.setWindowTitle(tr("New Case Arrived!!!"));
    msgBox.setText(Case);
    msgBox.setWindowFlags(msgBox.windowFlags() | Qt::WindowStaysOnTopHint); // pojawianie się nad wszystkimi oknami
    msgBox.exec();
}




void MainWindow::on_activeCaseWidget_cellClicked(int row, int column)
{
    QTableWidget *table = qobject_cast<QTableWidget*>(sender());
    if (!table) return;

    QString type = table->item(row, 0)->text();
    QString from = table->item(row, 1)->text();
    QString status = table->item(row, 2)->text();
    QString description = table->item(row, 3)->text();

    DetailsDialog *dialog = new DetailsDialog(row, from, type, status, description, this);
    connect(dialog, &DetailsDialog::closeCaseRequest, this, &MainWindow::onCloseCaseRequest);
    dialog->exec();
}

void MainWindow::onCloseCaseRequest(int row, const QString &from, const QString &type, const QString &description)
{
    qDebug() << "Closing case from row:" << row;
    int closedRow = ui->completeCaseWidget->rowCount();
    ui->completeCaseWidget->insertRow(closedRow);
    ui->completeCaseWidget->setItem(closedRow, 0, new QTableWidgetItem(type));
    ui->completeCaseWidget->setItem(closedRow, 1, new QTableWidgetItem(from));
    ui->completeCaseWidget->setItem(closedRow, 2, new QTableWidgetItem(tr("Closed")));
    ui->completeCaseWidget->setItem(closedRow, 3, new QTableWidgetItem(description));

    ui->activeCaseWidget->removeRow(row);
}
