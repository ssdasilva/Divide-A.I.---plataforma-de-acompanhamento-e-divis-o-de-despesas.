#include "tst_perfil_usuario.h"
#include "salvar_usuario.h"
#include "database_manager.h"
#include "perfil_usuario.h"
#include "usuario.h"
#include "QThread"

tst_perfil_usuario::tst_perfil_usuario()
{
    Salvar_usuario salvar_usuario;
    email_logado = salvar_usuario.loadEmail();
    password_logado = salvar_usuario.loadPassword();
}

void tst_perfil_usuario::criarUsuarioTeste(){
    UsuarioDAO *usuarioDAO = DatabaseManager::instance().usuarioDAO();
    Usuario usuario;
    Salvar_usuario salvar_usuario;

    usuario.setNome("teste");
    usuario.setEmail("teste@hotmail.com");
    usuario.setIdade(15);
    usuario.setSaldo(0);
    usuario.setSobrenome("teste");
    usuario.setSimplificar(false);
    usuario.setSenha("minhasenha");
    usuarioDAO->insertUsuario(usuario);
    salvar_usuario.save("teste@hotmail.com", "minhasenha");
}

void tst_perfil_usuario::removerUsuarioTeste(){
    Salvar_usuario salvar_usuario;
    UsuarioDAO *usuarioDAO = DatabaseManager::instance().usuarioDAO();
    usuarioDAO->removeUsuario("teste@hotmail.com");
    salvar_usuario.save(email_logado,password_logado);
}

void tst_perfil_usuario::testInit(){
    QString email;
    QString nome;
    criarUsuarioTeste();
    perfilUsuario.init();
    email = perfilUsuario.email();
    nome = perfilUsuario.nome();
    removerUsuarioTeste();
    QVERIFY(email == "teste@hotmail.com");
    QVERIFY(nome == "teste");
}

void tst_perfil_usuario::testEmail(){
    QVERIFY(perfilUsuario.email() == "teste@hotmail.com");
}

void tst_perfil_usuario::testIdade(){
     QVERIFY(perfilUsuario.idade() == "15");
}

void tst_perfil_usuario::testSetIdade(){
    perfilUsuario.setIdade("18");
    QVERIFY(perfilUsuario.idade() == "18");

    perfilUsuario.setIdade("22");
    QVERIFY(perfilUsuario.idade() == "22");
}

void tst_perfil_usuario::testNome(){
     QVERIFY(perfilUsuario.nome() == "teste");
}

void tst_perfil_usuario::testSetNome(){
    perfilUsuario.setNome("teste1");
    QVERIFY(perfilUsuario.nome() == "teste1");

    perfilUsuario.setNome("teste2");
    QVERIFY(perfilUsuario.nome() == "teste2");
}

void tst_perfil_usuario::testSobrenome(){
    QVERIFY(perfilUsuario.sobrenome() == "teste");
}

void tst_perfil_usuario::testSetSobrenome(){
    perfilUsuario.setSobrenome("teste1");
    QVERIFY(perfilUsuario.sobrenome() == "teste1");

    perfilUsuario.setSobrenome("teste2");
    QVERIFY(perfilUsuario.sobrenome() == "teste2");
}

void tst_perfil_usuario::testSaldo(){
    QVERIFY(perfilUsuario.saldo() <= 0);
}

void tst_perfil_usuario::testSimplificar(){
    QVERIFY(perfilUsuario.simplificar() == false);
}

void tst_perfil_usuario::testSetSimplificar(){
    perfilUsuario.setSimplificar(true);
    QVERIFY(perfilUsuario.simplificar() == true);

    perfilUsuario.setSimplificar(false);
    QVERIFY(perfilUsuario.simplificar() == false);
}
