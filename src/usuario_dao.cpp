#include "usuario_dao.h"
#include "usuario.h"

#include <QSqlQuery>
#include <QVariant>

#include "QDebug"

bool UsuarioDAO::insertUsuario(const Usuario &usuario) const {
  QSqlQuery query;

  // Monta a query com o uso de REPLACE de tal forma que o usuário será
  // inserido se não existir, caso contrário, será atualizado
  query.prepare(QStringLiteral(
      "INSERT INTO usuario (email, senha, idade, nome, sobrenome, saldo, simplificar) "
      "VALUES (?, ?, ?, ?, ?, ?, ?)"));

  query.addBindValue(usuario.email());
  query.addBindValue(usuario.senha());
  query.addBindValue(usuario.idade());
  query.addBindValue(usuario.nome());
  query.addBindValue(usuario.sobrenome());
  query.addBindValue(usuario.saldo());
  query.addBindValue(usuario.simplificar());

  return query.exec();
}

bool UsuarioDAO::removeUsuario(const QString &email) const {
  QSqlQuery query;

  query.prepare(QStringLiteral("DELETE FROM usuario WHERE email = ?"));
  query.addBindValue(email);

  return query.exec();
}

bool UsuarioDAO::removeAll() const {
  QSqlQuery query;

  query.prepare(QStringLiteral("DELETE FROM usuario"));

  return query.exec();
}

int UsuarioDAO::usuarioCount() const {
  QSqlQuery query;

  query.prepare(QStringLiteral("SELECT COUNT(*) FROM usuario"));

  query.exec();

  if (query.next()) {
    return query.value(0).toInt();
  }

  return 0;
}

std::unique_ptr<std::vector<std::unique_ptr<Usuario>>>
UsuarioDAO::usuarios(const QString &email) const {
  QSqlQuery query;

  // Verifica se um código de usuário foi especificado para decidir se deve
  // executar a query selecionando todos os usuários da tabela ou somente o
  // usuário de código especificado
  if (email.isEmpty()) {
    query.prepare(QStringLiteral("SELECT * FROM usuario"));
  } else {
    query.prepare(QStringLiteral("SELECT * FROM usuario WHERE email = ?"));
    query.addBindValue(email);
  }

  query.exec();

  // Declara um vector que conterá os ponteiros de cada usuário retornado
  // pela query
  std::unique_ptr<std::vector<std::unique_ptr<Usuario>>> list(
      new std::vector<std::unique_ptr<Usuario>>());

  while (query.next()) {
    std::unique_ptr<Usuario> usuario(new Usuario());

    usuario->setEmail(query.value(0).toString());
    usuario->setSenha(query.value(1).toString());
    usuario->setNome(query.value(2).toString());
    usuario->setSobrenome(query.value(3).toString());
    usuario->setIdade(query.value(4).toInt());
    usuario->setSaldo(query.value(5).toFloat());
    usuario->setSimplificar(query.value(6).toBool());

    // Move o unique_ptr<Usuario> para a lista de tal forma que ele pertença
    // à lista e não ao escopo atual. Dessa forma 'usuario' não será deletado
    // ao sair deste 'while'
    list->push_back(std::move(usuario));
  }

  return list;
}

bool UsuarioDAO::atualizarSenha(const QString &email,
                                const QString &senha) const {
  QSqlQuery query;

  query.prepare(QStringLiteral("UPDATE usuario SET senha = ? WHERE email = ?"));
  query.addBindValue(senha);
  query.addBindValue(email);

  return query.exec();
}

bool UsuarioDAO::atualizarIdade(const QString &email,
                                const qint8 &idade) const {
  QSqlQuery query;

  query.prepare(QStringLiteral("UPDATE usuario SET idade = ? WHERE email = ?"));
  query.addBindValue(idade);
  query.addBindValue(email);

  return query.exec();
}

bool UsuarioDAO::atualizarNome(const QString &email,
                               const QString &nome) const {
  QSqlQuery query;

  query.prepare(QStringLiteral("UPDATE usuario SET nome = ? WHERE email = ?"));
  query.addBindValue(nome);
  query.addBindValue(email);

  return query.exec();
}

bool UsuarioDAO::atualizarSobrenome(const QString &email,
                                    const QString &sobrenome) const {
  QSqlQuery query;

  query.prepare(
      QStringLiteral("UPDATE usuario SET sobrenome = ? WHERE email = ?"));
  query.addBindValue(sobrenome);
  query.addBindValue(email);

  return query.exec();
}

bool UsuarioDAO::atualizarSaldo(const QString &email, float saldo) const {
  QSqlQuery query;

  query.prepare(QStringLiteral("UPDATE usuario SET saldo = ? WHERE email = ?"));
  query.addBindValue(saldo);
  query.addBindValue(email);

  return query.exec();
}

bool UsuarioDAO::atualizarSimplificar(const QString &email, bool simplificar) const {
  QSqlQuery query;

  query.prepare(QStringLiteral("UPDATE usuario SET simplificar = ? WHERE email = ?"));
  query.addBindValue(simplificar);
  query.addBindValue(email);

  return query.exec();
}

float UsuarioDAO::getSaldo(const QString &email) const {
  QSqlQuery query;

  query.prepare(QStringLiteral("SELECT saldo FROM usuario WHERE email = ?"));
  query.addBindValue(email);

  return query.exec();
}

bool UsuarioDAO::getSimplificar(const QString &email) const
{
    QSqlQuery query;

    query.prepare(QStringLiteral("SELECT simplificar FROM usuario WHERE email = ?"));
    query.addBindValue(email);

    return query.exec();
}
