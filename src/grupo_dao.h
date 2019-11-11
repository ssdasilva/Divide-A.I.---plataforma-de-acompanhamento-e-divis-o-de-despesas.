#ifndef GRUPODAO_H
#define GRUPODAO_H

#include <memory>
#include <vector>

#include <QString>

class Grupo;

class GrupoDAO {
public:
  GrupoDAO() = default;

  bool insertGrupo(const Grupo &grupo) const;

  bool removeGrupo(const QString &identificador) const;

  int grupoCount() const;

  std::unique_ptr<std::vector<std::unique_ptr<Grupo>>>
  usuarios(const QString &identificador = QString()) const;

  bool adicionarUmaPessoaAoGrupo(const QString &identificador) const;
};

#endif // GRUPODAO_H
