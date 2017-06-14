#-------------------------------------------------
#
# Project created by QtCreator 2017-05-12T11:36:37
#
#-------------------------------------------------

QT       += core gui\
            widgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets\


TARGET = MIO_Serveur
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


SOURCES += main.cpp\
    settingswindow.cpp \
    startwindow.cpp \
    log_widget/logwidget.cpp \
    video_widget/videowidget.cpp \
    miowindow.cpp \
    chat_widget/chatwidget.cpp \
    gl_widget/glskeleton.cpp \
    gl_widget/glstream.cpp \
    gl_widget/glwidget.cpp\
    mio/Bone.cpp \
    mio/Frame.cpp \
    mio/Skeleton.cpp \
    mio/Starter.cpp \
    mionetwork.cpp

HEADERS  += \
    settingswindow.h \
    startwindow.h \
    log_widget/logwidget.h \
    video_widget/videowidget.h \
    miowindow.h \
    chat_widget/chatwidget.h \
    gl_widget/glskeleton.h \
    gl_widget/glshape.h \
    gl_widget/glcube.h \
    gl_widget/glstream.h \
    gl_widget/glwidget.h\
    mio/Bone.h \
    mio/DataStreamClient.h \
    mio/Frame.h \
    mio/includes.h \
    mio/Skeleton.h \
    mio/Starter.h \
    mionetwork.h


unix|win32: LIBS += -L$$PWD/libs/ -lViconDataStreamSDK_CPP

INCLUDEPATH += $$PWD/libs
DEPENDPATH += $$PWD/libs

ICON = MIO_Serveur.icns
