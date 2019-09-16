#include "divida_dao.h"
#include "divida.h"

#include <QSqlQuery>
#include <QVariant>

bool DividaDAO::init() const {
  QSqlQuery query;

  // Monta a query para criar a tabela caso ela ainda não exista
  return query.exec(QStringLiteral(
      "CREATE TABLE IF NOT EXISTS divida (cpfDevedor BIGINT NOT "
      "NULL, cpfCredor BIGINT NOT NULL, quantia INT NOT NULL, "
      "tipoMoeda VARCHAR(30), categoria VARCHAR(30), PRIMARY KEY(cpfDevedor, "
      "cpfCredor), FOREIGN KEY(cpfDevedor) REFERENCES usuario(CPF) ON DELETE "
      "CASCADE, FOREIGN KEY(cpfCredor) REFERENCES usuario(CPF) ON DELETE "
      "CASCADE"));
}

bool DividaDAO::insertDivida(const Divida &divida) const {
  QSqlQuery query;

  // Monta a query com o uso de REPLACE de tal forma que a divida será
  // inserida se não existir, caso contrário, será atualizada
  query.prepare(
      QStringLiteral("REPLACE INTO divida (cpfDevedor, cpfCredor, quantia, "
                     "tipoMoeda, categoria) VALUES (?, ?, ?, ?, ?)"));

  query.addBindValue(divida.cpfDevedor());
  query.addBindValue(divida.cpfCredor());
  query.addBindValue(divida.quantia());
  query.addBindValue(divida.tipoMoeda());
  query.addBindValue(divida.categoria());

  return query.exec();
}

bool DividaDAO::removeDivida(const qint64 &cpfDevedor,
                             const qint64 &cpfCredor) const {
  QSqlQuery query;

  query.prepare(QStringLiteral(
      "DELETE FROM divida WHERE cpfDevedor = ? AND cpfCredor = ?"));
  query.addBindValue(cpfDevedor);
  query.addBindValue(cpfCredor);

  return query.exec();
}

bool DividaDAO::removeAll() const {
  QSqlQuery query;

  query.prepare(QStringLiteral("DELETE FROM divida"));

  return query.exec();
}

int DividaDAO::dividaCount() const {
  QSqlQuery query;

  query.prepare(QStringLiteral("SELECT COUNT(*) FROM divida"));

  query.exec();

  if (query.next()) {
    return query.value(0).toInt();
  }

  return 0;
}

std::unique_ptr<std::vector<std::unique_ptr<Divida>>>
DividaDAO::usuarios(const qint64 &cpfDevedor, const qint64 &cpfCredor) const {
  QSqlQuery query;

  // Verifica se os codigos de divida foi especificado para decidir se deve
  // executar a query selecionando todas as dividas da tabela ou somente a
  // divida de código especificado
  if (cpfDevedor == -1 || cpfCredor == -1) {
    query.prepare(QStringLiteral("SELECT * FROM divida"));
  } else {
    query.prepare(QStringLiteral(
        "SELECT * FROM divida WHERE cpfDevedor = ? AND cpfCredor = ?"));
    query.addBindValue(cpfDevedor);
    query.addBindValue(cpfCredor);
  }

  query.exec();

  // Declara um vector que conterá os ponteiros de cada divida retornada
  // pela query
  std::unique_ptr<std::vector<std::unique_ptr<Divida>>> list(
      new std::vector<std::unique_ptr<Divida>>());

  while (query.next()) {
    std::unique_ptr<Divida> divida(new Divida());

    divida->setCpfDevedor(query.value(0).toInt());
    divida->setCpfCredor(query.value(1).toInt());
    divida->setQuantia(query.value(2).toInt());
    divida->setTipoMoeda(query.value(3).toString());
    divida->setCategoria(query.value(4).toString());

    // Move o unique_ptr<Divida> para a lista de tal forma que ele pertença
    // à lista e não ao escopo atual. Dessa forma 'divida' não será deletado
    // ao sair deste 'while'
    list->push_back(std::move(divida));
  }

  return list;
}
