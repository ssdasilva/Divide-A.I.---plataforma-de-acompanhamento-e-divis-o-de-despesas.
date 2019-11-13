#include "tst_divida.h"

tst_divida::tst_divida() {}

void tst_divida::initTestCase(){
    divida = new Divida();
}

void tst_divida::testM_emailDevedor(){
    divida->setEmailDevedor("teste@gmail.com");
    QCOMPARE(divida->emailDevedor(), "teste@gmail.com");
}

void tst_divida::testM_emailCredor(){
    divida->setEmailCredor("teste@gmail.com");
    QCOMPARE(divida->emailCredor(), "teste@gmail.com");
}

void tst_divida::testM_quantia(){
    divida->setQuantia(50);
    QCOMPARE(divida->quantia(), 50);
}

void tst_divida::testM_tipoMoeda(){
    divida->setTipoMoeda("R$");
    QCOMPARE(divida->tipoMoeda(), "R$");
}

void tst_divida::testM_categoria(){
    divida->setCategoria("Alimentação");
    QCOMPARE(divida->categoria(), "Alimentação");
}
