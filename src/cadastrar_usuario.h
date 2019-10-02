#ifndef CADASTRARUSUARIO_H
#define CADASTRARUSUARIO_H

#include <QObject>

class CadastrarUsuario : public QObject {
  Q_OBJECT
public:
  CadastrarUsuario(QObject *parent = nullptr);

  Q_INVOKABLE bool inserirUsuario(QString email, QString senha, QString idade,
                                  QString nome, QString sobrenome,
                                  QString saldo); // retorna true se foi
                                                  // possível inserir o usuário
                                                  // e false e não foi possível

  Q_INVOKABLE bool usuarioExiste(QString email); // retorna true se o
                                                 // usuário já existe e
                                                 // false se não existe

  Q_INVOKABLE bool senhaCorreta(QString email, QString senha);
    //retorna true se o usuário do email passado como parâmetro tem como
    //senha a senha passada como parâmetro. Retorna false caso contrário
};

#endif // CADASTRARUSUARIO_H
