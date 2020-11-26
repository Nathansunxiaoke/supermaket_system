#-------------------------------------------------
#
# Project created by QtCreator 2020-11-13T16:22:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SupermarketManagementSystem
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        addacountwindow.cpp \
        addgoodswindow.cpp \
        adminwindow.cpp \
        buygoods.cpp \
        buygoodsinfo.cpp \
        commodity.cpp \
        goods.cpp \
        goodsitem.cpp \
        goodsitemsinfo.cpp \
        loginwindow.cpp \
        main.cpp \
        shopbar.cpp \
        staff.cpp \
        staffinfobar.cpp \
        staffitem.cpp \
        staffmanagerwin.cpp

HEADERS += \
        addacountwindow.h \
        addgoodswindow.h \
        adminwindow.h \
        buygoods.h \
        buygoodsinfo.h \
        commodity.h \
        goods.h \
        goodsitem.h \
        goodsitemsinfo.h \
        loginwindow.h \
        shopbar.h \
        staff.h \
        staffinfobar.h \
        staffitem.h \
        staffmanagerwin.h

FORMS += \
        addacountwindow.ui \
        addgoodswindow.ui \
        adminwindow.ui \
        buygoodsinfo.ui \
        commodity.ui \
        goodsitem.ui \
        goodsitemsinfo.ui \
        loginwindow.ui \
        shopbar.ui \
        staffinfobar.ui \
        staffitem.ui \
        staffmanagerwin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
