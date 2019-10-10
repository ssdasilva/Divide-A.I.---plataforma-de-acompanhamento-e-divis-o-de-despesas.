#include "despesa_dao.h"
#include "despesa.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

bool DespesaDAO::insertDespesa(const Despesa &divida) const {
    QSqlQuery query;

    // Monta a query com o uso de REPLACE de tal forma que a despesa será
    // inserida se não existir, caso contrário, será atualizada
    query.prepare( QStringLiteral(
        "INSERT INTO despesa (email, descricao, data, "
        "moeda, categoria, frequencia, quantia) "
        "VALUES (?, ?, ?, ?, ?, ?, ?)"));

    query.addBindValue(divida.getEmail());
    query.addBindValue(divida.getDescricao());
    query.addBindValue(divida.getData());
    query.addBindValue(divida.getMoeda());
    query.addBindValue(divida.getCategoria());
    query.addBindValue(divida.getFrequencia());
    query.addBindValue(divida.getQuantia());

    qDebug() << query.lastQuery();

    bool x = query.exec();

    qDebug() << query.lastError().text();

    return x;
}

bool DespesaDAO::removeDespesa(const QString &email,
                   const QString &descricao) const {
    QSqlQuery query;

    query.prepare(QStringLiteral(
        "DELETE FROM despesa WHERE email = ? AND descricao = ?"));
    query.addBindValue(email);
    query.addBindValue(descricao);

    return query.exec();
}

bool DespesaDAO::removeAll() const {
    QSqlQuery query;

    query.prepare(QStringLiteral("DELETE FROM despesa"));

    return query.exec();
}

bool DespesaDAO::removeAllUsuario(const QString &email) const {
    QSqlQuery query;

    query.prepare(QStringLiteral(
        "DELETE FROM divida WHERE email = ?"));
    query.addBindValue(email);

    return query.exec();
}


int DespesaDAO::despesaCount() const{
    QSqlQuery query;

    query.prepare(QStringLiteral("SELECT COUNT(*) FROM despesa"));

    query.exec();

    if (query.next()) {
      return query.value(0).toInt();
    }

    return 0;
}

qint8 DespesaDAO::despesaCountUsuario(const QString &email) const{
    QSqlQuery query;

    query.prepare(QStringLiteral(
        "SELECT COUNT(*) FROM despesa WHERE email = ?"));
    query.addBindValue(email);

    query.exec();

    if (query.next()) {
      return query.value(0).toInt();
    }

    return 0;
}

std::unique_ptr<std::vector<std::unique_ptr<Despesa>>>
DespesaDAO::usuarios(const QString &email) const{
    QSqlQuery query;

    // Verifica se os codigos de despesa foi especificado para decidir se deve
    // executar a query selecionando todas as dividas da tabela ou somente a
    // divida de código especificado
    if (email.isEmpty()) {
      query.prepare(QStringLiteral("SELECT * FROM despesa"));
    } else {
      query.prepare(QStringLiteral(
          "SELECT * FROM divida WHERE email = ?"));
      query.addBindValue(email);
    }

    query.exec();

    // Declara um vector que conterá os ponteiros de cada divida retornada
    // pela query
    std::unique_ptr<std::vector<std::unique_ptr<Despesa>>> list(
        new std::vector<std::unique_ptr<Despesa>>());

    while (query.next()) {
      std::unique_ptr<Despesa> despesa(new Despesa());

      despesa->setEmail(query.value(0).toString());
      despesa->setDescricao(query.value(1).toString());
      despesa->setData(query.value(2).toString());
      despesa->setMoeda(query.value(3).toString());
      despesa->setCategoria(query.value(4).toString());
      despesa->setFrequencia(query.value(5).toString());
      despesa->setQuantia(query.value(6).toInt());

      // Move o unique_ptr<Divida> para a lista de tal forma que ele pertença
      // à lista e não ao escopo atual. Dessa forma 'divida' não será deletado
      // ao sair deste 'while'
      list->push_back(std::move(despesa));
    }

    return list;
}

bool DespesaDAO::atualizarQuantia(QString email, QString descricao, int quantia) const {
    QSqlQuery query;

    query.prepare(QStringLiteral("UPDATE despesa SET quantia = ? WHERE "
                                 "email = ? AND descricao = ?"));
    query.addBindValue(quantia);
    query.addBindValue(email);
    query.addBindValue(descricao);

    return query.exec();
}
