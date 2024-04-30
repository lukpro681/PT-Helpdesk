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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_reportDialog
{
public:
    QFormLayout *formLayout;
    QLabel *infoLabel;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QRadioButton *srButton;
    QRadioButton *incButton;
    QRadioButton *secIncButton;
    QLabel *infoLabel2;
    QTextEdit *descText;
    QLabel *infoLabel3;
    QDialogButtonBox *buttonBox;
    QLineEdit *sendToText;
    QPushButton *pushButton;

    void setupUi(QDialog *reportDialog)
    {
        if (reportDialog->objectName().isEmpty())
            reportDialog->setObjectName("reportDialog");
        reportDialog->resize(543, 625);
        reportDialog->setMinimumSize(QSize(543, 623));
        reportDialog->setMaximumSize(QSize(16777215, 625));
        formLayout = new QFormLayout(reportDialog);
        formLayout->setObjectName("formLayout");
        infoLabel = new QLabel(reportDialog);
        infoLabel->setObjectName("infoLabel");
        QFont font;
        font.setPointSize(28);
        infoLabel->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, infoLabel);

        groupBox = new QGroupBox(reportDialog);
        groupBox->setObjectName("groupBox");
        groupBox->setMaximumSize(QSize(16777215, 50));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName("horizontalLayout");
        srButton = new QRadioButton(groupBox);
        srButton->setObjectName("srButton");

        horizontalLayout->addWidget(srButton);

        incButton = new QRadioButton(groupBox);
        incButton->setObjectName("incButton");

        horizontalLayout->addWidget(incButton);

        secIncButton = new QRadioButton(groupBox);
        secIncButton->setObjectName("secIncButton");

        horizontalLayout->addWidget(secIncButton);


        formLayout->setWidget(1, QFormLayout::SpanningRole, groupBox);

        infoLabel2 = new QLabel(reportDialog);
        infoLabel2->setObjectName("infoLabel2");
        infoLabel2->setMaximumSize(QSize(16777215, 30));

        formLayout->setWidget(2, QFormLayout::LabelRole, infoLabel2);

        descText = new QTextEdit(reportDialog);
        descText->setObjectName("descText");
        descText->setMinimumSize(QSize(0, 375));

        formLayout->setWidget(3, QFormLayout::SpanningRole, descText);

        infoLabel3 = new QLabel(reportDialog);
        infoLabel3->setObjectName("infoLabel3");
        infoLabel3->setMaximumSize(QSize(16777215, 30));

        formLayout->setWidget(4, QFormLayout::LabelRole, infoLabel3);

        buttonBox = new QDialogButtonBox(reportDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel);

        formLayout->setWidget(8, QFormLayout::FieldRole, buttonBox);

        sendToText = new QLineEdit(reportDialog);
        sendToText->setObjectName("sendToText");

        formLayout->setWidget(5, QFormLayout::SpanningRole, sendToText);

        pushButton = new QPushButton(reportDialog);
        pushButton->setObjectName("pushButton");

        formLayout->setWidget(8, QFormLayout::LabelRole, pushButton);


        retranslateUi(reportDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, reportDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, reportDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(reportDialog);
    } // setupUi

    void retranslateUi(QDialog *reportDialog)
    {
        reportDialog->setWindowTitle(QCoreApplication::translate("reportDialog", "Dialog", nullptr));
        infoLabel->setText(QCoreApplication::translate("reportDialog", "Choose the case Type", nullptr));
        groupBox->setTitle(QString());
        srButton->setText(QCoreApplication::translate("reportDialog", "Service Request (SR)", nullptr));
        incButton->setText(QCoreApplication::translate("reportDialog", "Incident (INC)", nullptr));
        secIncButton->setText(QCoreApplication::translate("reportDialog", "Security Incident (SEC INC)", nullptr));
        infoLabel2->setText(QCoreApplication::translate("reportDialog", "Describe the case", nullptr));
        infoLabel3->setText(QCoreApplication::translate("reportDialog", "Send to:", nullptr));
        sendToText->setText(QString());
        pushButton->setText(QCoreApplication::translate("reportDialog", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reportDialog: public Ui_reportDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTDIALOG_H
