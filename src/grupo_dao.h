#ifndef GRUPODAO_H
#define GRUPODAO_H

#include <memory>
#include <vector>

#include <QString>

class Grupo;

class GrupoDAO {
public:
  GrupoDAO() = default;

  bool init() const;

  bool insertGrupo(const Grupo &grupo) const;

  bool removeGrupo(const QString &identificador) const;

  bool removeAll() const;

  int grupoCount() const;

  std::unique_ptr<std::vector<std::unique_ptr<Grupo>>>
  usuarios(const QString &identificador = QString()) const;
};

#endif // GRUPODAO_H
