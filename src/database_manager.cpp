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
    qDebug() << " Banco abriu";
    m_usuarioDAO.init();
    /* Exemplo de uma consulta no banco */
    qDebug() << "--------Exemplo de consulta no banco de dados:-------";
    QSqlQuery query;
    if(query.exec("SELECT * FROM public.usuario"))
    {
      qDebug()<<"Email/Senha/Nome/Sobrenome/Idade/Saldo";
      while(query.next())
      {
       qDebug()<< query.value(0).toString()<<" "<< query.value(1).toString()<<" "<< query.value(2).toString()<<" "<< query.value(3).toString()<<" "<< query.value(4).toString()<<query.value(5).toString();
      }
      qDebug() << "-------------";
     }
     else
       qDebug()<<"Erro ao tentar executar query";
  }
  else
    qDebug() << "Banco não foi aberto";
}

UsuarioDAO *DatabaseManager::usuarioDAO() { return &m_usuarioDAO; }

GrupoDAO *DatabaseManager::grupoDAO() { return &m_grupoDAO; }

DividaDAO *DatabaseManager::dividaDAO() { return &m_dividaDAO; }
