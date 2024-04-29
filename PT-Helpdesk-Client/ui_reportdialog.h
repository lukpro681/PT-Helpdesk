/********************************************************************************
** Form generated from reading UI file 'reportdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTDIALOG_H
#define UI_REPORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_reportDialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *reportDialog)
    {
        if (reportDialog->objectName().isEmpty())
            reportDialog->setObjectName("reportDialog");
        reportDialog->resize(656, 558);
        buttonBox = new QDialogButtonBox(reportDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(290, 510, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(reportDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, reportDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, reportDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(reportDialog);
    } // setupUi

    void retranslateUi(QDialog *reportDialog)
    {
        reportDialog->setWindowTitle(QCoreApplication::translate("reportDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reportDialog: public Ui_reportDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTDIALOG_H
