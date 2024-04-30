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
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *versionLabel;
    QLabel *infoLabel;
    QListWidget *activeCaseWidget;
    QLabel *infoLabel2;
    QListWidget *completeCaseWidget;
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

        activeCaseWidget = new QListWidget(centralwidget);
        activeCaseWidget->setObjectName("activeCaseWidget");

        verticalLayout->addWidget(activeCaseWidget);

        infoLabel2 = new QLabel(centralwidget);
        infoLabel2->setObjectName("infoLabel2");

        verticalLayout->addWidget(infoLabel2);

        completeCaseWidget = new QListWidget(centralwidget);
        completeCaseWidget->setObjectName("completeCaseWidget");

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

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        versionLabel->setText(QString());
        infoLabel->setText(QCoreApplication::translate("MainWindow", "Active Cases", nullptr));
        infoLabel2->setText(QCoreApplication::translate("MainWindow", "Completed Cases", nullptr));
        menuMore->setTitle(QCoreApplication::translate("MainWindow", "More", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
