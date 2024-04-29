#include "reportview.h"
#include "ui_reportview.h"

reportView::reportView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reportView)
{
    ui->setupUi(this);
}

reportView::~reportView()
{
    delete ui;
}




void reportView::on_buttonBox_accepted()
{
    if(ui->buttonBox->Save)
    {
        qDebug("Saving...");
    }
}

