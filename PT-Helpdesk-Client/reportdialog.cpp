#include "reportdialog.h"
#include "ui_reportdialog.h"

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

            message += "\n" + UserInfo + "\n" + ui->descText->toPlainText() + "\n";

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

