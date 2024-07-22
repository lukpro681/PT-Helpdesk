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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DetailsDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *infoLabel;
    QLabel *fromLabel;
    QLabel *fromResponse;
    QLabel *typeLabel;
    QLabel *typeResponse;
    QLabel *statusLabel;
    QLabel *statusResponse;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *closeCaseButton;
    QPushButton *assignCaseButton;
    QDialogButtonBox *buttonBox;
    QLabel *descLabel;

    void setupUi(QDialog *DetailsDialog)
    {
        if (DetailsDialog->objectName().isEmpty())
            DetailsDialog->setObjectName("DetailsDialog");
        DetailsDialog->resize(635, 501);
        gridLayout = new QGridLayout(DetailsDialog);
        gridLayout->setObjectName("gridLayout");
        infoLabel = new QLabel(DetailsDialog);
        infoLabel->setObjectName("infoLabel");
        infoLabel->setMaximumSize(QSize(16777215, 75));
        QFont font;
        font.setPointSize(26);
        font.setBold(true);
        infoLabel->setFont(font);

        gridLayout->addWidget(infoLabel, 0, 0, 1, 1);

        fromLabel = new QLabel(DetailsDialog);
        fromLabel->setObjectName("fromLabel");
        fromLabel->setMaximumSize(QSize(16777215, 20));

        gridLayout->addWidget(fromLabel, 1, 0, 1, 1);

        fromResponse = new QLabel(DetailsDialog);
        fromResponse->setObjectName("fromResponse");

        gridLayout->addWidget(fromResponse, 1, 1, 1, 1);

        typeLabel = new QLabel(DetailsDialog);
        typeLabel->setObjectName("typeLabel");
        typeLabel->setMaximumSize(QSize(16777215, 20));

        gridLayout->addWidget(typeLabel, 2, 0, 1, 1);

        typeResponse = new QLabel(DetailsDialog);
        typeResponse->setObjectName("typeResponse");

        gridLayout->addWidget(typeResponse, 2, 1, 1, 1);

        statusLabel = new QLabel(DetailsDialog);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setMaximumSize(QSize(16777215, 20));

        gridLayout->addWidget(statusLabel, 3, 0, 1, 1);

        statusResponse = new QLabel(DetailsDialog);
        statusResponse->setObjectName("statusResponse");

        gridLayout->addWidget(statusResponse, 3, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        closeCaseButton = new QPushButton(DetailsDialog);
        closeCaseButton->setObjectName("closeCaseButton");

        horizontalLayout_2->addWidget(closeCaseButton);

        assignCaseButton = new QPushButton(DetailsDialog);
        assignCaseButton->setObjectName("assignCaseButton");

        horizontalLayout_2->addWidget(assignCaseButton);

        buttonBox = new QDialogButtonBox(DetailsDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);


        gridLayout->addLayout(horizontalLayout_2, 5, 0, 1, 2);

        descLabel = new QLabel(DetailsDialog);
        descLabel->setObjectName("descLabel");
        descLabel->setMinimumSize(QSize(0, 275));
        descLabel->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(descLabel, 4, 0, 1, 2);


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
        closeCaseButton->setText(QCoreApplication::translate("DetailsDialog", "Close Case", nullptr));
        assignCaseButton->setText(QCoreApplication::translate("DetailsDialog", "Assign Case", nullptr));
        descLabel->setText(QCoreApplication::translate("DetailsDialog", "Description", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DetailsDialog: public Ui_DetailsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILSDIALOG_H
