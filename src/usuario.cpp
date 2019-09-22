#include "usuario.h"

Usuario::Usuario(QObject *parent) : QObject(parent) {}

QString Usuario::email() const { return m_email; }

void Usuario::setEmail(const QString &email) { m_email = email; }

QString Usuario::senha() const { return m_senha; }

void Usuario::setSenha(const QString &senha) { m_senha = senha; }

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
