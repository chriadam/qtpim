include(../auto.pri)

QT += contacts versit versit-private

HEADERS += tst_qversitcontactimporter.h
SOURCES += tst_qversitcontactimporter.cpp

#symbian: {
#    TARGET.CAPABILITY = ALL \
#        -TCB
#    LIBS += -lws32 \
#        -lbafl
#}
