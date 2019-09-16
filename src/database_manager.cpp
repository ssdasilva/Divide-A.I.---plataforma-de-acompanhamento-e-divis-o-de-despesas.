#include "database_manager.h"

#include <QCoreApplication>
#include <QSqlDatabase>

std::unique_ptr<DatabaseManager> DatabaseManager::s_instance;

std::once_flag DatabaseManager::s_onceFlag;

DatabaseManager &DatabaseManager::instance() {
  std::call_once(s_onceFlag, []() { s_instance.reset(new DatabaseManager()); });
  return *(s_instance.get());
}

void DatabaseManager::closeDatabase() {
  if (m_database) {
    m_database->close();
  }
}

DatabaseManager::DatabaseManager()
    : m_database(new QSqlDatabase(
          QSqlDatabase::addDatabase(QStringLiteral("QSQLITE")))) {
  m_database->setDatabaseName(QString("%1/%2").arg(
      QCoreApplication::applicationDirPath(), DATABASE_FILENAME));

  if (m_database->open()) {
    m_usuarioDAO.init();
  }
}

UsuarioDAO *DatabaseManager::usuarioDAO() { return &m_usuarioDAO; }

GrupoDAO *DatabaseManager::grupoDAO() { return &m_grupoDAO; }

DividaDAO *DatabaseManager::dividaDAO() { return &m_dividaDAO; }
