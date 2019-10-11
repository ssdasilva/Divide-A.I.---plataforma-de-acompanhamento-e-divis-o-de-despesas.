QT += quick sql

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    src/cadastrar_usuario.h \
    src/database_manager.h \
    src/despesa.h \
    src/despesa_dao.h \
    src/divida.h \
    src/divida_dao.h \
    src/grupo.h \
    src/grupo_dao.h \
    src/manejar_despesa.h \
    src/salvar_usuario.h \
    src/secao_usuario.h \
    src/usuario.h \
    src/usuario_dao.h \
    src/usuario_grupo.h \
    src/usuario_grupo_dao.h

SOURCES += \
        src/cadastrar_usuario.cpp \
        src/despesa.cpp \
        src/despesa_dao.cpp \
        src/divida.cpp \
        src/divida_dao.cpp \
        src/grupo_dao.cpp \
        src/main.cpp \
        src/database_manager.cpp \
        src/grupo.cpp \
        src/manejar_despesa.cpp \
        src/salvar_usuario.cpp \
        src/secao_usuario.cpp \
        src/usuario.cpp \
        src/usuario_dao.cpp \
        src/usuario_grupo.cpp \
        src/usuario_grupo_dao.cpp

RESOURCES += qml.qrc \
    imagens.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
