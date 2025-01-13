TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        admins.cpp \
        books.cpp \
        dbase.cpp \
        issuedbooks.cpp \
        main.cpp \
        members.cpp

INCLUDEPATH += /usr/include
LIBS += -lsqlite3

HEADERS += \
    admins.h \
    books.h \
    dbase.h \
    issuedbooks.h \
    members.h
