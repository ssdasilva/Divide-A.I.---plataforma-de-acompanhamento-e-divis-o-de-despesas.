#ifndef USUARIO_H
#define USUARIO_H

#include <QObject>

class Usuario : public QObject {
  Q_OBJECT

public:
  explicit Usuario(QObject *parent = nullptr);

  qint64 CPF() const;
  void setCPF(const qint64 &CPF);

  qint8 idade() const;
  void setIdade(const qint8 &idade);

  QString nome() const;
  void setNome(const QString &nome);

  QString sobrenome() const;
  void setSobrenome(const QString &sobrenome);

  float saldo() const;
  void setSaldo(float saldo);

private:
  qint64 m_CPF;

  qint8 m_idade;

  QString m_nome;

  QString m_sobrenome;

  float m_saldo;
};

#endif // USUARIO_H