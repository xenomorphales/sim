TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

DEFINES += NON_MATLAB_PARSING
DEFINES += MAX_EXT_API_CONNECTIONS=255

LIBS += -lWs2_32
LIBS += -lWinmm

SOURCES += main.cpp \
    extApi.c \
    extApiCustom.c \
    extApiPlatform.c

HEADERS += \
    extApi.h \
    extApiCustom.h \
    extApiInternal.h \
    extApiPlatform.h \
    v_repConst.h \
    extApiCustomConst.h \
    socketInConnection.h \
    socketOutConnection.h \
    v_repLib.h \
    v_repTypes.h
