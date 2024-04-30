/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionShow_basic_report;
    QAction *actionShow_advanced_report;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *tempLlabel;
    QPushButton *reportButton;
    QMenuBar *menubar;
    QMenu *menuMore;
    QMenu *menuReport;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        actionShow_basic_report = new QAction(MainWindow);
        actionShow_basic_report->setObjectName("actionShow_basic_report");
        actionShow_advanced_report = new QAction(MainWindow);
        actionShow_advanced_report->setObjectName("actionShow_advanced_report");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        tempLlabel = new QLabel(centralwidget);
        tempLlabel->setObjectName("tempLlabel");
        tempLlabel->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tempLlabel->sizePolicy().hasHeightForWidth());
        tempLlabel->setSizePolicy(sizePolicy);
        tempLlabel->setMaximumSize(QSize(16777215, 210));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(48);
        font.setBold(false);
        tempLlabel->setFont(font);
        tempLlabel->setPixmap(QPixmap(QString::fromUtf8("helpdesk-baner.png")));
        tempLlabel->setScaledContents(false);
        tempLlabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(tempLlabel, 0, 0, 1, 1);

        reportButton = new QPushButton(centralwidget);
        reportButton->setObjectName("reportButton");

        gridLayout->addWidget(reportButton, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuMore = new QMenu(menubar);
        menuMore->setObjectName("menuMore");
        menuReport = new QMenu(menubar);
        menuReport->setObjectName("menuReport");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMore->menuAction());
        menubar->addAction(menuReport->menuAction());
        menuMore->addAction(actionAbout);
        menuReport->addAction(actionShow_basic_report);
        menuReport->addAction(actionShow_advanced_report);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionShow_basic_report->setText(QCoreApplication::translate("MainWindow", "Show basic report", nullptr));
        actionShow_advanced_report->setText(QCoreApplication::translate("MainWindow", "Show advanced report", nullptr));
        tempLlabel->setText(QString());
        reportButton->setText(QCoreApplication::translate("MainWindow", "Create Case", nullptr));
        menuMore->setTitle(QCoreApplication::translate("MainWindow", "More", nullptr));
        menuReport->setTitle(QCoreApplication::translate("MainWindow", "Report", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
