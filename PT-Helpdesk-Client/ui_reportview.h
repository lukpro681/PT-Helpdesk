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
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_reportView
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *logoLabel;
    QTextBrowser *textBrowser;
    QLabel *infoLabel;

    void setupUi(QDialog *reportView)
    {
        if (reportView->objectName().isEmpty())
            reportView->setObjectName("reportView");
        reportView->resize(710, 596);
        buttonBox = new QDialogButtonBox(reportView);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(520, 560, 166, 24));
        buttonBox->setStandardButtons(QDialogButtonBox::Ok|QDialogButtonBox::Save);
        buttonBox->setCenterButtons(false);
        logoLabel = new QLabel(reportView);
        logoLabel->setObjectName("logoLabel");
        logoLabel->setGeometry(QRect(9, 9, 281, 61));
        textBrowser = new QTextBrowser(reportView);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(10, 80, 681, 471));
        infoLabel = new QLabel(reportView);
        infoLabel->setObjectName("infoLabel");
        infoLabel->setGeometry(QRect(320, 10, 361, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("HoloLens MDL2 Assets")});
        font.setPointSize(28);
        infoLabel->setFont(font);

        retranslateUi(reportView);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, reportView, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, reportView, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(reportView);
    } // setupUi

    void retranslateUi(QDialog *reportView)
    {
        reportView->setWindowTitle(QCoreApplication::translate("reportView", "Dialog", nullptr));
        logoLabel->setText(QCoreApplication::translate("reportView", "LOGO", nullptr));
        infoLabel->setText(QCoreApplication::translate("reportView", "Informacje o systemie", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reportView: public Ui_reportView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTVIEW_H
