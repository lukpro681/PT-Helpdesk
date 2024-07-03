/********************************************************************************
** Form generated from reading UI file 'detailsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAILSDIALOG_H
#define UI_DETAILSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DetailsDialog
{
public:
    QFormLayout *formLayout;
    QLabel *infoLabel;
    QLabel *fromLabel;
    QLabel *fromResponse;
    QLabel *typeLabel;
    QLabel *typeResponse;
    QLabel *statusLabel;
    QLabel *statusResponse;
    QLabel *descLabel;
    QDialogButtonBox *buttonBox;
    QPushButton *closeCaseButton;

    void setupUi(QDialog *DetailsDialog)
    {
        if (DetailsDialog->objectName().isEmpty())
            DetailsDialog->setObjectName("DetailsDialog");
        DetailsDialog->resize(650, 499);
        formLayout = new QFormLayout(DetailsDialog);
        formLayout->setObjectName("formLayout");
        infoLabel = new QLabel(DetailsDialog);
        infoLabel->setObjectName("infoLabel");
        infoLabel->setMaximumSize(QSize(16777215, 75));
        QFont font;
        font.setPointSize(26);
        font.setBold(true);
        infoLabel->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, infoLabel);

        fromLabel = new QLabel(DetailsDialog);
        fromLabel->setObjectName("fromLabel");
        fromLabel->setMaximumSize(QSize(16777215, 20));

        formLayout->setWidget(1, QFormLayout::LabelRole, fromLabel);

        fromResponse = new QLabel(DetailsDialog);
        fromResponse->setObjectName("fromResponse");

        formLayout->setWidget(1, QFormLayout::FieldRole, fromResponse);

        typeLabel = new QLabel(DetailsDialog);
        typeLabel->setObjectName("typeLabel");
        typeLabel->setMaximumSize(QSize(16777215, 20));

        formLayout->setWidget(2, QFormLayout::LabelRole, typeLabel);

        typeResponse = new QLabel(DetailsDialog);
        typeResponse->setObjectName("typeResponse");

        formLayout->setWidget(2, QFormLayout::FieldRole, typeResponse);

        statusLabel = new QLabel(DetailsDialog);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setMaximumSize(QSize(16777215, 20));

        formLayout->setWidget(3, QFormLayout::LabelRole, statusLabel);

        statusResponse = new QLabel(DetailsDialog);
        statusResponse->setObjectName("statusResponse");

        formLayout->setWidget(3, QFormLayout::FieldRole, statusResponse);

        descLabel = new QLabel(DetailsDialog);
        descLabel->setObjectName("descLabel");
        descLabel->setMaximumSize(QSize(16777215, 16777215));

        formLayout->setWidget(4, QFormLayout::SpanningRole, descLabel);

        buttonBox = new QDialogButtonBox(DetailsDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        formLayout->setWidget(5, QFormLayout::FieldRole, buttonBox);

        closeCaseButton = new QPushButton(DetailsDialog);
        closeCaseButton->setObjectName("closeCaseButton");

        formLayout->setWidget(5, QFormLayout::LabelRole, closeCaseButton);


        retranslateUi(DetailsDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DetailsDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DetailsDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DetailsDialog);
    } // setupUi

    void retranslateUi(QDialog *DetailsDialog)
    {
        DetailsDialog->setWindowTitle(QCoreApplication::translate("DetailsDialog", "Dialog", nullptr));
        infoLabel->setText(QCoreApplication::translate("DetailsDialog", "Case Information", nullptr));
        fromLabel->setText(QCoreApplication::translate("DetailsDialog", "From", nullptr));
        fromResponse->setText(QCoreApplication::translate("DetailsDialog", "TextLabel", nullptr));
        typeLabel->setText(QCoreApplication::translate("DetailsDialog", "Type", nullptr));
        typeResponse->setText(QCoreApplication::translate("DetailsDialog", "TextLabel", nullptr));
        statusLabel->setText(QCoreApplication::translate("DetailsDialog", "Status", nullptr));
        statusResponse->setText(QCoreApplication::translate("DetailsDialog", "TextLabel", nullptr));
        descLabel->setText(QCoreApplication::translate("DetailsDialog", "Description", nullptr));
        closeCaseButton->setText(QCoreApplication::translate("DetailsDialog", "Close Case", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DetailsDialog: public Ui_DetailsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILSDIALOG_H
