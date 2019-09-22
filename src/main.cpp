#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "cadastrar_usuario.h"

int main(int argc, char *argv[]) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
  QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                   &app, [url](QObject *obj, const QUrl &objUrl) {
                     if (!obj && url == objUrl)
                       QCoreApplication::exit(-1);
                   }, Qt::QueuedConnection);
  engine.load(url);

  // Expõe o c++ para o qml
  CadastrarUsuario *cadastrarUsuario = new CadastrarUsuario();
  engine.rootContext()->setContextProperty("cadastrarUsuario",
                                           cadastrarUsuario);

  return app.exec();
}
