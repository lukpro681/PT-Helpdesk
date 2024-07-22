/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QGridLayout *gridLayout;
    QLabel *titleLabel;
    QLabel *infoLabel2;
    QLabel *versionNumber;
    QLabel *infoLabel;
    QLabel *authorsLabel;
    QDialogButtonBox *buttonBox;
    QLabel *logo;
    QLabel *licenseInfo;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName("About");
        About->resize(393, 568);
        About->setMinimumSize(QSize(393, 568));
        About->setMaximumSize(QSize(393, 568));
        gridLayout = new QGridLayout(About);
        gridLayout->setObjectName("gridLayout");
        titleLabel = new QLabel(About);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(titleLabel, 1, 0, 1, 2);

        infoLabel2 = new QLabel(About);
        infoLabel2->setObjectName("infoLabel2");
        infoLabel2->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(infoLabel2, 2, 0, 1, 1);

        versionNumber = new QLabel(About);
        versionNumber->setObjectName("versionNumber");

        gridLayout->addWidget(versionNumber, 2, 1, 1, 1);

        infoLabel = new QLabel(About);
        infoLabel->setObjectName("infoLabel");
        infoLabel->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(infoLabel, 3, 0, 1, 1);

        authorsLabel = new QLabel(About);
        authorsLabel->setObjectName("authorsLabel");

        gridLayout->addWidget(authorsLabel, 3, 1, 1, 1);

        buttonBox = new QDialogButtonBox(About);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 5, 0, 1, 2);

        logo = new QLabel(About);
        logo->setObjectName("logo");
        logo->setMaximumSize(QSize(375, 100));
        logo->setPixmap(QPixmap(QString::fromUtf8("helpdesk-baner.png")));
        logo->setScaledContents(true);

        gridLayout->addWidget(logo, 0, 0, 1, 2);

        licenseInfo = new QLabel(About);
        licenseInfo->setObjectName("licenseInfo");
        licenseInfo->setWordWrap(true);

        gridLayout->addWidget(licenseInfo, 4, 0, 1, 2);


        retranslateUi(About);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, About, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, About, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QCoreApplication::translate("About", "Dialog", nullptr));
        titleLabel->setText(QCoreApplication::translate("About", "Title", nullptr));
        infoLabel2->setText(QCoreApplication::translate("About", "Version", nullptr));
        versionNumber->setText(QCoreApplication::translate("About", "versionNumber", nullptr));
        infoLabel->setText(QCoreApplication::translate("About", "Authors", nullptr));
        authorsLabel->setText(QCoreApplication::translate("About", "authorslabel", nullptr));
        logo->setText(QString());
        licenseInfo->setText(QCoreApplication::translate("About", "License", nullptr));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
