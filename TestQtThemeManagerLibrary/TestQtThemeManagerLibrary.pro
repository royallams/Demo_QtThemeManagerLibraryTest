#-------------------------------------------------
#
# Project created by QtCreator 2019-07-07T16:30:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestQtThemeMangerLibrary
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui



win32: LIBS += -L$$PWD/../QtThemeLibrary/lib/ -lQtThemeManager

INCLUDEPATH += $$PWD/../QtThemeLibrary/include
DEPENDPATH += $$PWD/../QtThemeLibrary/include
