#include "tst_manejar_despesa.h"
#include "manejar_despesa.h"
#include "cadastrar_usuario.h"
#include "despesa_dao.h"

tst_manejar_despesa::tst_manejar_despesa() {}

void tst_manejar_despesa::initTestCase() {
    email = "teste@gmail.com";
    senha = "12345678";
    idade = "20";
    nome = "Teste";
    sobrenome = "da Silva";
    saldo = "1234";
    simplificar = false;
    descricao = "Despesa de Teste";
    data = "01/01/1900";
    categoria = "Categoria de teste";
    frequencia = "";
    quantia = "50";
    manejar_despesa = new Manejar_despesa();
    cadastrarUsuario = new CadastrarUsuario();

    if (cadastrarUsuario->usuarioExiste(email)){
        DespesaDAO *despesa_dao = new DespesaDAO();
        despesa_dao->removeTodasDespesasUsuario(email);
    } else {
        cadastrarUsuario->inserirUsuario(email, senha, idade, nome,
                                         sobrenome, saldo, simplificar);
    }
}

void tst_manejar_despesa::testInserirDespesa() {
    int qtdadeAntes = manejar_despesa->quantidadeDespesasUsuario(email);
    manejar_despesa->inserirDespesa(email, descricao, data,
                                    categoria, frequencia, quantia);
    int qtdadeDepois = manejar_despesa->quantidadeDespesasUsuario(email);

    QCOMPARE(qtdadeDepois-qtdadeAntes, 1);

    manejar_despesa->removerDespesa(email, descricao);
}

void tst_manejar_despesa::testRemoverDespesa() {
    int qtdadeAntes = manejar_despesa->quantidadeDespesasUsuario(email);
    manejar_despesa->inserirDespesa(email, descricao, data,
                                    categoria, frequencia, quantia);
    manejar_despesa->removerDespesa(email, descricao);
    int qtdadeDepois = manejar_despesa->quantidadeDespesasUsuario(email);

    QCOMPARE(qtdadeDepois-qtdadeAntes, 0);
}

void tst_manejar_despesa::testQuantidadeDespesasUsuario() {
    manejar_despesa->inserirDespesa(email, descricao, data,
                                    categoria, frequencia, quantia);
    int qtdade = manejar_despesa->quantidadeDespesasUsuario(email);

    QCOMPARE(qtdade, 1);

    manejar_despesa->removerDespesa(email, descricao);
}

void tst_manejar_despesa::testGetDescricaoDespesaUsuario() {
    manejar_despesa->inserirDespesa(email, descricao, data,
                                    categoria, frequencia, quantia);

    QCOMPARE(descricao, manejar_despesa->getDescricaoDespesaUsuario(email, 0));

    manejar_despesa->removerDespesa(email, descricao);
}

void tst_manejar_despesa::testGetCategoriaDespesaUsuario() {

    manejar_despesa->inserirDespesa(email, descricao, data,
                                    categoria, frequencia, quantia);

    QCOMPARE(categoria, manejar_despesa->getCategoriaDespesaUsuario(email, 0));

    manejar_despesa->removerDespesa(email, descricao);
}

void tst_manejar_despesa::testGetDataDespesaUsuario() {
    manejar_despesa->inserirDespesa(email, descricao, data,
                                    categoria, frequencia, quantia);

    QCOMPARE(data, manejar_despesa->getDataDespesaUsuario(email, 0));

    manejar_despesa->removerDespesa(email, descricao);
}

void tst_manejar_despesa::testGetFrequenciaDespesaUsuario() {
    manejar_despesa->inserirDespesa(email, descricao, data,
                                    categoria, frequencia, quantia);

    QCOMPARE(frequencia, manejar_despesa->getFrequenciaDespesaUsuario(email, 0));

    manejar_despesa->removerDespesa(email, descricao);
}

void tst_manejar_despesa::testGetQuantiaDespesaUsuario() {
    manejar_despesa->inserirDespesa(email, descricao, data,
                                    categoria, frequencia, quantia);

    QCOMPARE(quantia.toInt(), manejar_despesa->getQuantiaDespesaUsuario(email, 0));

    manejar_despesa->removerDespesa(email, descricao);
}


