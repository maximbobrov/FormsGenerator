QT += core gui sql printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FormsGenerator
TEMPLATE = app

HEADERS = mainwindow.h \
    pages.h \
    aes256.h \
    QRCodeGenerator.h \
    mypixmaplabel.h \
    commondata.h \
    mytranslatable.h \
    mysqltablemodel.h \
    dialog.h \
    dialog1.h \
    dialog2.h \
    navbutton.h

SOURCES = main.cpp \
    mainwindow.cpp \
    pages.cpp \
    generateformspage.cpp \
    aes256.c \
    QRCodeGenerator.cpp \
    mypixmaplabel.cpp \
    printandpreviewpage.cpp \
    commondata.cpp \
    edittablespage.cpp \
    mytranslatable.cpp \
    mysqltablemodel.cpp \
    dialog.cpp \
    dialog1.cpp \
    dialog2.cpp \
    navbutton.cpp


RESOURCES += \
    app_resources.qrc

VERSION = 1.0.0.1
