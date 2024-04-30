#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    if (QSysInfo::kernelVersion() < "10.0") //sprawdzenie wersji komputera bazując na wersji jądra
    {

        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle(tr("Warning"));
        msgBox.setText(tr("Program detected an older version of Windows. PT-Helpdesk may be unstable."));
        msgBox.setInformativeText(tr("Would you like to still open it?"));
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        int choice = msgBox.exec();
        if (choice == QMessageBox::Yes)
        {
            ui->setupUi(this);

        }
        else
        {
            delete qApp;
        }
    }
    else ui->setupUi(this);
   // ui->tempLlabel->clear();
   // ui->tempLlabel->setText(qApp->applicationName() + " " + qApp->applicationVersion());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_reportButton_clicked()
{
    reportDialog *r = new reportDialog();
    r->setWindowTitle(tr("Report problem"));
    r->setWindowIcon(QIcon());
    r->show();
}


void MainWindow::on_actionAbout_triggered()
{

}


void MainWindow::on_actionShow_basic_report_triggered()
{
    reportView *r = new reportView();
    r->setWindowIcon(QIcon());
    r->setWindowTitle(tr("Report view"));
    r->show();
}


void MainWindow::on_actionShow_advanced_report_triggered()
{
    QProcess process;
    process.start("msinfo32.exe");
    process.waitForFinished();
}

