#ifndef DESPESA_DAO_H
#define DESPESA_DAO_H

#include <memory>
#include <vector>

#include <QString>

class Despesa;

class DespesaDAO {
public:
    DespesaDAO() = default;

    bool insertDespesa(const Despesa &divida) const;

    bool removeDespesa(const QString &email,
                       const QString &descricao) const;

    bool removeAll() const;

    bool removeAllUsuario(const QString &email) const;

    int despesaCount() const;

    qint8 despesaCountUsuario(const QString &email) const;

    std::unique_ptr<std::vector<std::unique_ptr<Despesa>>>
    usuarios(const QString &email = QString()) const;

    bool atualizarQuantia(QString email, QString descricao,
                          int quantia) const;
};

#endif // DESPESA_DAO_H
