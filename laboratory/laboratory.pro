#-------------------------------------------------
#
# Project created by QtCreator 2020-12-16T14:00:37
#
#-------------------------------------------------

QT       += core gui
QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = laboratory
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    student.cpp \
    search_techer.cpp \
    choose_lab.cpp \
    teacher.cpp \
    change_student.cpp \
    delete_student.cpp \
    admin.cpp \
    mstduent.cpp \
    mteacher.cpp \
    add_student.cpp

HEADERS += \
        mainwindow.h \
    student.h \
    search_techer.h \
    choose_lab.h \
    teacher.h \
    change_student.h \
    delete_student.h \
    admin.h \
    mstduent.h \
    mteacher.h \
    add_student.h

FORMS += \
        mainwindow.ui \
    student.ui \
    search_techer.ui \
    choose_lab.ui \
    teacher.ui \
    change_student.ui \
    delete_student.ui \
    admin.ui \
    mstduent.ui \
    mteacher.ui \
    add_student.ui

RESOURCES += \
    res.qrc
