#include <QtTest/QtTest>
#include "perfil_usuario.h"

#ifndef TST_PERFIL_USUARIO_H
#define TST_PERFIL_USUARIO_H


class tst_perfil_usuario: public QObject
{
    Q_OBJECT
    public:
        tst_perfil_usuario();
    private:
        QString email_logado;
        QString password_logado;
        PerfilUsuario perfilUsuario;
    private:
        void criarUsuarioTeste();
        void removerUsuarioTeste();
    private slots:
        void testInit();
        void testEmail();
        void testIdade();
        void testSetIdade();
        void testNome();
        void testSetNome();
        void testSobrenome();
        void testSetSobrenome();
        void testSaldo();
        void testSimplificar();
        void testSetSimplificar();
};

#endif // TST_PERFIL_USUARIO_H
