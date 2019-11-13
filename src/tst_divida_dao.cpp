#include "tst_divida_dao.h"

tst_divida_dao::tst_divida_dao(){}

void tst_divida_dao::initTestCase(){
    m_emailDevedor = "teste@gmail.com";
    m_emailCredor = "teste@gmail.com";
    m_quantia = 50;
    m_tipoMoeda = "R$";
    m_categoria = "Alimentação";
    divida_dao = new DividaDAO();
    divida.setEmailDevedor(m_emailDevedor);
    divida.setEmailCredor(m_emailCredor);
    divida.setQuantia(m_quantia);
    divida.setTipoMoeda(m_tipoMoeda);
    divida.setCategoria(m_categoria);
}

void tst_divida_dao::testInsertDivida(){
    divida_dao->removeDivida(m_emailDevedor, m_emailCredor);
    QCOMPARE(divida_dao->insertDivida(divida), true);
    divida_dao->removeDivida(m_emailDevedor, m_emailCredor);
}

void tst_divida_dao::testRemoveDivida(){
    divida_dao->insertDivida(divida);
    QCOMPARE(divida_dao->removeDivida(m_emailDevedor, m_emailCredor), true);
}

void tst_divida_dao::testDividaCount(){
    int qtdadeAntes = divida_dao->dividaCount();
    divida_dao->insertDivida(divida);
    int qtdadeDepois = divida_dao->dividaCount();
    QCOMPARE(qtdadeDepois-qtdadeAntes, 1);
    divida_dao->removeDivida(m_emailDevedor, m_emailCredor);
}

void tst_divida_dao::testUsuarios(){
    std::unique_ptr<std::vector<std::unique_ptr<Divida>>> list(
         new std::vector<std::unique_ptr<Divida>>());
    list = divida_dao->usuarios();
    int numAtual = int(list->size());
    int numDepois;

    divida_dao->insertDivida(divida);

    list = divida_dao->usuarios();
    numDepois = int(list->size());

    QCOMPARE(numAtual + 1, numDepois);

    list = divida_dao->usuarios(m_emailDevedor, m_emailCredor);
    numAtual = int(list->size());

    QCOMPARE(numAtual, 1);

    divida_dao->removeDivida(m_emailDevedor, m_emailCredor);
}
