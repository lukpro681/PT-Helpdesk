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





void reportView::on_saveInfoButton_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save as..."), QDir::homePath(), tr("PC Diagnostic Center files (*.pcdiag)"));

    QFile file(filePath);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Cannot write file";
    } else {
        QTextStream out(&file);
        out << info;

        file.close();

        qDebug() << filePath << " wrote successfuly";
    }
}



// {
//     QString filePath = QFileDialog::getSaveFileName(this, tr("Save as..."), QDir::homePath(), tr("PC Diagnostic Center files (*.pcdiag)"));

//     if(!filePath.isEmpty()) {
//         QProcess process;
//         QStringList arguments;
//         arguments << "echo" << info << ">>" << filePath;

//         process.start("cmd", arguments);
//         if (!process.waitForStarted())
//             throw QString(tr("Error: Failed to Initiate writing process."));

//         if (!process.waitForFinished(-1))
//             throw QString(tr("Error: Write process timed out."));

//         if (process.exitCode() != 0)
//             throw QString(tr("Error: Failed to Write Data."));
//     } else {
//         throw QString(tr("Error: Please select input file!"));
//     }
// }

