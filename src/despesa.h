#ifndef DESPESA_H
#define DESPESA_H

#include <QObject>

class Despesa : public QObject {
    Q_OBJECT
public:
    explicit Despesa(QObject *parent = nullptr);

    QString getEmail() const;
    void setEmail(const QString &value);

    QString getDescricao() const;
    void setDescricao(const QString &value);

    QString getData() const;
    void setData(const QString &value);

    QString getCategoria() const;
    void setCategoria(const QString &value);

    QString getFrequencia() const;
    void setFrequencia(const QString &value);

    qint8 getQuantia() const;
    void setQuantia(const qint8 &value);

private:
    QString email;
    QString descricao;
    QString data;
    QString categoria;
    QString frequencia;
    qint8 quantia;
};

#endif // DESPESA_H
