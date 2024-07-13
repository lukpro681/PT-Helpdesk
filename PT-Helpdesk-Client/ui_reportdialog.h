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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_reportDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *infoLabel;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QRadioButton *srButton;
    QRadioButton *incButton;
    QRadioButton *secIncButton;
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton;
    QLabel *infoLabel2;
    QPushButton *findButton;
    QTableWidget *tableWidget;
    QTextEdit *descText;
    QLabel *infoLabel3;
    QLineEdit *sendToText;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *addOptionalReport;
    QLabel *optionalLabel;

    void setupUi(QDialog *reportDialog)
    {
        if (reportDialog->objectName().isEmpty())
            reportDialog->setObjectName("reportDialog");
        reportDialog->resize(1051, 623);
        reportDialog->setMinimumSize(QSize(1051, 623));
        reportDialog->setMaximumSize(QSize(1051, 623));
        gridLayout = new QGridLayout(reportDialog);
        gridLayout->setObjectName("gridLayout");
        infoLabel = new QLabel(reportDialog);
        infoLabel->setObjectName("infoLabel");
        QFont font;
        font.setPointSize(28);
        infoLabel->setFont(font);

        gridLayout->addWidget(infoLabel, 0, 0, 1, 1);

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


        gridLayout->addWidget(groupBox, 1, 0, 2, 2);

        buttonBox = new QDialogButtonBox(reportDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel);

        gridLayout->addWidget(buttonBox, 9, 1, 1, 1);

        pushButton = new QPushButton(reportDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(pushButton, 9, 0, 1, 1);

        infoLabel2 = new QLabel(reportDialog);
        infoLabel2->setObjectName("infoLabel2");
        infoLabel2->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(infoLabel2, 3, 0, 1, 1);

        findButton = new QPushButton(reportDialog);
        findButton->setObjectName("findButton");

        gridLayout->addWidget(findButton, 5, 1, 1, 1);

        tableWidget = new QTableWidget(reportDialog);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName("tableWidget");
        tableWidget->horizontalHeader()->setDefaultSectionSize(160);

        gridLayout->addWidget(tableWidget, 6, 1, 1, 1);

        descText = new QTextEdit(reportDialog);
        descText->setObjectName("descText");
        descText->setMinimumSize(QSize(0, 310));

        gridLayout->addWidget(descText, 4, 0, 4, 1);

        infoLabel3 = new QLabel(reportDialog);
        infoLabel3->setObjectName("infoLabel3");
        infoLabel3->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(infoLabel3, 3, 1, 1, 1);

        sendToText = new QLineEdit(reportDialog);
        sendToText->setObjectName("sendToText");

        gridLayout->addWidget(sendToText, 4, 1, 1, 1);

        groupBox_2 = new QGroupBox(reportDialog);
        groupBox_2->setObjectName("groupBox_2");
        QFont font1;
        font1.setKerning(true);
        groupBox_2->setFont(font1);
        horizontalLayout_4 = new QHBoxLayout(groupBox_2);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        addOptionalReport = new QPushButton(groupBox_2);
        addOptionalReport->setObjectName("addOptionalReport");
        addOptionalReport->setMaximumSize(QSize(125, 16777215));

        horizontalLayout_4->addWidget(addOptionalReport);

        optionalLabel = new QLabel(groupBox_2);
        optionalLabel->setObjectName("optionalLabel");
        optionalLabel->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_4->addWidget(optionalLabel);


        gridLayout->addWidget(groupBox_2, 8, 0, 1, 2);


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
        pushButton->setText(QCoreApplication::translate("reportDialog", "Send", nullptr));
        infoLabel2->setText(QCoreApplication::translate("reportDialog", "Describe the case", nullptr));
        findButton->setText(QCoreApplication::translate("reportDialog", "Refresh list", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("reportDialog", "Host", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("reportDialog", "Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("reportDialog", "Select", nullptr));
        infoLabel3->setText(QCoreApplication::translate("reportDialog", "Send to:", nullptr));
        sendToText->setText(QString());
        groupBox_2->setTitle(QString());
        addOptionalReport->setText(QCoreApplication::translate("reportDialog", "Attach basic report", nullptr));
        optionalLabel->setText(QCoreApplication::translate("reportDialog", "Optional", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reportDialog: public Ui_reportDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTDIALOG_H
