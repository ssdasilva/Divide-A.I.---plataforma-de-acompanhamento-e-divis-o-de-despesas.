#ifndef USUARIO_DAO_H
#define USUARIO_DAO_H

#include <memory>
#include <vector>

#include <QString>

class Usuario;

class UsuarioDAO {
public:
  UsuarioDAO() = default;

  bool init() const;

  bool insertUsuario(const Usuario &usuario) const;

  bool removeUsuario(const QString &email) const;

  bool removeAll() const;

  int usuarioCount() const;

  std::unique_ptr<std::vector<std::unique_ptr<Usuario>>>
  usuarios(const QString &email = QString()) const;
};

#endif // USUARIO_DAO_H
