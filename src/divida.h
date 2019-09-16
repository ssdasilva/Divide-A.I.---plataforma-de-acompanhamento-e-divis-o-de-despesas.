#ifndef DIVIDA_H
#define DIVIDA_H

#include <QObject>

class Divida : public QObject {
  Q_OBJECT
public:
  explicit Divida(QObject *parent = nullptr);

  qint64 cpfDevedor() const;
  void setCpfDevedor(const qint64 &cpfDevedor);

  qint64 cpfCredor() const;
  void setCpfCredor(const qint64 &cpfCredor);

  int quantia() const;
  void setQuantia(int quantia);

  QString tipoMoeda() const;
  void setTipoMoeda(const QString &tipoMoeda);

  QString categoria() const;
  void setCategoria(const QString &categoria);

private:
  qint64 m_cpfDevedor;

  qint64 m_cpfCredor;

  int m_quantia;

  QString m_tipoMoeda;

  QString m_categoria;
};

#endif // DIVIDA_H
