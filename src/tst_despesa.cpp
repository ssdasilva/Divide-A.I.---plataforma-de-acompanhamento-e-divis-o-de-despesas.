#include "tst_despesa.h"

tst_despesa::tst_despesa(){}

void tst_despesa::initTestCase(){
    despesa = new Despesa();
}

void tst_despesa::testEmail(){
    despesa->setEmail("teste@gmail.com");
    QCOMPARE(despesa->getEmail(), "teste@gmail.com");
}

void tst_despesa::testDescricao() {
    despesa->setDescricao("Teste de Descricao");
    QCOMPARE(despesa->getDescricao(), "Teste de Descricao");
}

void tst_despesa::testData() {
    despesa->setData("01/01/1900");
    QCOMPARE(despesa->getData(), "01/01/1900");
}

void tst_despesa::testCategoria(){
    despesa->setCategoria("Alimentação");
    QCOMPARE(despesa->getCategoria(), "Alimentação");
}

void tst_despesa::testFrequencia(){
    despesa->setFrequencia("Semanal");
    QCOMPARE(despesa->getFrequencia(), "Semanal");
}

void tst_despesa::testQuantia() {
    despesa->setQuantia(50);
    QCOMPARE(despesa->getQuantia(), 50);
}
