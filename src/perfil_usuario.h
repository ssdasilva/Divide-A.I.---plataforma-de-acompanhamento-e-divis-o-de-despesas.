#ifndef PEFILUSUARIO_H
#define PEFILUSUARIO_H

#include <QObject>
#include <QTimer>

class PerfilUsuario : public QObject {
  Q_OBJECT

public:
  PerfilUsuario(QObject *parent = nullptr);

  Q_INVOKABLE void init();

  Q_INVOKABLE QString email() const;

  Q_INVOKABLE QString idade() const;
  Q_INVOKABLE void setIdade(QString idade);

  Q_INVOKABLE QString nome() const;
  Q_INVOKABLE void setNome(QString nome);

  Q_INVOKABLE QString sobrenome() const;
  Q_INVOKABLE void setSobrenome(QString sobrenome);

  Q_INVOKABLE float saldo() const;

private slots:
  void setSaldo();

signals:
  void mudouPerfil();
  void mudouSaldo(float saldo);

private:
  QString m_email;
  qint8 m_idade;
  QString m_nome;
  QString m_sobrenome;
  float m_saldo;

  // Utilizado para verificar o saldo do usuário
  QTimer m_timer;
};

#endif // PEFILUSUARIO_H
