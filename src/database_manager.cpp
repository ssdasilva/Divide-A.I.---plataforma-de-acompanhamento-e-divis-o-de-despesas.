#include "database_manager.h"

#include <QCoreApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>

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
          QSqlDatabase::addDatabase(QStringLiteral("QPSQL")))) {
  m_database->setHostName("motty.db.elephantsql.com");
  m_database->setUserName("lhdsevbs");
  m_database->setPassword("Veujw2R99MrbPUN8VX_A7bWtjzI52k-4");
  m_database->setPort(5432);
  m_database->setDatabaseName("lhdsevbs");
  if (m_database->open()) {
    qDebug() << "Abriu o banco";
  } else
    qDebug() << "Banco não foi aberto";
}

UsuarioDAO *DatabaseManager::usuarioDAO() { return &m_usuarioDAO; }

GrupoDAO *DatabaseManager::grupoDAO() { return &m_grupoDAO; }

DividaDAO *DatabaseManager::dividaDAO() { return &m_dividaDAO; }

UsuarioGrupoDAO *DatabaseManager::usuarioGrupoDAO() {
  return &m_usuarioGrupoDAO;
}
