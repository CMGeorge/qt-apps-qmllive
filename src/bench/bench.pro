include(../../qmllive.pri)

TEMPLATE = app
TARGET = qmllivebench
DESTDIR = $$BUILD_DIR/bin

CONFIG += c++11
QT *= gui core quick widgets core-private quickcontrols2

SOURCES += \
    ThemePathOptionPage.cpp \
    aboutdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    optionsdialog.cpp \
    benchlivenodeengine.cpp \
    previewimageprovider.cpp \
    directorypreviewadapter.cpp \
    qmlpreviewadapter.cpp \
    host.cpp \
    hostmodel.cpp \
    hostwidget.cpp \
    dummydelegate.cpp \
    allhostswidget.cpp \
    hostmanager.cpp \
    hostsoptionpage.cpp \
    httpproxyoptionpage.cpp \
    importpathoptionpage.cpp \
    hostdiscoverymanager.cpp \
    autodiscoveryhostsdialog.cpp \
    options.cpp \
    newprojectwizard.cpp \
    appearanceoptionpage.cpp

HEADERS += \
    ThemePathOptionPage.h \
    aboutdialog.h \
    mainwindow.h \
    optionsdialog.h \
    benchlivenodeengine.h \
    previewimageprovider.h \
    directorypreviewadapter.h \
    qmlpreviewadapter.h \
    host.h \
    hostmodel.h \
    hostwidget.h \
    dummydelegate.h \
    allhostswidget.h \
    hostmanager.h \
    hostsoptionpage.h \
    importpathoptionpage.h \
    httpproxyoptionpage.h \
    hostdiscoverymanager.h \
    autodiscoveryhostsdialog.h \
    options.h \
    newprojectwizard.h \
    appearanceoptionpage.h

FORMS += \
    ThemePathOptionPage.ui \
    optionsdialog.ui \
    hostsoptionpage.ui \
    httpproxyoptionpage.ui \
    importpathoptionpage.ui \
    autodiscoveryhostsdialog.ui \
    appearanceoptionpage.ui

include(../widgets/widgets.pri)
include(../lib.pri)

# install rules
macx*: CONFIG -= app_bundle
target.path = $$PREFIX/bin
INSTALLS += target

win32: RC_FILE = ../../icons/appicon.rc
macx*: ICON = ../../icons/appicon.icns
