QT       += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about.cpp \
    detailsdialog.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    about.h \
    detailsdialog.h \
    mainwindow.h

FORMS += \
    about.ui \
    detailsdialog.ui \
    mainwindow.ui

TRANSLATIONS += \
    PT-Helpdesk-Server_pl_PL.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    PTIcon.ico \
    cases.json

RC_ICONS = PTIcon.ico
