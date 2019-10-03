#include "perfil_usuario.h"
#include "usuario.h"
#include "usuario_dao.h"
#include "database_manager.h"
#include "salvar_usuario.h"

#include <QDebug>

PerfilUsuario::PerfilUsuario(QObject *parent) : QObject(parent) {}

void PerfilUsuario::init() {
  UsuarioDAO *usuarioDAO = DatabaseManager::instance().usuarioDAO();

  std::unique_ptr<std::vector<std::unique_ptr<Usuario>>> list(
      new std::vector<std::unique_ptr<Usuario>>());

  Salvar_usuario salvarUsuario;

  QString email = salvarUsuario.loadEmail();

  list = usuarioDAO->usuarios(email);

  if (list->size() > 0) {
    m_email = list->at(0)->email();
    m_idade = list->at(0)->idade();
    m_nome = list->at(0)->nome();
    m_sobrenome = list->at(0)->sobrenome();
    m_saldo = list->at(0)->saldo();
  } else
    qDebug() << "Erro no perfil usuário --> não achou usuário";

  // Utilizado par atualizar o saldo a cada 10 minutos
  connect(&m_timer, SIGNAL(timeout), this, SLOT(setSaldo()));
  m_timer.start(600000);

  emit mudouPerfil();
}

QString PerfilUsuario::email() const { return m_email; }

QString PerfilUsuario::idade() const { return QString::number(m_idade); }

void PerfilUsuario::setIdade(QString idade) {
  m_idade = idade.toInt();

  UsuarioDAO *usuarioDAO = DatabaseManager::instance().usuarioDAO();

  usuarioDAO->atualizarIdade(m_email, m_idade);
}

QString PerfilUsuario::nome() const { return m_nome; }

void PerfilUsuario::setNome(QString nome) {
  m_nome = nome;

  UsuarioDAO *usuarioDAO = DatabaseManager::instance().usuarioDAO();

  usuarioDAO->atualizarNome(m_email, m_nome);
}

QString PerfilUsuario::sobrenome() const { return m_sobrenome; }

void PerfilUsuario::setSobrenome(QString sobrenome) {
  m_sobrenome = sobrenome;
  UsuarioDAO *usuarioDAO = DatabaseManager::instance().usuarioDAO();

  usuarioDAO->atualizarSobrenome(m_email, m_sobrenome);
}

float PerfilUsuario::saldo() const { return m_saldo; }

void PerfilUsuario::setSaldo() {
  UsuarioDAO *usuarioDAO = DatabaseManager::instance().usuarioDAO();

  m_saldo = usuarioDAO->getSaldo(m_email);

  emit mudouSaldo(m_saldo);
}
