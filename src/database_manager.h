#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include "usuario_dao.h"
#include "grupo_dao.h"
#include "divida_dao.h"
#include "usuario_grupo_dao.h"

#include <QString>

#include <memory>
#include <mutex>

class QSqlDatabase;

const QString DATABASE_FILENAME = QStringLiteral("DivideAI.db");

class DatabaseManager {
public:
  virtual ~DatabaseManager() = default;

  static DatabaseManager &instance();

  void closeDatabase();

  UsuarioDAO *usuarioDAO();

  GrupoDAO *grupoDAO();

  DividaDAO *dividaDAO();

  UsuarioGrupoDAO *usuarioGrupoDAO();

private:
  Q_DISABLE_COPY(DatabaseManager)

  DatabaseManager();

  static std::unique_ptr<DatabaseManager> s_instance;

  static std::once_flag s_onceFlag;

  std::unique_ptr<QSqlDatabase> m_database;

  UsuarioDAO m_usuarioDAO;

  GrupoDAO m_grupoDAO;

  DividaDAO m_dividaDAO;

  UsuarioGrupoDAO m_usuarioGrupoDAO;
};

#endif // DATABASE_MANAGER_H
