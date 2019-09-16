#include "usuario_dao.h"
#include "usuario.h"

#include <QSqlQuery>
#include <QVariant>

bool UsuarioDAO::init() const {
  QSqlQuery query;

  // Monta a query para criar a tabela caso ela ainda não exista
  return query.exec(
      QStringLiteral("CREATE TABLE IF NOT EXISTS usuario (CPF BIGINT"
                     "NOT NULL, idade TINYINT, nome VARCHAR(30),"
                     "sobrenome VARCHAR(50), saldo FLOAT,"
                     "PRIMARY KEY (CPF))"));
}

bool UsuarioDAO::insertUsuario(const Usuario &usuario) const {
  QSqlQuery query;

  // Monta a query com o uso de REPLACE de tal forma que o usuário será
  // inserido se não existir, caso contrário, será atualizado
  query.prepare(QStringLiteral(
      "REPLACE INTO usuario (CPF, idade, nome, sobrenome, saldo) "
      "VALUES (?, ?, ?, ?, ?)"));

  query.addBindValue(usuario.CPF());
  query.addBindValue(usuario.idade());
  query.addBindValue(usuario.nome());
  query.addBindValue(usuario.sobrenome());
  query.addBindValue(usuario.saldo());

  return query.exec();
}

bool UsuarioDAO::removeUsuario(const qint64 &CPF) const {
  QSqlQuery query;

  query.prepare(QStringLiteral("DELETE FROM usuario WHERE CPF = ?"));
  query.addBindValue(CPF);

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
UsuarioDAO::usuarios(const quint64 &CPF) const {
  QSqlQuery query;

  // Verifica se um código de usuário foi especificado para decidir se deve
  // executar a query selecionando todos os usuários da tabela ou somente o
  // usuário de código especificado
  if (CPF == 0) {
    query.prepare(QStringLiteral("SELECT * FROM usuario"));
  } else {
    query.prepare(QStringLiteral("SELECT * FROM usuario WHERE CPF = ?"));
    query.addBindValue(CPF);
  }

  query.exec();

  // Declara um vector que conterá os ponteiros de cada usuário retornado
  // pela query
  std::unique_ptr<std::vector<std::unique_ptr<Usuario>>> list(
      new std::vector<std::unique_ptr<Usuario>>());

  while (query.next()) {
    std::unique_ptr<Usuario> usuario(new Usuario());

    usuario->setCPF(query.value(0).toInt());
    usuario->setIdade(query.value(1).toInt());
    usuario->setNome(query.value(2).toString());
    usuario->setSobrenome(query.value(3).toString());
    usuario->setSaldo(query.value(4).toFloat());

    // Move o unique_ptr<Usuario> para a lista de tal forma que ele pertença
    // à lista e não ao escopo atual. Dessa forma 'usuario' não será deletado
    // ao sair deste 'while'
    list->push_back(std::move(usuario));
  }

  return list;
}
