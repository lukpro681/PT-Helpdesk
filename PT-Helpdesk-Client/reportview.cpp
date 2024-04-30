#include "reportview.h"
#include "qhostaddress.h"
#include "ui_reportview.h"

reportView::reportView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reportView)
{
    ui->setupUi(this);
    getInformation();
}

reportView::~reportView()
{
    delete ui;

}

void reportView::getInformation()
{
    QString info;
    QString OS = QSysInfo::productType();
    QString kernelType = QSysInfo::kernelType();
    QString NT_ver = QSysInfo::kernelVersion();
    QString build = QSysInfo::buildAbi();
    QString CPU_Architecture = QSysInfo::buildCpuArchitecture();
    QString hostName = QSysInfo::machineHostName();
    QString machineId = QSysInfo::machineUniqueId();
    QString currentCPU_Architecture = QSysInfo::currentCpuArchitecture();
    QString bootId = QSysInfo::bootUniqueId();

    info +=
        "------------------------- OS Information -------------------------\n\n"
     + tr("Product type:\t\t") + OS + "\n\n"
     + tr("Kernel Type:\t\t") +  kernelType + "\n\n"
            + tr("NT Version:\t\t") +  NT_ver + "\n\n"
     + tr("Build:\t\t") +  build + "\n\n"
     + tr("Build CPU Architekture:\t") +  CPU_Architecture + "\n\n"
     + tr("Current CPU Architekture:\t") +  currentCPU_Architecture + "\n\n"
     + tr("Host Name:\t\t") +  hostName + "\n\n"
            + tr("Machine ID:\t\t") +  machineId;

    ui->textBrowser->setText(info);
}




void reportView::on_buttonBox_accepted()
{
    if(ui->buttonBox->Save)
    {
        qDebug("Saving...");
    }
}


void reportView::on_pushButton_clicked()
{

}

