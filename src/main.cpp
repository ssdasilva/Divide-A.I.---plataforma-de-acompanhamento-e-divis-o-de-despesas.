#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "cadastrar_usuario.h"
#include "manejar_despesa.h"
#include "secao_usuario.h"
#include "salvar_usuario.h"
#include "perfil_usuario.h"
#include "grafico_categoria.h"
#include "tst_salvar_usuario.h"
#include "tst_manejar_despesa.h"
#include "tst_despesa_dao.h"
#include "tst_grupo.h"
#include "tst_grupo_dao.h"
#include "tst_perfil_usuario.h"

int main(int argc, char *argv[]) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QApplication app(argc, argv);

  tst_salvar_usuario test1;
  QTest::qExec(&test1);

  tst_manejar_despesa test2;
  QTest::qExec(&test2);

  tst_despesa_dao test3;
  QTest::qExec(&test3);

  tst_grupo test4;
  QTest::qExec(&test4);

  tst_grupo_dao test5;
  QTest::qExec(&test5);

  tst_perfil_usuario test6;
  QTest::qExec(&test6);

  QQmlApplicationEngine engine;
  const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
  QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                   &app, [url](QObject *obj, const QUrl &objUrl) {
                     if (!obj && url == objUrl)
                       QCoreApplication::exit(-1);
                   }, Qt::QueuedConnection);

  // Expõe o c++ para o qml
  CadastrarUsuario *cadastrarUsuario = new CadastrarUsuario();
  engine.rootContext()->setContextProperty("cadastrarUsuario",
                                           cadastrarUsuario);

  Secao_usuario *secaoUsuario = new Secao_usuario();
  engine.rootContext()->setContextProperty("secaoUsuario", secaoUsuario);

  Manejar_despesa *manejarDespesa = new Manejar_despesa();
  engine.rootContext()->setContextProperty("manejarDespesa", manejarDespesa);

  Salvar_usuario *salvar_usuario = new Salvar_usuario();
  engine.rootContext()->setContextProperty("salvar_usuario", salvar_usuario);

  PerfilUsuario *perfilUsuario = new PerfilUsuario();
  engine.rootContext()->setContextProperty("perfilUsuario", perfilUsuario);

  GraficoCategoria *graficoCategoria = new GraficoCategoria();
  engine.rootContext()->setContextProperty("graficoCategoria",
                                           graficoCategoria);

  engine.load(url);

  return app.exec();
}
