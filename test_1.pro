QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    errortaker.cpp \
    main.cpp \
    mainwindow.cpp\
    car.cpp \
    datareader.cpp \
    datawriter.cpp \
    complexdll.cpp \
    pass_car.cpp \
    freight_car.cpp \
    bus.cpp \
    errbrowser.cpp \
    abstractreader.cpp \
    jsonreader.cpp

HEADERS += \
    errortaker.h \
    mainwindow.h\
    car.h \
    datareader.h \
    datawriter.h \
    complexdll.h \
    pass_car.h \
    freight_car.h \
    bus.h \
    errbrowser.h \
    abstractreader.h \
    jsonreader.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    cars.json
