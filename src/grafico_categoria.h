#ifndef GRAFICOCATEGORIA_H
#define GRAFICOCATEGORIA_H

#include <QObject>

class GraficoCategoria : public QObject {
  Q_OBJECT

public:
  GraficoCategoria(QObject *parent = nullptr);

  Q_INVOKABLE void criarGrafico();

signals:
  void inserirCategoria(QString categoria, int valor);
  void apagarDados();
};

#endif // GRAFICOCATEGORIA_H
