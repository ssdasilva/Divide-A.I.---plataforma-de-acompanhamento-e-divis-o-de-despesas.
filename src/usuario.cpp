#include "usuario.h"

Usuario::Usuario(QObject *parent) : QObject(parent) {}

qint64 Usuario::CPF() const { return m_CPF; }

void Usuario::setCPF(const qint64 &CPF) { m_CPF = CPF; }

qint8 Usuario::idade() const { return m_idade; }

void Usuario::setIdade(const qint8 &idade) { m_idade = idade; }

QString Usuario::nome() const { return m_nome; }

void Usuario::setNome(const QString &nome) { m_nome = nome; }

QString Usuario::sobrenome() const { return m_sobrenome; }

void Usuario::setSobrenome(const QString &sobrenome) {
  m_sobrenome = sobrenome;
}

float Usuario::saldo() const { return m_saldo; }

void Usuario::setSaldo(float saldo) { m_saldo = saldo; }
