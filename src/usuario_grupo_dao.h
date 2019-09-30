#ifndef USUARIOGRUPODAO_H
#define USUARIOGRUPODAO_H

#include <memory>
#include <vector>

#include <QString>

class UsuarioGrupo;

class UsuarioGrupoDAO {
public:
  UsuarioGrupoDAO() = default;

  bool init() const;

  bool insertUsuarioGrupo(const UsuarioGrupo &usuarioGrupo) const;

  bool removeUsuarioGrupo(const QString &emailUsuario,
                          const QString &identificadorGrupo) const;

  bool removeAll() const;

  int usuarioGrupoCount() const;

  std::unique_ptr<std::vector<std::unique_ptr<UsuarioGrupo>>>
  usuarioGrupos(const QString &emailUsuario = QString(),
                const QString &identificadorGrupo = QString()) const;
};

#endif // USUARIOGRUPODAO_H
