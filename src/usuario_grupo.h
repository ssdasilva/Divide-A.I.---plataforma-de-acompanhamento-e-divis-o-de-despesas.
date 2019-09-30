#ifndef USUARIOGRUPO_H
#define USUARIOGRUPO_H

#include <QObject>

class UsuarioGrupo : public QObject {
  Q_OBJECT

public:
  explicit UsuarioGrupo(QObject *parent = nullptr);

  QString emailUsuario() const;
  void setEmailUsuario(const QString &emailUsuario);

  QString identificadorGrupo() const;
  void setIdentificadorGrupo(const QString &IdentificadorGrupo);

private:
  QString m_emailUsuario;

  QString m_identificadorGrupo;
};

#endif // USUARIOGRUPO_H
