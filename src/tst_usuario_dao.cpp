#include "tst_usuario_dao.h"
#include "usuario_dao.h"
#include "database_manager.h"

#include <memory>
#include <vector>

tst_usuario_dao::tst_usuario_dao() {}

void tst_usuario_dao::initTestCase() {
  m_email = "teste@gmail.com";
  m_senha = "123456";
  m_idade = 21;
  m_nome = "Fulano";
  m_sobrenome = "de Tal";
  m_saldo = 11;
  m_simplificar = true;

  m_usuario.setEmail(m_email);
  m_usuario.setSenha(m_senha);
  m_usuario.setIdade(m_idade);
  m_usuario.setNome(m_nome);
  m_usuario.setSobrenome(m_sobrenome);
  m_usuario.setSaldo(m_saldo);
  m_usuario.setSimplificar(m_simplificar);
}

void tst_usuario_dao::testInsertUsuario() {
  UsuarioDAO *usuarioDAO = DatabaseManager::instance().usuarioDAO();
  QCOMPARE(usuarioDAO->insertUsuario(m_usuario), true);
  usuarioDAO->removeUsuario(m_usuario.email());
}

void tst_usuario_dao::testRemoveUsuario() {
  UsuarioDAO *usuarioDAO = DatabaseManager::instance().usuarioDAO();
  usuarioDAO->insertUsuario(m_usuario);
  QCOMPARE(usuarioDAO->removeUsuario(m_usuario.email()), true);
}

void tst_usuario_dao::testRemoveAll() {
  UsuarioDAO *usuarioDAO = DatabaseManager::instance().usuarioDAO();

  // Utilizado para salvar os usuários para reinseri-los depois
  std::unique_ptr<std::vector<std::unique_ptr<Usuario>>> list(
      new std::vector<std::unique_ptr<Usuario>>());
  list = usuarioDAO->usuarios();

  QCOMPARE(usuarioDAO->removeAll(), true);

  for (unsigned long i = 0; i < list->size(); i++)
    usuarioDAO->insertUsuario(*(list->at(i)));
}

void tst_usuario_dao::testUsuarioCount() {
  UsuarioDAO *usuarioDAO = DatabaseManager::instance().usuarioDAO();

  // Utilizado para comparar o número de usuários
  std::unique_ptr<std::vector<std::unique_ptr<Usuario>>> list(
      new std::vector<std::unique_ptr<Usuario>>());
  list = usuarioDAO->usuarios();

  QCOMPARE(usuarioDAO->usuarioCount(), list->size());
}

void tst_usuario_dao::testAtualizarSenha() {
  UsuarioDAO *usuarioDAO = DatabaseManager::instance().usuarioDAO();
  usuarioDAO->insertUsuario(m_usuario);

  std::unique_ptr<std::vector<std::unique_ptr<Usuario>>> list(
      new std::vector<std::unique_ptr<Usuario>>());
  list = usuarioDAO->usuarios(m_email);

  QCOMPARE(list->at(0)->senha(), m_senha);

  usuarioDAO->atualizarSenha(m_usuario.email(), "09876");

  list->clear();
  list = usuarioDAO->usuarios(m_email);
  QCOMPARE(list->at(0)->senha(), "09876");

  usuarioDAO->removeUsuario(m_usuario.email());
}

void tst_usuario_dao::testAtualizarIdade() {
  UsuarioDAO *usuarioDAO = DatabaseManager::instance().usuarioDAO();
  usuarioDAO->insertUsuario(m_usuario);

  std::unique_ptr<std::vector<std::unique_ptr<Usuario>>> list(
      new std::vector<std::unique_ptr<Usuario>>());
  list = usuarioDAO->usuarios(m_email);

  QCOMPARE(list->at(0)->idade(), m_idade);

  usuarioDAO->atualizarIdade(m_usuario.email(), 18);

  list->clear();
  list = usuarioDAO->usuarios(m_email);
  QCOMPARE(list->at(0)->idade(), 18);

  usuarioDAO->removeUsuario(m_usuario.email());
}

void tst_usuario_dao::testAtualizarNome() {
  UsuarioDAO *usuarioDAO = DatabaseManager::instance().usuarioDAO();
  usuarioDAO->insertUsuario(m_usuario);

  std::unique_ptr<std::vector<std::unique_ptr<Usuario>>> list(
      new std::vector<std::unique_ptr<Usuario>>());
  list = usuarioDAO->usuarios(m_email);

  QCOMPARE(list->at(0)->nome(), m_nome);

  usuarioDAO->atualizarNome(m_usuario.email(), "Siclano");

  list->clear();
  list = usuarioDAO->usuarios(m_email);
  QCOMPARE(list->at(0)->nome(), "Siclano");

  usuarioDAO->removeUsuario(m_usuario.email());
}

void tst_usuario_dao::testAtualizarSobrenome() {
  UsuarioDAO *usuarioDAO = DatabaseManager::instance().usuarioDAO();
  usuarioDAO->insertUsuario(m_usuario);

  std::unique_ptr<std::vector<std::unique_ptr<Usuario>>> list(
      new std::vector<std::unique_ptr<Usuario>>());
  list = usuarioDAO->usuarios(m_email);

  QCOMPARE(list->at(0)->sobrenome(), m_sobrenome);

  usuarioDAO->atualizarSobrenome(m_usuario.email(), "Araujo");

  list->clear();
  list = usuarioDAO->usuarios(m_email);
  QCOMPARE(list->at(0)->sobrenome(), "Araujo");

  usuarioDAO->removeUsuario(m_usuario.email());
}

void tst_usuario_dao::testAtualizarSaldo() {
  UsuarioDAO *usuarioDAO = DatabaseManager::instance().usuarioDAO();
  usuarioDAO->insertUsuario(m_usuario);

  std::unique_ptr<std::vector<std::unique_ptr<Usuario>>> list(
      new std::vector<std::unique_ptr<Usuario>>());
  list = usuarioDAO->usuarios(m_email);

  QCOMPARE(list->at(0)->saldo(), m_saldo);

  usuarioDAO->atualizarSaldo(m_usuario.email(), 22);

  list->clear();
  list = usuarioDAO->usuarios(m_email);
  QCOMPARE(list->at(0)->saldo(), 22);

  usuarioDAO->removeUsuario(m_usuario.email());
}

void tst_usuario_dao::testAtualizarSimplificar() {
  UsuarioDAO *usuarioDAO = DatabaseManager::instance().usuarioDAO();
  usuarioDAO->insertUsuario(m_usuario);

  std::unique_ptr<std::vector<std::unique_ptr<Usuario>>> list(
      new std::vector<std::unique_ptr<Usuario>>());
  list = usuarioDAO->usuarios(m_email);

  QCOMPARE(list->at(0)->simplificar(), m_simplificar);

  usuarioDAO->atualizarSimplificar(m_usuario.email(), !m_simplificar);

  list->clear();
  list = usuarioDAO->usuarios(m_email);
  QCOMPARE(list->at(0)->simplificar(), !m_simplificar);

  usuarioDAO->removeUsuario(m_usuario.email());
}

void tst_usuario_dao::testGetSaldo() {
  UsuarioDAO *usuarioDAO = DatabaseManager::instance().usuarioDAO();
  usuarioDAO->insertUsuario(m_usuario);

  QCOMPARE(usuarioDAO->getSaldo(m_usuario.email()), m_saldo);

  usuarioDAO->removeUsuario(m_usuario.email());
}

void tst_usuario_dao::testGetSimplificar() {
  UsuarioDAO *usuarioDAO = DatabaseManager::instance().usuarioDAO();
  usuarioDAO->insertUsuario(m_usuario);

  QCOMPARE(usuarioDAO->getSimplificar(m_usuario.email()), m_simplificar);

  usuarioDAO->removeUsuario(m_usuario.email());
}
