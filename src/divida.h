#ifndef DIVIDA_H
#define DIVIDA_H

#include <QObject>

class Divida : public QObject {
  Q_OBJECT
public:
  explicit Divida(QObject *parent = nullptr);

  QString emailDevedor() const;
  void setEmailDevedor(const QString &emailDevedor);

  QString emailCredor() const;
  void setEmailCredor(const QString &emailCredor);

  int quantia() const;
  void setQuantia(int quantia);

  QString tipoMoeda() const;
  void setTipoMoeda(const QString &tipoMoeda);

  QString categoria() const;
  void setCategoria(const QString &categoria);

private:
  QString m_emailDevedor;

  QString m_emailCredor;

  int m_quantia;

  QString m_tipoMoeda;

  QString m_categoria;
};

#endif // DIVIDA_H
