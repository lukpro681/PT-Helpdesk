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

QT_BEGIN_NAMESPACE

class Ui_reportView
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *reportView)
    {
        if (reportView->objectName().isEmpty())
            reportView->setObjectName("reportView");
        reportView->resize(400, 300);
        buttonBox = new QDialogButtonBox(reportView);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok|QDialogButtonBox::Save);

        retranslateUi(reportView);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, reportView, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, reportView, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(reportView);
    } // setupUi

    void retranslateUi(QDialog *reportView)
    {
        reportView->setWindowTitle(QCoreApplication::translate("reportView", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reportView: public Ui_reportView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTVIEW_H
