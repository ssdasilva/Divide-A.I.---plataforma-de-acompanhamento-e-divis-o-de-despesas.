#include "despesa.h"

Despesa::Despesa(QObject *parent) : QObject(parent) {}

QString Despesa::getEmail() const { return email; }
void Despesa::setEmail(const QString &value) { email = value; }

QString Despesa::getDescricao() const { return descricao; }
void Despesa::setDescricao(const QString &value) { descricao = value; }

QString Despesa::getData() const { return data; }
void Despesa::setData(const QString &value) { data = value; }

QString Despesa::getMoeda() const { return moeda; }
void Despesa::setMoeda(const QString &value) { moeda = value; }

QString Despesa::getCategoria() const { return categoria; }
void Despesa::setCategoria(const QString &value) { categoria = value; }

QString Despesa::getFrequencia() const { return frequencia; }
void Despesa::setFrequencia(const QString &value) { frequencia = value; }
