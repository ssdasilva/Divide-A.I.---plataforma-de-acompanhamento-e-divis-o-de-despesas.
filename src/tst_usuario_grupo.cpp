#include "tst_usuario_grupo.h"

tst_usuario_grupo::tst_usuario_grupo(){}

void tst_usuario_grupo::initTestCase(){
    usuarioGrupo = new UsuarioGrupo();
}

void tst_usuario_grupo::testM_emailUsuario(){
    usuarioGrupo->setEmailUsuario("teste@gmail.com");
    QCOMPARE(usuarioGrupo->emailUsuario(), "teste@gmail.com");
}

void tst_usuario_grupo::testM_identificadorGrupo(){
    usuarioGrupo->setIdentificadorGrupo("abcde");
    QCOMPARE(usuarioGrupo->identificadorGrupo(),"abcde");
}
