#include "divida_dao.h"
#include "divida.h"

#include <QSqlQuery>
#include <QVariant>

bool DividaDAO::insertDivida(const Divida &divida) const {
  QSqlQuery query;

  // Monta a query com o uso de REPLACE de tal forma que a divida será
  // inserida se não existir, caso contrário, será atualizada
  query.prepare(
      QStringLiteral("INSERT INTO divida (email_devedor, email_credor, quantia, "
                     "tipo_moeda, categoria) VALUES (?, ?, ?, ?, ?)"));

  query.addBindValue(divida.emailDevedor());
  query.addBindValue(divida.emailCredor());
  query.addBindValue(divida.quantia());
  query.addBindValue(divida.tipoMoeda());
  query.addBindValue(divida.categoria());

  return query.exec();
}

bool DividaDAO::removeDivida(const QString &emailDevedor,
                             const QString &emailCredor) const {
  QSqlQuery query;

  query.prepare(QStringLiteral(
      "DELETE FROM divida WHERE email_devedor = ? AND email_credor = ?"));
  query.addBindValue(emailDevedor);
  query.addBindValue(emailCredor);

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
DividaDAO::usuarios(const QString &emailDevedor,
                    const QString &emailCredor) const {
  QSqlQuery query;

  // Verifica se os codigos de divida foi especificado para decidir se deve
  // executar a query selecionando todas as dividas da tabela ou somente a
  // divida de código especificado
  if (emailDevedor.isEmpty() && emailCredor.isEmpty()) {
    query.prepare(QStringLiteral("SELECT * FROM divida"));
  } else if (emailCredor.isEmpty()) {
    query.prepare(
        QStringLiteral("SELECT * FROM divida WHERE email_devedor = ?"));
    query.addBindValue(emailDevedor);
  } else if (emailDevedor.isEmpty()) {
    query.prepare(QStringLiteral("SELECT * FROM divida WHERE email_credor = ?"));
    query.addBindValue(emailCredor);
  } else {
    query.prepare(QStringLiteral(
        "SELECT * FROM divida WHERE email_devedor = ? AND email_credor = ?"));
    query.addBindValue(emailDevedor);
    query.addBindValue(emailCredor);
  }

  query.exec();

  // Declara um vector que conterá os ponteiros de cada divida retornada
  // pela query
  std::unique_ptr<std::vector<std::unique_ptr<Divida>>> list(
      new std::vector<std::unique_ptr<Divida>>());

  while (query.next()) {
    std::unique_ptr<Divida> divida(new Divida());

    divida->setEmailDevedor(query.value(0).toString());
    divida->setEmailCredor(query.value(1).toString());
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

bool DividaDAO::atualizarQuantia(QString emailDevedor, QString emailCredor,
                                 int quantia) const {
  QSqlQuery query;

  query.prepare(QStringLiteral("UPDATE divida SET quantia = ? WHERE "
                               "email_devedor = ? AND email_credor = ?"));
  query.addBindValue(quantia);
  query.addBindValue(emailDevedor);
  query.addBindValue(emailCredor);

  return query.exec();
}
