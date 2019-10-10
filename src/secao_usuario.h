#ifndef SECAO_USUARIO_H
#define SECAO_USUARIO_H

#include <QObject>

class Secao_usuario : public QObject {
    Q_OBJECT
public:
    Secao_usuario(QObject *parent = nullptr);

    Q_INVOKABLE QString getEmailLogado() const;
    Q_INVOKABLE void setEmailLogado(const QString &value);

private:
    QString emailLogado;
};

#endif // SECAO_USUARIO_H
