#-------------------------------------------------
#
# Project created by QtCreator 2017-03-16T16:06:44
#
#-------------------------------------------------

QT       += core gui webenginewidgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 360Safe
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
        mainwindow.cpp \
        customviews/waveballwidget.cpp \
        customviews/hoverpushbutton.cpp\
        dialog/questiondialog.cpp\
        dialog/aboutdialog.cpp \
    customviews/scanwidget.cpp \
    widget/homewidget.cpp \
    widget/home2widget.cpp \
    customviews/statewidget.cpp \
    widget/horsewidget.cpp \
    widget/horse2widget.cpp \
    widget/clearwidget.cpp \
    widget/clear2widget.cpp \
    widget/fixwidget.cpp \
    widget/fix2widget.cpp \
    widget/optimizewidget.cpp \
    widget/optimize2widget.cpp \
    widget/fuctionswidget.cpp \
    dialog/market360dialog.cpp \
    customviews/progressbarwidget.cpp \
    dialog/upgradedialog.cpp \
    customviews/upgradewidget.cpp \
    dialog/optiondialog.cpp \
    customviews/checkwidget.cpp \
    popupwidgets/dataconnectsetup.cpp \
    popupwidgets/popupwidget.cpp \
    customviews/hovertoolbutton.cpp \
    widget/loginwidget.cpp \
    widget/clearmenuwidget.cpp \
    customviews/focuswidget.cpp \
    widget/actionswidget.cpp

HEADERS  += mainwindow.h \
        customviews/waveballwidget.h \
    customviews/hoverpushbutton.h\
        dialog/questiondialog.h\
        dialog/aboutdialog.h \
    customviews/scanwidget.h \
    widget/homewidget.h \
    widget/home2widget.h \
    customviews/statewidget.h \
    widget/horsewidget.h \
    widget/horse2widget.h \
    widget/clearwidget.h \
    widget/clear2widget.h \
    widget/fixwidget.h \
    widget/fix2widget.h \
    widget/optimizewidget.h \
    widget/optimize2widget.h \
    widget/fuctionswidget.h \
    dialog/market360dialog.h \
    customviews/progressbarwidget.h \
    dialog/upgradedialog.h \
    customviews/upgradewidget.h \
    dialog/optiondialog.h \
    customviews/checkwidget.h \
    popupwidgets/dataconnectsetup.h \
    popupwidgets/popupwidget.h \
    customviews/hovertoolbutton.h \
    widget/loginwidget.h \
    widget/clearmenuwidget.h \
    customviews/focuswidget.h \
    widget/actionswidget.h

FORMS    += mainwindow.ui \
        dialog/questiondialog.ui\
        dialog/aboutdialog.ui \
    widget/home2widget.ui \
    widget/homewidget.ui \
    customviews/statewidget.ui \
    widget/horsewidget.ui \
    widget/horse2widget.ui \
    widget/clearwidget.ui \
    widget/clear2widget.ui \
    widget/fixwidget.ui \
    widget/fix2widget.ui \
    widget/optimizewidget.ui \
    widget/optimize2widget.ui \
    widget/fuctionswidget.ui \
    dialog/market360dialog.ui \
    dialog/upgradedialog.ui \
    dialog/optiondialog.ui \
    customviews/scanwidget.ui \
    popupwidgets/dataconnectsetup.ui \
    popupwidgets/loginpopupwidget.ui \
    widget/loginwidget.ui \
    widget/clearmenuwidget.ui \
    widget/actionswidget.ui

RESOURCES += \
    resource.qrc

DISTFILES += \
    styles.qss
