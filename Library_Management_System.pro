TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        admins.cpp \
        books.cpp \
        dbase.cpp \
        main.cpp \
        members.cpp

INCLUDEPATH += /usr/include
LIBS += -lsqlite3

HEADERS += \
    admins.h \
    books.h \
    dbase.h \
    members.h
