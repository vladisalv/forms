#-------------------------------------------------
#
# Project created by QtCreator 2015-02-18T02:38:00
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = forms
TEMPLATE = app


SOURCES += main.cpp\
        common.cpp \
    connecting.cpp \
    program.cpp \
    queue.cpp \
    ssh2_exec.cpp \
    xml.cpp \
    settings.cpp

HEADERS  += common.h \
    connecting.h \
    program.h \
    queue.h \
    libssh2_config.h \
    xml.h \
    settings.h

FORMS += \
    connecting.ui \
    program.ui \
    queue.ui

LIBS += -lssh2 -L/usr/local/lib
INCLUDEPATH += /usr/local/include

QMAKE_CXXFLAGS += -std=c++0x

OTHER_FILES += \
    default.cfg

RESOURCES += \
    forms.qrc
