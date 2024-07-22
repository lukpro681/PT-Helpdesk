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

    loadCases();

}

MainWindow::~MainWindow()
{
    saveCases();
    delete ui;
}

QList<QString> MainWindow::getCases(){
    return messages;
}

void MainWindow::addCaseToTable(const QString &sender, const QString &type, const QString &desc)
{
    QDateTime date = QDateTime::currentDateTime();
    QString formattedDate = date.toString("dd.MM.yyyy hh:mm:ss");
    int row = ui->activeCaseWidget->rowCount();
    ui->activeCaseWidget->insertRow(row);
    ui->activeCaseWidget->setItem(row, 0, new QTableWidgetItem(formattedDate));
    ui->activeCaseWidget->setItem(row, 1, new QTableWidgetItem(type));
    ui->activeCaseWidget->setItem(row, 2, new QTableWidgetItem(sender));
    ui->activeCaseWidget->setItem(row, 3, new QTableWidgetItem(tr("New")));
    ui->activeCaseWidget->setItem(row, 4, new QTableWidgetItem(desc));

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
        saveCases();
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

    QString type = table->item(row, 1)->text();
    QString from = table->item(row, 2)->text();
    QString status = table->item(row, 3)->text();
    QString description = table->item(row, 4)->text();

    DetailsDialog *dialog = new DetailsDialog(row, from, type, status, description, this);
    connect(dialog, &DetailsDialog::closeCaseRequest, this, &MainWindow::onCloseCaseRequest);

    connect(dialog, &DetailsDialog::assignCase, this, &MainWindow::onAssignCase);
    dialog->exec();
}

void MainWindow::onCloseCaseRequest(int row, const QString &from, const QString &type, const QString &description)
{
    QDateTime closedDate = QDateTime::currentDateTime();
    QString formattedClosedDate = closedDate.toString("dd.MM.yyyy hh:mm:ss");
    QString openedDate = ui->activeCaseWidget->takeItem(row,0)->text();
    qDebug() << "Closing case from row:" << row;
    int closedRow = ui->completeCaseWidget->rowCount();
    ui->completeCaseWidget->insertRow(closedRow);
    ui->completeCaseWidget->setItem(closedRow, 0, new QTableWidgetItem(openedDate));
    ui->completeCaseWidget->setItem(closedRow, 1, new QTableWidgetItem(formattedClosedDate));
    ui->completeCaseWidget->setItem(closedRow, 2, new QTableWidgetItem(type));
    ui->completeCaseWidget->setItem(closedRow, 3, new QTableWidgetItem(from));
    ui->completeCaseWidget->setItem(closedRow, 4, new QTableWidgetItem(tr("Closed")));
    ui->completeCaseWidget->setItem(closedRow, 5, new QTableWidgetItem(description));

    ui->activeCaseWidget->removeRow(row);
}

void MainWindow::onAssignCase(int row)
{
    qDebug() << "Assigning case... " << row;
    ui->activeCaseWidget->setItem(row,3, new QTableWidgetItem(tr("Open")));
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    qApp->aboutQt();
}


void MainWindow::on_actionAbout_triggered()
{
    About *dialog = new About(this);
    dialog->setWindowTitle(tr("About App"));
    dialog->exec();
}



void MainWindow::on_completeCaseWidget_cellClicked(int row, int column)
{
    QTableWidget *table = qobject_cast<QTableWidget*>(sender());
    if (!table) return;

    QString type = table->item(row, 2)->text();
    QString from = table->item(row, 3)->text();
    QString status = table->item(row, 4)->text();
    QString description = table->item(row, 5)->text();

    DetailsDialog *dialog = new DetailsDialog(row, from, type, status, description, this);

    dialog->exec();
}

void MainWindow::saveCases()
{
    QJsonArray activeCases;
    QJsonArray completeCases;

    for (int row = 0; row < ui->activeCaseWidget->rowCount(); ++row) {
        QJsonObject caseObject;
        caseObject["openedDate"] = ui->activeCaseWidget->item(row, 0)->text();
        caseObject["type"] = ui->activeCaseWidget->item(row, 1)->text();
        caseObject["from"] = ui->activeCaseWidget->item(row, 2)->text();
        caseObject["status"] = ui->activeCaseWidget->item(row, 3)->text();
        caseObject["description"] = ui->activeCaseWidget->item(row, 4)->text();
        activeCases.append(caseObject);
    }

    for (int row = 0; row < ui->completeCaseWidget->rowCount(); ++row) {
        QJsonObject caseObject;
        caseObject["openedDate"] = ui->completeCaseWidget->item(row, 0)->text();
        caseObject["closedDate"] = ui->completeCaseWidget->item(row, 1)->text();
        caseObject["type"] = ui->completeCaseWidget->item(row, 2)->text();
        caseObject["from"] = ui->completeCaseWidget->item(row, 3)->text();
        caseObject["status"] = ui->completeCaseWidget->item(row, 4)->text();
        caseObject["description"] = ui->completeCaseWidget->item(row, 5)->text();
        completeCases.append(caseObject);
    }

    QJsonObject casesObject;
    casesObject["activeCases"] = activeCases;
    casesObject["completeCases"] = completeCases;

    QFile saveFile(fileName);
    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
        return;
    }

    QJsonDocument saveDoc(casesObject);
    saveFile.write(saveDoc.toJson());
}
void MainWindow::loadCases()
{
    QFile loadFile(fileName);

    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open load file.");
        return;
    }

    QByteArray saveData = loadFile.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));

    QJsonObject json = loadDoc.object();
    QJsonArray activeCases = json["activeCases"].toArray();
    QJsonArray completeCases = json["completeCases"].toArray();

    for (const QJsonValue &value : activeCases) {
        QJsonObject caseObject = value.toObject();
        int row = ui->activeCaseWidget->rowCount();
        ui->activeCaseWidget->insertRow(row);
        ui->activeCaseWidget->setItem(row, 0, new QTableWidgetItem(caseObject["openedDate"].toString()));
        ui->activeCaseWidget->setItem(row, 1, new QTableWidgetItem(caseObject["type"].toString()));
        ui->activeCaseWidget->setItem(row, 2, new QTableWidgetItem(caseObject["from"].toString()));
        ui->activeCaseWidget->setItem(row, 3, new QTableWidgetItem(caseObject["status"].toString()));
        ui->activeCaseWidget->setItem(row, 4, new QTableWidgetItem(caseObject["description"].toString()));
    }

    for (const QJsonValue &value : completeCases) {
        QJsonObject caseObject = value.toObject();
        int row = ui->completeCaseWidget->rowCount();
        ui->completeCaseWidget->insertRow(row);
        ui->completeCaseWidget->setItem(row, 0, new QTableWidgetItem(caseObject["openedDate"].toString()));
        ui->completeCaseWidget->setItem(row, 1, new QTableWidgetItem(caseObject["closedDate"].toString()));
        ui->completeCaseWidget->setItem(row, 2, new QTableWidgetItem(caseObject["type"].toString()));
        ui->completeCaseWidget->setItem(row, 3, new QTableWidgetItem(caseObject["from"].toString()));
        ui->completeCaseWidget->setItem(row, 4, new QTableWidgetItem(caseObject["status"].toString()));
        ui->completeCaseWidget->setItem(row, 5, new QTableWidgetItem(caseObject["description"].toString()));
    }
}

