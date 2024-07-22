#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::About)
{
    ui->setupUi(this);
    ui->titleLabel->setText(appName);
    ui->versionNumber->setText(version);
    ui->authorsLabel->setText(authors);
    ui->licenseInfo->setText(license);
}

About::~About()
{
    delete ui;
}
