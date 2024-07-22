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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *versionLabel;
    QLabel *infoLabel;
    QTableWidget *activeCaseWidget;
    QLabel *infoLabel2;
    QTableWidget *completeCaseWidget;
    QMenuBar *menubar;
    QMenu *menuMore;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(815, 619);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName("actionAbout_Qt");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        versionLabel = new QLabel(centralwidget);
        versionLabel->setObjectName("versionLabel");
        versionLabel->setMaximumSize(QSize(425, 110));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(28);
        font.setKerning(true);
        versionLabel->setFont(font);
        versionLabel->setPixmap(QPixmap(QString::fromUtf8("helpdesk-baner.png")));
        versionLabel->setScaledContents(true);

        verticalLayout->addWidget(versionLabel);

        infoLabel = new QLabel(centralwidget);
        infoLabel->setObjectName("infoLabel");

        verticalLayout->addWidget(infoLabel);

        activeCaseWidget = new QTableWidget(centralwidget);
        if (activeCaseWidget->columnCount() < 5)
            activeCaseWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        activeCaseWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        activeCaseWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        activeCaseWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        activeCaseWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        activeCaseWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        activeCaseWidget->setObjectName("activeCaseWidget");
        activeCaseWidget->setSortingEnabled(true);
        activeCaseWidget->setColumnCount(5);
        activeCaseWidget->horizontalHeader()->setCascadingSectionResizes(false);
        activeCaseWidget->horizontalHeader()->setMinimumSectionSize(35);
        activeCaseWidget->horizontalHeader()->setDefaultSectionSize(110);
        activeCaseWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        activeCaseWidget->horizontalHeader()->setStretchLastSection(true);
        activeCaseWidget->verticalHeader()->setCascadingSectionResizes(false);
        activeCaseWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        activeCaseWidget->verticalHeader()->setStretchLastSection(false);

        verticalLayout->addWidget(activeCaseWidget);

        infoLabel2 = new QLabel(centralwidget);
        infoLabel2->setObjectName("infoLabel2");

        verticalLayout->addWidget(infoLabel2);

        completeCaseWidget = new QTableWidget(centralwidget);
        if (completeCaseWidget->columnCount() < 6)
            completeCaseWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        completeCaseWidget->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        completeCaseWidget->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        completeCaseWidget->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        completeCaseWidget->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        completeCaseWidget->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        completeCaseWidget->setHorizontalHeaderItem(5, __qtablewidgetitem10);
        completeCaseWidget->setObjectName("completeCaseWidget");
        completeCaseWidget->horizontalHeader()->setDefaultSectionSize(110);
        completeCaseWidget->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(completeCaseWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 815, 21));
        menuMore = new QMenu(menubar);
        menuMore->setObjectName("menuMore");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMore->menuAction());
        menuMore->addAction(actionAbout);
        menuMore->addAction(actionAbout_Qt);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionAbout_Qt->setText(QCoreApplication::translate("MainWindow", "About Qt", nullptr));
        versionLabel->setText(QString());
        infoLabel->setText(QCoreApplication::translate("MainWindow", "Active Cases", nullptr));
        QTableWidgetItem *___qtablewidgetitem = activeCaseWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = activeCaseWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = activeCaseWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "From", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = activeCaseWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = activeCaseWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        infoLabel2->setText(QCoreApplication::translate("MainWindow", "Completed Cases", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = completeCaseWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = completeCaseWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Closing Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = completeCaseWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = completeCaseWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "From", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = completeCaseWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = completeCaseWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        menuMore->setTitle(QCoreApplication::translate("MainWindow", "More", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
