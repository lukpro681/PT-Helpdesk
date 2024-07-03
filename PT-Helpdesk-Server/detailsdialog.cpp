#include "detailsdialog.h"
#include "ui_detailsdialog.h"

DetailsDialog::DetailsDialog(int row, const QString &from, const QString &type, const QString &status, const QString &description, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DetailsDialog)
    , row(row)
    , from(from)
    , type(type)
    , status(status)
    , description(description)
{
    ui->setupUi(this);
    ui->fromResponse->setText(from);
    ui->typeResponse->setText(type);
    ui->statusResponse->setText(status);
    ui->descLabel->setText(description);

   // connect(ui->closeCaseButton, &QPushButton::clicked, this, &DetailsDialog::on_closeCaseButton_clicked);
}

DetailsDialog::~DetailsDialog()
{
    delete ui;
}

void DetailsDialog::on_closeCaseButton_clicked()
{
    emit closeCaseRequest(row, from, type, description);
    accept();
}
