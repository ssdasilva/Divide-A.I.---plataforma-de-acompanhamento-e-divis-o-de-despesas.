#include "secao_usuario.h"

#include <QDebug>

Secao_usuario::Secao_usuario(QObject *parent) : QObject(parent) {}

QString Secao_usuario::getEmailLogado() const {
    return emailLogado;
}
void Secao_usuario::setEmailLogado(const QString &value) {
    emailLogado = value;
}
