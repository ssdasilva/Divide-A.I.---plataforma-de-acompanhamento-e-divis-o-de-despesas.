#include "usuario_grupo.h"

UsuarioGrupo::UsuarioGrupo(QObject *parent) : QObject(parent) {}

QString UsuarioGrupo::emailUsuario() const { return m_emailUsuario; }

void UsuarioGrupo::setEmailUsuario(const QString &emailUsuario) {
  m_emailUsuario = emailUsuario;
}

QString UsuarioGrupo::identificadorGrupo() const {
  return m_identificadorGrupo;
}

void UsuarioGrupo::setIdentificadorGrupo(const QString &identificadorGrupo) {
  m_identificadorGrupo = identificadorGrupo;
}
