HEADERS       = glwidget/glcube.h \
    glwidget/glshape.h \
    glwidget/glskeleton.h \
    glwidget/glstream.h \
    glwidget/glwidget.h \
    mio/Bone.h \
    mio/DataStreamClient.h \
    mio/Frame.h \
    mio/includes.h \
    mio/Skeleton.h \
    window.h \
    mainwindow.h

SOURCES       = main.cpp \
                window.cpp \
                mainwindow.cpp \
    glwidget/glskeleton.cpp \
    glwidget/glstream.cpp \
    glwidget/glwidget.cpp \
    mio/Bone.cpp \
    mio/Frame.cpp \
    mio/Skeleton.cpp

QT           += widgets

unix|win32: LIBS += -L$$PWD/libs/ -lViconDataStreamSDK_CPP

INCLUDEPATH += $$PWD/libs
DEPENDPATH += $$PWD/libs
