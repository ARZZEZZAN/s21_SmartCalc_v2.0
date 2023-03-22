QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QT += printsupport
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
SOURCES += \
    Controller/controller.cc \
    View/graphwindow.cpp \
    View/mainwindow.cpp \
    Model/CalculatorModel.cc \
    QcustomLibrary/qcustomplot.cpp \
    main.cpp

HEADERS += \
    Controller/controller.h \
    View/graphwindow.h \
    QcustomLibrary/qcustomplot.h \
    View/mainwindow.h \
    Model/CalculatorModel.h

FORMS += \
     View/graphwindow.ui \
     View/mainwindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
