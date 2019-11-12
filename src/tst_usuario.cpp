#include "tst_usuario.h"

tst_usuario::tst_usuario() {}

void tst_usuario::initTestCase() { usuario = new Usuario(this); }

void tst_usuario::testEmail() {
  usuario->setEmail("teste@gmail.com");
  QCOMPARE(usuario->email(), "teste@gmail.com");
}

void tst_usuario::testIdade() {
  usuario->setIdade(21);
  QCOMPARE(usuario->idade(), 21);
}

void tst_usuario::testNome() {
  usuario->setNome("Fulano");
  QCOMPARE(usuario->nome(), "Fulano");
}

void tst_usuario::testSobrenome() {
  usuario->setSobrenome("de Tal");
  QCOMPARE(usuario->sobrenome(), "de Tal");
}

void tst_usuario::testSaldo() {
  usuario->setSaldo(11);
  QCOMPARE(usuario->saldo(), 11);
}

void tst_usuario::testSimplificar() {
  usuario->setSimplificar(true);
  QCOMPARE(usuario->simplificar(), true);
}
