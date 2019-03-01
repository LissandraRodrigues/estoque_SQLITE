#-------------------------------------------------
#
# Project created by QtCreator 2019-02-05T22:55:06
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = P_SQL_QT
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        fm_principal.cpp \
    fm_login.cpp \
    fm_novas_vendas.cpp \
    fm_gestao_vendas.cpp \
    fm_gestao_estoque.cpp \
    fm_gestao_colaboradores.cpp

HEADERS += \
        fm_principal.h \
    fm_login.h \
    fm_conexao.h \
    fm_novas_vendas.h \
    fm_gestao_vendas.h \
    fm_gestao_estoque.h \
    fm_gestao_colaboradores.h

FORMS += \
        fm_principal.ui \
    fm_login.ui \
    fm_novas_vendas.ui \
    fm_gestao_vendas.ui \
    fm_gestao_estoque.ui \
    fm_gestao_colaboradores.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource_sql.qrc
