include(../auto.pri)

unix:QMAKE_LIBS += -Wl,-rpath,$${QT.contacts.libs}

QT += contacts

SOURCES  += tst_qlatin1constant.cpp

