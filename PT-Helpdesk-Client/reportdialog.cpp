#include "reportdialog.h"
#include "ui_reportdialog.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QThreadPool>

reportDialog::reportDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reportDialog)
{
    ui->setupUi(this);

    tcpSocket = new QTcpSocket(this);
}

reportDialog::~reportDialog()
{
    delete ui;
}

void reportDialog::on_pushButton_clicked()
{


    if(ui->srButton->isChecked() || ui->incButton->isChecked() || ui->secIncButton->isChecked())
    {
        QString recipient = ui->sendToText->text();

        if(ui->descText->toPlainText()!="") {

            QString UserInfo = QHostInfo::localHostName();
            QString message;


            if(ui->srButton->isChecked()) {
                message = tr("Service Request");
            } else if(ui->incButton->isChecked()) {
                message = tr("Incident");
            } else if (ui->secIncButton->isChecked()) {
                message = tr("Security Incident");
            }

            message += "\n" + UserInfo + "\n" + ui->descText->toPlainText() + "\n" + systemInfo;

            tcpSocket->connectToHost(recipient,4829);

            if(tcpSocket->waitForConnected()) {
                qDebug() << "Sending message:";
                qDebug() << "Sender: " << UserInfo;
                qDebug() << "message: " << message;
                tcpSocket->write(message.toUtf8());
                tcpSocket->waitForBytesWritten();
                tcpSocket->disconnectFromHost();
                qDebug() << "SUCCESS";
                ui->descText->clear();
                QMessageBox::information(this,tr("Success"),tr("Your case has been sent successfully"));
                reportDialog::close();
            } else {
                QMessageBox::critical(this, tr("Error"), tr("Could not connect to the server."));
            }

        } else {
            QMessageBox::critical(this,tr("Error"), tr("You cannot send case without details."));
        }


    } else {
        QMessageBox::critical(this,tr("Error"), tr("You have to choose case type."));
    }
}




void reportDialog::on_addOptionalReport_clicked()
{
    QString attachment = QFileDialog::getOpenFileName(this, tr("Select report file..."),QDir::homePath(), tr("PC Diagnostic Center files (*.pcdiag)"));
    QFile f(attachment);
    if (!f.open(QFile::ReadOnly | QFile::Text)) throw new QString("");
    QTextStream in(&f);
    systemInfo = in.readAll();
    ui->optionalLabel->setText(tr("added file: ") + f.fileName());
}


void reportDialog::on_findButton_clicked()
{
    findHosts();
}


void reportDialog::findHosts()
{
    QFile file("adminHosts.cfg");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Cannot open adminHosts.cfg");
        return;
    }

    QTextStream in(&file);
    ui->tableWidget->setRowCount(0);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (!line.isEmpty()) {
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);

            QTableWidgetItem *hostItem = new QTableWidgetItem(line);
            ui->tableWidget->setItem(row, 0, hostItem);

            QTableWidgetItem *statusItem = new QTableWidgetItem("Checking...");
            ui->tableWidget->setItem(row, 1, statusItem);

            QCheckBox *checkBox = new QCheckBox();
            ui->tableWidget->setCellWidget(row, 2, checkBox);

            QThread *thread = new QThread;
            PingWorker *worker = new PingWorker(line, statusItem);
            worker->moveToThread(thread);

            connect(thread, &QThread::started, worker, &PingWorker::process);
            connect(worker, &PingWorker::finished, thread, &QThread::quit);
            connect(worker, &PingWorker::finished, worker, &PingWorker::deleteLater);
            connect(thread, &QThread::finished, thread, &QThread::deleteLater);

            thread->start();
        }
    }

}

void reportDialog::on_addHostsButton_clicked()
{
    QList<QString> selectedHosts;

    for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(ui->tableWidget->cellWidget(i, 2));
        if (checkBox && checkBox->isChecked()) {
            QTableWidgetItem *hostItem = ui->tableWidget->item(i, 0);
            if (hostItem) {
                selectedHosts.append(hostItem->text());
            }
        }
    }

    // Debugging output
    qDebug() << "Selected hosts:" << selectedHosts;

    // Pass the selected hosts to the function that will send messages
    sendMessagesToHosts(selectedHosts);
}

PingWorker::PingWorker(const QString &host, QTableWidgetItem *statusItem, QObject *parent) :
    QObject(parent), host(host), statusItem(statusItem)
{
}

void PingWorker::process()
{
    QProcess pingProcess;
    pingProcess.start("ping", QStringList() << "-n" << "1" << host);
    pingProcess.waitForFinished();
    QString output = pingProcess.readAllStandardOutput();

    if (output.contains("TTL")) {
        statusItem->setText("Available");
    } else {
        statusItem->setText("Unavailable");
    }

    emit finished();
}

void reportDialog::sendMessagesToHosts(const QList<QString> &hosts)
{
    for (const QString &host : hosts) {
        QThread *thread = new QThread;
        MessageSender *sender = new MessageSender(host);
        sender->moveToThread(thread);

        connect(thread, &QThread::started, sender, &MessageSender::process);
        connect(sender, &MessageSender::finished, thread, &QThread::quit);
        connect(sender, &MessageSender::finished, sender, &MessageSender::deleteLater);
        connect(thread, &QThread::finished, thread, &QThread::deleteLater);

        thread->start();
    }
}


MessageSender::MessageSender(const QString &host, QObject *parent) :
    QObject(parent), host(host)
{
}

void MessageSender::process()
{
    // Implement the message sending logic here
    // Example:
    // sendMessageToHost(host);

    qDebug() << "Message sent to host:" << host;

    emit finished();
}

//QHostInfo::fromName(line).hostName();
//if (hostname.isEmpty()) {
//    hostname = line; // If DNS resolution fails, use the line as hostname
//}
