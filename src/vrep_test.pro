TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

DEFINES += NON_MATLAB_PARSING
DEFINES += MAX_EXT_API_CONNECTIONS=255
DEFINES += QT_COMPIL

LIBS += -lWs2_32
LIBS += -lWinmm

INCLUDEPATH += v_rep_api/include

SOURCES += main.cpp \
    v_rep_api/extApi.c \
    v_rep_api/extApiCustom.c \
    v_rep_api/extApiPlatform.c

HEADERS += \
    v_rep_api/include/extApi.h \
    v_rep_api/include/extApiCustom.h \
    v_rep_api/include/extApiCustomConst.h \
    v_rep_api/include/extApiInternal.h \
    v_rep_api/include/extApiPlatform.h \
    v_rep_api/include/socketInConnection.h \
    v_rep_api/include/socketOutConnection.h \
    v_rep_api/include/v_repConst.h \
    v_rep_api/include/v_repLib.h \
    v_rep_api/include/v_repTypes.h
