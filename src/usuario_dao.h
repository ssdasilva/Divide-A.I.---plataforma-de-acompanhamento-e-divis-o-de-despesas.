#ifndef USUARIO_DAO_H
#define USUARIO_DAO_H

#include <memory>
#include <vector>

#include <QString>

class Usuario;

class UsuarioDAO {
public:
  UsuarioDAO() = default;

  bool insertUsuario(const Usuario &usuario) const;

  bool removeUsuario(const QString &email) const;

  bool removeAll() const;

  int usuarioCount() const;

  std::unique_ptr<std::vector<std::unique_ptr<Usuario>>>
  usuarios(const QString &email = QString()) const;

  bool atualizarSenha(const QString &email, const QString &senha) const;

  bool atualizarIdade(const QString &email, const QString &idade) const;

  bool atualizarNome(const QString &email, const QString &Nome) const;

  bool atualizarSobrenome(const QString &email, const QString &sobrenome) const;

  bool atualizarSaldo(const QString &email, float saldo) const;
};

#endif // USUARIO_DAO_H
