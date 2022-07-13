#-------------------------------------------------
#
# Project created by QtCreator 2013-08-29T00:18:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

lessThan(QT_MAJOR_VERSION, 5): error(This project requires Qt 5 or later)

TARGET = Display3DModel
TEMPLATE = app


SOURCES += main.cpp\
        window.cpp \
    scene.cpp \
    modelloader.cpp \
    scene_gles.cpp

HEADERS  += window.h \
    scene.h \
    modelloader.h \
    scene_gles.h \
    scenebase.h



INCLUDEPATH += "C:\Program Files\Assimp\include"
LIBS += -L"C:\Program Files\Assimp\lib\x64" -lassimp

OTHER_FILES += ads_fragment.vert ads_fragment.frag \
    es_ads_fragment.frag \
    es_ads_fragment.vert

RESOURCES += \
    resources.qrc
