#include "tst_despesa_dao.h"
#include "despesa_dao.h"
#include "despesa.h"

tst_despesa_dao::tst_despesa_dao() {}

void tst_despesa_dao::initTestCase(){
    email = "teste@gmail.com";
    descricao = "Despesa de Teste";
    data = "01/01/1900";
    categoria = "Categoria de teste";
    frequencia = "";
    quantia = "50";
    despesa_dao = new DespesaDAO();
    despesa.setEmail(email);
    despesa.setDescricao(descricao);
    despesa.setData(data);
    despesa.setCategoria(categoria);
    despesa.setFrequencia(frequencia);
    despesa.setQuantia(quantia.toInt());
    despesa_dao->removeTodasDespesasUsuario(email);
}

void tst_despesa_dao::testInsertDespesa(){
    QCOMPARE(despesa_dao->insertDespesa(despesa), true);
    despesa_dao->removeDespesa(email, descricao);
}

void tst_despesa_dao::testRemoveDespesa(){
    despesa_dao->insertDespesa(despesa);

    QCOMPARE(despesa_dao->removeDespesa(email, descricao), true);
}

void tst_despesa_dao::testRemoveTodasDespesasUsuario(){
    despesa_dao->insertDespesa(despesa);
    despesa.setDescricao("Despesa de Teste 2");
    despesa_dao->insertDespesa(despesa);
    despesa.setDescricao("Despesa de Teste 3");
    despesa_dao->insertDespesa(despesa);

    QCOMPARE(despesa_dao->removeTodasDespesasUsuario(email), true);
}

void tst_despesa_dao::testRemoveAll(){

}

void tst_despesa_dao::testDespesaCount(){
    despesa_dao->removeTodasDespesasUsuario(email);
    int qtdadeAntes = despesa_dao->despesaCount();
    despesa.setDescricao("Despesa de Teste 2");
    despesa_dao->insertDespesa(despesa);
    despesa.setDescricao("Despesa de Teste 3");
    despesa_dao->insertDespesa(despesa);
    int qtdadeDepois = despesa_dao->despesaCount();
    QCOMPARE(qtdadeDepois - qtdadeAntes, 2);
    despesa_dao->removeTodasDespesasUsuario(email);
}

void tst_despesa_dao::testDespesaCountUsuario(){
    despesa_dao->removeTodasDespesasUsuario(email);
    int qtdadeAntes = despesa_dao->despesaCountUsuario(email);
    despesa.setDescricao("Despesa de Teste 2");
    despesa_dao->insertDespesa(despesa);
    despesa.setDescricao("Despesa de Teste 3");
    despesa_dao->insertDespesa(despesa);
    int qtdadeDepois = despesa_dao->despesaCountUsuario(email);
    QCOMPARE(qtdadeDepois - qtdadeAntes, 2);
    despesa_dao->removeTodasDespesasUsuario(email);

}

void tst_despesa_dao::testUsuarios(){

    despesa_dao->removeTodasDespesasUsuario(email);

    std::unique_ptr<std::vector<std::unique_ptr<Despesa>>> list(
         new std::vector<std::unique_ptr<Despesa>>());
    list = despesa_dao->usuarios();
    int numAtual = int(list->size());
    int numDepois;

    despesa.setDescricao("Teste 3");
    despesa_dao->insertDespesa(despesa);
    despesa.setDescricao("Teste 4");
    despesa_dao->insertDespesa(despesa);
    despesa.setDescricao("Teste 5");
    despesa_dao->insertDespesa(despesa);

    list = despesa_dao->usuarios();
    numDepois = int(list->size());

    QCOMPARE(numAtual + 3, numDepois);

    list = despesa_dao->usuarios(email);
    numAtual = int(list->size());

    QCOMPARE(numAtual, 3);

}

void tst_despesa_dao::testAtualizarQuantia(){
}

void tst_despesa_dao::testGastoPorCategoria(){

}
