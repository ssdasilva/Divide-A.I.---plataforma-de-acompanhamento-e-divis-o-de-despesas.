#ifndef DESPESA_DAO_H
#define DESPESA_DAO_H

#include <memory>
#include <vector>

#include <QString>
#include <QMap>

class Despesa;

class DespesaDAO {
public:
  DespesaDAO() = default;

  bool insertDespesa(const Despesa &despesa) const;

  bool removeDespesa(const QString &email, const QString &descricao) const;

  bool removeTodasDespesasUsuario(const QString &email) const;

  bool removeAll() const;

  int despesaCount() const;

  int despesaCountUsuario(const QString &email) const;

  std::unique_ptr<std::vector<std::unique_ptr<Despesa>>>
  usuarios(const QString &email = QString()) const;

  bool atualizarQuantia(QString email, QString descricao, int quantia) const;

  QMap<QString, int> gastoPorCategoria(QString email);
};

#endif // DESPESA_DAO_H
