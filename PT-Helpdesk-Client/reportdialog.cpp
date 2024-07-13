#include "reportdialog.h"
#include "ui_reportdialog.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QThreadPool>
#include <QtConcurrent/QtConcurrent>

reportDialog::reportDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reportDialog)
{
    ui->setupUi(this);
    findHosts();
    tcpSocket = new QTcpSocket(this);
}

reportDialog::~reportDialog()
{
    delete ui;
}

void reportDialog::on_pushButton_clicked()
{
    int successSendCounter = 0;
    int failedSendCounter = 0;
    if (ui->srButton->isChecked() || ui->incButton->isChecked() || ui->secIncButton->isChecked())
    {

        // Check which row is selected
        int rowCount = ui->tableWidget->rowCount();
        QString recipient;

        for (int row = 0; row < rowCount; ++row)
        {
            QCheckBox *checkBox = qobject_cast<QCheckBox*>(ui->tableWidget->cellWidget(row, 2));
            if (checkBox && checkBox->isChecked())
            {
                QTableWidgetItem *hostItem = ui->tableWidget->item(row, 0);
                QTableWidgetItem *statusItem = ui->tableWidget->item(row,1);
                if (hostItem && statusItem->text()== tr("Available"))
                {
                    recipient = hostItem->text();
                    if (!recipient.isEmpty())
                    {
                        QString UserInfo = QHostInfo::localHostName();
                        QString message;

                        // Determine message type
                        if (ui->srButton->isChecked())
                            message = tr("Service Request");
                        else if (ui->incButton->isChecked())
                            message = tr("Incident");
                        else if (ui->secIncButton->isChecked())
                            message = tr("Security Incident");

                        message += "\n" + UserInfo + "\n" + ui->descText->toPlainText() + "\n" + systemInfo;

                        // Use QtConcurrent to send message in a separate thread
                        QtConcurrent::run([=]() {
                            QTcpSocket socket;
                            socket.connectToHost(recipient, 4829);

                            if (socket.waitForConnected())
                            {
                                qDebug() << "Sending message:";
                                qDebug() << "Sender: " << UserInfo;
                                qDebug() << "message: " << message;
                                socket.write(message.toUtf8());
                                socket.waitForBytesWritten();
                                socket.disconnectFromHost();
                                qDebug() << "SUCCESS";

                                //emit messageSent(); // Signal success if needed
                            }
                            else
                            {
                                qDebug() << "Failed to connect to host.";
                                // QMessageBox::critical(this, tr("Error"), tr("Failed connect to host."));

                            }
                        });

                        ui->descText->clear();
                        successSendCounter++;
                        //QMessageBox::information(this, tr("Success"), tr("Your case has been sent successfully"));
                        this->close();

                    }
                    else
                    {
                        QMessageBox::critical(this, tr("Error"), tr("Please select a recipient."));
                    }
                }
                else {
                    //QMessageBox::critical(this,tr("Error"),tr("Cannot send to: ") + hostItem->text());
                    failedSendCounter++;

                }

            }

        }
        if(successSendCounter > 0)
        QMessageBox::information(this,tr("Sending result"),tr("Sent case to all selected administrators"));
        else
        QMessageBox::critical(this, tr("Error"), tr("Please select a recipient."));
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), tr("You have to choose case type."));
    }
}




void reportDialog::on_addOptionalReport_clicked()
{
    QString attachment = QFileDialog::getOpenFileName(this, tr("Select report file..."),QDir::homePath(), tr("PC Diagnostic Center files (*.pcdiag)"));
    QFile f(attachment);
    if (!f.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::information(this,tr("Additional report"), tr("Additional report not attached."));
        return;
    }
    else{
    QTextStream in(&f);
    systemInfo = in.readAll();
    ui->optionalLabel->setText(tr("added file: ") + f.fileName());
    }
}


void reportDialog::on_findButton_clicked()
{
    findHosts();
}


void reportDialog::findHosts()
{
    QFile file("adminHosts.cfg");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    QMessageBox::critical(this, tr("Error"), tr("Cannot open adminHosts.cfg"));
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

            QTableWidgetItem *statusItem = new QTableWidgetItem(tr("Checking..."));
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

            connect(worker, &PingWorker::finished, this, [=]() {
                if (statusItem->text() == tr("Unavailable")) {
                    checkBox->setEnabled(false); // Disable checkbox if host is unavailable
                }
            });

            thread->start();
        }
    }

}


PingWorker::PingWorker(const QString &host, QTableWidgetItem *statusItem, QObject *parent) :
    QObject(parent), host(host), statusItem(statusItem)
{
}

void PingWorker::process()
{
    QProcess pingProcess;
    pingProcess.start("paping", QStringList() << host << "-p" << "4829" << "-c" << "1");
    qDebug() << "ping", QStringList() << "-n" << "1" << host;
    pingProcess.waitForFinished();
    QString output = pingProcess.readAllStandardOutput();

    if (output.contains("protocol")) {
        statusItem->setText(tr("Available"));
    } else {
        statusItem->setText(tr("Unavailable"));
    }

    emit finished();
}
