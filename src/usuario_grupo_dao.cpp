#include "usuario_grupo_dao.h"
#include "usuario_grupo.h"

#include <QSqlQuery>
#include <QVariant>

bool UsuarioGrupoDAO::insertUsuarioGrupo(
    const UsuarioGrupo &usuarioGrupo) const {
  QSqlQuery query;

  // Monta a query com o uso de REPLACE de tal forma que o usuárioGrupo será
  // inserido se não existir, caso contrário, será atualizado
  query.prepare(
      QStringLiteral("INSERT INTO usuarioGrupo (email, identificador) "
                     "VALUES (?, ?)"));

  query.addBindValue(usuarioGrupo.emailUsuario());
  query.addBindValue(usuarioGrupo.identificadorGrupo());

  return query.exec();
}

bool UsuarioGrupoDAO::removeUsuarioGrupo(
    const QString &emailUsuario, const QString &identificadorGrupo) const {
  QSqlQuery query;

  query.prepare(QStringLiteral(
      "DELETE FROM usuarioGrupo WHERE email = ? AND identificador = ?"));
  query.addBindValue(emailUsuario);
  query.addBindValue(identificadorGrupo);

  return query.exec();
}

bool UsuarioGrupoDAO::removeAll() const {
  QSqlQuery query;

  query.prepare(QStringLiteral("DELETE FROM usuarioGrupo"));

  return query.exec();
}

int UsuarioGrupoDAO::usuarioGrupoCount() const {
  QSqlQuery query;

  query.prepare(QStringLiteral("SELECT COUNT(*) FROM usuarioGrupo"));

  query.exec();

  if (query.next()) {
    return query.value(0).toInt();
  }

  return 0;
}

std::unique_ptr<std::vector<std::unique_ptr<UsuarioGrupo>>>
UsuarioGrupoDAO::usuarioGrupos(const QString &emailUsuario,
                               const QString &identificadorGrupo) const {
  QSqlQuery query;

  // Verifica se um código de usuário foi especificado para decidir se deve
  // executar a query selecionando todos os usuários da tabela ou somente o
  // usuário de código especificado
  if (emailUsuario.isEmpty() && identificadorGrupo.isEmpty()) {
    query.prepare(QStringLiteral("SELECT * FROM usuarioGrupo"));
  } else if (emailUsuario.isEmpty()) {
    query.prepare(
        QStringLiteral("SELECT * FROM usuarioGrupo WHERE identificador = ?"));
    query.addBindValue(identificadorGrupo);
  } else if (identificadorGrupo.isEmpty()) {
    query.prepare(QStringLiteral("SELECT * FROM usuarioGrupo WHERE email = ?"));
    query.addBindValue(emailUsuario);
  } else {
    query.prepare(QStringLiteral(
        "SELECT * FROM usuario WHERE email = ? AND indentificador = ?"));
    query.addBindValue(emailUsuario);
    query.addBindValue(identificadorGrupo);
  }

  query.exec();

  // Declara um vector que conterá os ponteiros de cada usuário retornado
  // pela query
  std::unique_ptr<std::vector<std::unique_ptr<UsuarioGrupo>>> list(
      new std::vector<std::unique_ptr<UsuarioGrupo>>());

  while (query.next()) {
    std::unique_ptr<UsuarioGrupo> usuarioGrupo(new UsuarioGrupo());

    usuarioGrupo->setEmailUsuario(query.value(0).toString());
    usuarioGrupo->setIdentificadorGrupo(query.value(1).toString());

    // Move o unique_ptr<Usuario> para a lista de tal forma que ele pertença
    // à lista e não ao escopo atual. Dessa forma 'usuario' não será deletado
    // ao sair deste 'while'
    list->push_back(std::move(usuarioGrupo));
  }

  return list;
}
