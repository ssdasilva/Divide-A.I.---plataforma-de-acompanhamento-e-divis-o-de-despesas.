#include "divida.h"

Divida::Divida(QObject *parent) : QObject(parent) {}

qint64 Divida::cpfDevedor() const { return m_cpfDevedor; }

void Divida::setCpfDevedor(const qint64 &cpfDevedor) {
  m_cpfDevedor = cpfDevedor;
}

qint64 Divida::cpfCredor() const { return m_cpfCredor; }

void Divida::setCpfCredor(const qint64 &cpfCredor) { m_cpfCredor = cpfCredor; }

int Divida::quantia() const { return m_quantia; }

void Divida::setQuantia(int quantia) { m_quantia = quantia; }

QString Divida::tipoMoeda() const { return m_tipoMoeda; }

void Divida::setTipoMoeda(const QString &tipoMoeda) { m_tipoMoeda = tipoMoeda; }

QString Divida::categoria() const { return m_categoria; }

void Divida::setCategoria(const QString &categoria) { m_categoria = categoria; }
