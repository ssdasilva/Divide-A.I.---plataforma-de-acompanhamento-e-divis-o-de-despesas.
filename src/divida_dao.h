#ifndef DIVIDADAO_H
#define DIVIDADAO_H

#include <memory>
#include <vector>

#include <QString>

class Divida;

class DividaDAO {
public:
  DividaDAO() = default;

  bool insertDivida(const Divida &divida) const;

  bool removeDivida(const QString &emailDevedor,
                    const QString &emailCredor) const;

  bool removeAll() const;

  int dividaCount() const;

  std::unique_ptr<std::vector<std::unique_ptr<Divida>>>
  usuarios(const QString &emailDevedor = QString(),
           const QString &emailCredor = QString()) const;

  bool atualizarQuantia(QString emailDevedor, QString emailCredor,
                        int quantia) const;
};

#endif // DIVIDADAO_H
