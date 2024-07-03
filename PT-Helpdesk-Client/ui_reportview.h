/********************************************************************************
** Form generated from reading UI file 'reportview.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTVIEW_H
#define UI_REPORTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_reportView
{
public:
    QGridLayout *gridLayout;
    QLabel *infoLabel;
    QPushButton *saveInfoButton;
    QLabel *logoLabel;
    QDialogButtonBox *buttonBox;
    QTextBrowser *textBrowser;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *reportView)
    {
        if (reportView->objectName().isEmpty())
            reportView->setObjectName("reportView");
        reportView->resize(649, 634);
        reportView->setMinimumSize(QSize(649, 634));
        reportView->setMaximumSize(QSize(649, 634));
        gridLayout = new QGridLayout(reportView);
        gridLayout->setObjectName("gridLayout");
        infoLabel = new QLabel(reportView);
        infoLabel->setObjectName("infoLabel");
        QFont font;
        font.setFamilies({QString::fromUtf8("HoloLens MDL2 Assets")});
        font.setPointSize(28);
        infoLabel->setFont(font);

        gridLayout->addWidget(infoLabel, 1, 2, 1, 1);

        saveInfoButton = new QPushButton(reportView);
        saveInfoButton->setObjectName("saveInfoButton");
        saveInfoButton->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(saveInfoButton, 3, 0, 1, 1);

        logoLabel = new QLabel(reportView);
        logoLabel->setObjectName("logoLabel");
        logoLabel->setMinimumSize(QSize(300, 0));
        logoLabel->setMaximumSize(QSize(300, 75));
        logoLabel->setPixmap(QPixmap(QString::fromUtf8("helpdesk-baner.png")));
        logoLabel->setScaledContents(true);

        gridLayout->addWidget(logoLabel, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(reportView);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);

        gridLayout->addWidget(buttonBox, 3, 2, 1, 1);

        textBrowser = new QTextBrowser(reportView);
        textBrowser->setObjectName("textBrowser");

        gridLayout->addWidget(textBrowser, 2, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);


        retranslateUi(reportView);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, reportView, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, reportView, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(reportView);
    } // setupUi

    void retranslateUi(QDialog *reportView)
    {
        reportView->setWindowTitle(QCoreApplication::translate("reportView", "Dialog", nullptr));
        infoLabel->setText(QCoreApplication::translate("reportView", "System information", nullptr));
        saveInfoButton->setText(QCoreApplication::translate("reportView", "Save Info", nullptr));
        logoLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class reportView: public Ui_reportView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTVIEW_H
