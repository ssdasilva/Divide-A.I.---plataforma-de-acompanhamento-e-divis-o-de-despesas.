#ifndef SALVAR_USUARIO_H
#define SALVAR_USUARIO_H

#include <QObject>

class Salvar_usuario : public QObject {
    Q_OBJECT
public:
    Salvar_usuario(QObject *parent = nullptr);

    Q_INVOKABLE QString loadEmail();
    Q_INVOKABLE QString loadPassword();
    Q_INVOKABLE void save(const QString &email, const QString &senha);
    Q_INVOKABLE void deleteSettings();
private:
    QString aplication;
    QString organization;
    QString group_name;
};

#endif // SALVAR_USUARIO_H
