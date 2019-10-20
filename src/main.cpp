#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "cadastrar_usuario.h"
#include "manejar_despesa.h"
#include "secao_usuario.h"
#include "salvar_usuario.h"
#include "perfil_usuario.h"
#include "grafico_categoria.h"

int main(int argc, char *argv[]) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QApplication app(argc, argv);

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

  // salvar_usuario->deleteSettings();

  engine.load(url);

  return app.exec();
}
