#include "tst_grupo.h"
#include "grupo.h"

tst_grupo::tst_grupo()
{
    grupo = new Grupo();
    grupo->setIdentificador("123456");
    grupo->setNome("Alunos engenharia elétrica UFMG - 2016/1");
    grupo->setNumPessoas(40);
}

void tst_grupo::testIdentificador(){
    QVERIFY("123456"==grupo->identificador());
}

void tst_grupo::testSetIdentificador(){
    grupo->setIdentificador("abcdef");
    QVERIFY("abcdef"==grupo->identificador());

    grupo->setIdentificador("abc123");
    QVERIFY("abc123"==grupo->identificador());
}

void tst_grupo::testNome(){
    QVERIFY("Alunos engenharia elétrica UFMG - 2016/1"==grupo->nome());
}

void tst_grupo::testSetNome(){
    grupo->setNome("Churrasco final do ano");
    QVERIFY("Churrasco final do ano"==grupo->nome());

    grupo->setNome("Grupo da família Xavier");
    QVERIFY("Grupo da família Xavier"==grupo->nome());
}

void tst_grupo::testNumPessoas(){
    QVERIFY(40==grupo->numPessoas());
}

void tst_grupo::testSetNumPessoas(){
    grupo->setNumPessoas(10);
    QVERIFY(10==grupo->numPessoas());

    grupo->setNumPessoas(15);
    QVERIFY(15==grupo->numPessoas());
}
