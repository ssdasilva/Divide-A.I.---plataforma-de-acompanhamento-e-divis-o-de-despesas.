#include "tst_grupo_dao.h"
#include "QtDebug"
#include "database_manager.h"
#include <QSqlQuery>
#include <QVariant>

tst_grupo_dao::tst_grupo_dao()
{
    grupoDAO = DatabaseManager::instance().grupoDAO();
}

void tst_grupo_dao::testInsertGrupo(){
    Grupo grupo;
    grupo.setNome("teste1");
    grupo.setNumPessoas(10);
    grupo.setIdentificador("123444");
    QVERIFY(true == grupoDAO->insertGrupo(grupo));

    grupo.setNome("teste2");
    grupo.setNumPessoas(10);
    grupo.setIdentificador("123455");
    QVERIFY(true == grupoDAO->insertGrupo(grupo));

    grupo.setNome("teste3");
    grupo.setNumPessoas(10);
    grupo.setIdentificador("123456");
    QVERIFY(true == grupoDAO->insertGrupo(grupo));
}

void tst_grupo_dao::testRemoveGrupo(){
    Grupo grupo;

    QVERIFY(true == grupoDAO->removeGrupo("123444"));
    QVERIFY(true == grupoDAO->removeGrupo("123455"));
    QVERIFY(true == grupoDAO->removeGrupo("123456"));
}

void tst_grupo_dao::testGrupoCount(){
    int numAtual = grupoDAO->grupoCount();
    int numDepois;
    Grupo grupo;
    grupo.setNome("teste1");
    grupo.setNumPessoas(10);
    grupo.setIdentificador("123444");
    grupoDAO->insertGrupo(grupo);
    grupo.setNome("teste2");
    grupo.setNumPessoas(10);
    grupo.setIdentificador("123455");
    grupoDAO->insertGrupo(grupo);

    numDepois = grupoDAO->grupoCount();

    grupoDAO->removeGrupo("123444");
    grupoDAO->removeGrupo("123455");

    QVERIFY(numDepois == numAtual + 2);
}

void tst_grupo_dao::testAdicionarUmaPessoaAoGrupo(){
    Grupo grupo;
    grupo.setNome("teste1");
    grupo.setNumPessoas(10);
    grupo.setIdentificador("123444");
    grupoDAO->insertGrupo(grupo);
    QVERIFY(true == grupoDAO->adicionarUmaPessoaAoGrupo("123455"));
    grupoDAO->removeGrupo("123444");

    grupo.setNome("teste2");
    grupo.setNumPessoas(12);
    grupo.setIdentificador("12345");
    grupoDAO->insertGrupo(grupo);
    QVERIFY(true == grupoDAO->adicionarUmaPessoaAoGrupo("12345"));
    grupoDAO->removeGrupo("12345");
}

void tst_grupo_dao::usuarios(){
   Grupo grupo;
   std::unique_ptr<std::vector<std::unique_ptr<Grupo>>> list(
        new std::vector<std::unique_ptr<Grupo>>());
   list = grupoDAO->usuarios();
   int numAtual = int(list->size());
   int numDepois;

   grupo.setNome("teste1");
   grupo.setNumPessoas(10);
   grupo.setIdentificador("123444");
   grupoDAO->insertGrupo(grupo);

   grupo.setNome("teste2");
   grupo.setNumPessoas(12);
   grupo.setIdentificador("12345");
   grupoDAO->insertGrupo(grupo);

   list = grupoDAO->usuarios();
   numDepois = int(list->size());
   grupoDAO->removeGrupo("123444");
   grupoDAO->removeGrupo("12345");

   QVERIFY(numAtual + 2 == numDepois);

   grupo.setNome("teste3");
   grupo.setNumPessoas(13);
   grupo.setIdentificador("98765");
   grupoDAO->insertGrupo(grupo);

   list = grupoDAO->usuarios("98765");
   numAtual = int(list->size());
   grupoDAO->removeGrupo("98765");

   QVERIFY(numAtual == 1);
}
