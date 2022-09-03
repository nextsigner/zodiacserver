#QT += widgets network declarative
QT += widgets network qml quick
DESTDIR = $$_PRO_FILE_PWD_/../bin
TARGET = zodiac_server
TEMPLATE = app

VPATH += ../swe ../astroprocessor ../chart ../fileeditor ../plain ../planets ../details

include(../swe/swe.pri)
include(../astroprocessor/astroprocessor.pri)
include(../chart/chart.pri)
include(../fileeditor/fileeditor.pri)
include(../plain/plain.pri)
include(../planets/planets.pri)
include(../details/details.pri)
include(zodiac.pri)

#CONFIG(release, debug|release): DEFINES += QT_NO_DEBUG_OUTPUT

DISTFILES += \
    src/test.sh

HEADERS += \
    astroqmlviewv2.h

SOURCES += \
    #astroqmlviewv2.cpp
