#include "grupo.h"

Grupo::Grupo(QObject *parent) : QObject(parent) {}

QString Grupo::identificador() const { return m_identificador; }

void Grupo::setIdentificador(const QString &identificador) {
  m_identificador = identificador;
}

QString Grupo::nome() const { return m_nome; }

void Grupo::setNome(const QString &nome) { m_nome = nome; }

int Grupo::numPessoas() const { return m_numPessoas; }

void Grupo::setNumPessoas(int numPessoas) { m_numPessoas = numPessoas; }
