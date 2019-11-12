#include <QObject>
#include <QtTest/QtTest>
#include "usuario.h"

#ifndef TST_USUARIO_H
#define TST_USUARIO_H

class tst_usuario : public QObject {
  Q_OBJECT
public:
  tst_usuario();

private:
  Usuario *usuario;

private slots:
  void initTestCase();
  void testEmail();
  void testIdade();
  void testNome();
  void testSobrenome();
  void testSaldo();
  void testSimplificar();
};

#endif // TST_USUARIO_H
