#ifndef GRUPO_H
#define GRUPO_H

#include <QObject>

class Grupo : public QObject {
  Q_OBJECT
public:
  explicit Grupo(QObject *parent = nullptr);

  QString identificador() const;
  void setIdentificador(const QString &identificador);

  QString nome() const;
  void setNome(const QString &nome);

  int numPessoas() const;
  void setNumPessoas(int numPessoas);

private:
  QString m_identificador;

  QString m_nome;

  int m_numPessoas = 0;
};

#endif // GRUPO_H
