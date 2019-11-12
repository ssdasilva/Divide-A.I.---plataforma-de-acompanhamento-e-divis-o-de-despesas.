#include <QObject>
#include <QDebug>
#include <QtTest/QtTest>
#include "usuario.h"

#ifndef TST_USUARIO_DAO_H
#define TST_USUARIO_DAO_H

class tst_usuario_dao : public QObject {
  Q_OBJECT

public:
  tst_usuario_dao();

private:
  QString m_email;
  QString m_senha;
  qint8 m_idade;
  QString m_nome;
  QString m_sobrenome;
  float m_saldo;
  bool m_simplificar;

  Usuario m_usuario;

private slots:
  void initTestCase();
  void testInsertUsuario();
  void testRemoveUsuario();
  void testRemoveAll();
  void testUsuarioCount();
  void testAtualizarSenha();
  void testAtualizarIdade();
  void testAtualizarNome();
  void testAtualizarSobrenome();
  void testAtualizarSaldo();
  void testAtualizarSimplificar();
  void testGetSaldo();
  void testGetSimplificar();
};

#endif // TST_USUARIO_DAO_H
