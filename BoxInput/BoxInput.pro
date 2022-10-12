QT += quick core qml

SOURCES += \
        main.cpp \
        numbercontrol.cpp

CONFIG += qml_debug

resources.files = main.qml 
resources.prefix = /$${TARGET}
RESOURCES += resources \
    components/components.qrc \
    images/images.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    components/Background.qml \
    components/DataArea.qml

HEADERS += \
    numbercontrol.h
