#include <QObject>
#include <QtTest/QtTest>
#include "usuario_grupo.h"

#ifndef TST_USUARIO_GRUPO_H
#define TST_USUARIO_GRUPO_H

class tst_usuario_grupo: public QObject
{
    Q_OBJECT
    public:
        tst_usuario_grupo();
    private:
        UsuarioGrupo *usuarioGrupo;
    private slots:
        void initTestCase();
        void testM_emailUsuario();
        void testM_identificadorGrupo();
};

#endif // TST_USUARIO_GRUPO_H
