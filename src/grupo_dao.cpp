#include "grupo_dao.h"
#include "grupo.h"

#include <QSqlQuery>
#include <QVariant>

bool GrupoDAO::insertGrupo(const Grupo &grupo) const {
  QSqlQuery query;

  // Monta a query com o uso de REPLACE de tal forma que o grupo será
  // inserido se não existir, caso contrário, será atualizado
  query.prepare(QStringLiteral(
      "INSERT INTO grupo (identificador, nome, numPessoas) VALUES (?, ?, ?)"));

  query.addBindValue(grupo.identificador());
  query.addBindValue(grupo.nome());
  query.addBindValue(grupo.numPessoas());

  return query.exec();
}

bool GrupoDAO::removeGrupo(const QString &identificador) const {
  QSqlQuery query;

  query.prepare(QStringLiteral("DELETE FROM grupo WHERE identificador = ?"));
  query.addBindValue(identificador);

  return query.exec();
}

bool GrupoDAO::removeAll() const {
  QSqlQuery query;

  query.prepare(QStringLiteral("DELETE FROM grupo"));

  return query.exec();
}

int GrupoDAO::grupoCount() const {
  QSqlQuery query;

  query.prepare(QStringLiteral("SELECT COUNT(*) FROM grupo"));

  query.exec();

  if (query.next()) {
    return query.value(0).toInt();
  }

  return 0;
}

std::unique_ptr<std::vector<std::unique_ptr<Grupo>>>
GrupoDAO::usuarios(const QString &identificador) const {
  QSqlQuery query;

  // Verifica se um código de grupo foi especificado para decidir se deve
  // executar a query selecionando todos os grupos da tabela ou somente o
  // grupo de código especificado
  if (identificador.isEmpty()) {
    query.prepare(QStringLiteral("SELECT * FROM grupo"));
  } else {
    query.prepare(
        QStringLiteral("SELECT * FROM grupo WHERE identificador = ?"));
    query.addBindValue(identificador);
  }

  query.exec();

  // Declara um vector que conterá os ponteiros de cada grupo retornado
  // pela query
  std::unique_ptr<std::vector<std::unique_ptr<Grupo>>> list(
      new std::vector<std::unique_ptr<Grupo>>());

  while (query.next()) {
    std::unique_ptr<Grupo> grupo(new Grupo());

    grupo->setIdentificador(query.value(0).toString());
    grupo->setNome(query.value(1).toString());
    grupo->setNumPessoas(query.value(2).toInt());

    // Move o unique_ptr<Grupo> para a lista de tal forma que ele pertença
    // à lista e não ao escopo atual. Dessa forma 'grupo' não será deletado
    // ao sair deste 'while'
    list->push_back(std::move(grupo));
  }

  return list;
}

bool GrupoDAO::adicionarUmaPessoaAoGrupo(const QString &identificador) const {
  QSqlQuery query;

  query.prepare(QStringLiteral(
      "UPDATE grupo SET numPessoas = numPessoas + 1 WHERE identificador = ?"));
  query.addBindValue(identificador);

  return query.exec();
}
