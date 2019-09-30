#include "divida.h"

Divida::Divida(QObject *parent) : QObject(parent) {}

QString Divida::emailDevedor() const { return m_emailDevedor; }

void Divida::setEmailDevedor(const QString &emailDevedor) {
  m_emailDevedor = emailDevedor;
}

QString Divida::emailCredor() const { return m_emailCredor; }

void Divida::setEmailCredor(const QString &emailCredor) {
  m_emailCredor = emailCredor;
}

int Divida::quantia() const { return m_quantia; }

void Divida::setQuantia(int quantia) { m_quantia = quantia; }

QString Divida::tipoMoeda() const { return m_tipoMoeda; }

void Divida::setTipoMoeda(const QString &tipoMoeda) { m_tipoMoeda = tipoMoeda; }

QString Divida::categoria() const { return m_categoria; }

void Divida::setCategoria(const QString &categoria) { m_categoria = categoria; }
