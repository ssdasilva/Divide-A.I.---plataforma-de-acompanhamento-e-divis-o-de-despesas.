#include "tst_salvar_usuario.h"

#include "salvar_usuario.h"

tst_salvar_usuario::tst_salvar_usuario()
{
}

void tst_salvar_usuario::testSave()
{
    Salvar_usuario *salvar_usuario = new Salvar_usuario();
    QString lastEmail = salvar_usuario -> loadEmail();
    QString lastPassword = salvar_usuario -> loadPassword();

    salvar_usuario->save ("samuelsouzadasilva@hotmail.com","minhasenha123");
    QVERIFY("samuelsouzadasilva@hotmail.com"==salvar_usuario -> loadEmail());
    QVERIFY("minhasenha123"==salvar_usuario->loadPassword());

    salvar_usuario->save ("izabela@hotmail.com","iza123");
    QVERIFY("izabela@hotmail.com"==salvar_usuario->loadEmail());
    QVERIFY("iza123"==salvar_usuario->loadPassword());

    salvar_usuario->save ("amanda@hotmail.com","amanda123");
    QVERIFY("amanda@hotmail.com"==salvar_usuario->loadEmail());
    QVERIFY("amanda123"==salvar_usuario->loadPassword());

    salvar_usuario->save (lastEmail,lastPassword);
}

void tst_salvar_usuario::testDeleteSettings()
{
    Salvar_usuario *salvar_usuario = new Salvar_usuario();
    QString lastEmail = salvar_usuario -> loadEmail();
    QString lastPassword = salvar_usuario -> loadPassword();

    salvar_usuario->save ("samuelsouzadasilva@hotmail.com","minhasenha123");
    salvar_usuario->deleteSettings();
    QVERIFY(""==salvar_usuario->loadEmail());
    QVERIFY(""==salvar_usuario->loadPassword());

    salvar_usuario->save ("izabela@hotmail.com","iza123");
    salvar_usuario->deleteSettings();
    QVERIFY(""==salvar_usuario->loadEmail());
    QVERIFY(""==salvar_usuario->loadPassword());

    salvar_usuario->save ("amanda@hotmail.com","amanda123");
    salvar_usuario->deleteSettings();
    QVERIFY(""==salvar_usuario->loadEmail());
    QVERIFY(""==salvar_usuario->loadPassword());

    salvar_usuario->save (lastEmail,lastPassword);
}
