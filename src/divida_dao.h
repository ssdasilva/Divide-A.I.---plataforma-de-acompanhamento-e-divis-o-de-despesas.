#ifndef DIVIDADAO_H
#define DIVIDADAO_H

#include <memory>
#include <vector>

#include <QString>

class Divida;

class DividaDAO {
public:
  DividaDAO() = default;

  bool init() const;

  bool insertDivida(const Divida &divida) const;

  bool removeDivida(const qint64 &cpfDevedor, const qint64 &cpfCredor) const;

  bool removeAll() const;

  int dividaCount() const;

  std::unique_ptr<std::vector<std::unique_ptr<Divida>>>
  usuarios(const qint64 &cpfDevedor = -1, const qint64 &cpfCredor = -1) const;
};

#endif // DIVIDADAO_H
