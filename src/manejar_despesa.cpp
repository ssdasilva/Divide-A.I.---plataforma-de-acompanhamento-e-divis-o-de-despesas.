#include "manejar_despesa.h"
#include "divida.h"
#include "divida_dao.h"
#include "usuario_dao.h"
#include "database_manager.h"

Manejar_despesa::Manejar_despesa(QObject *parent) : QObject(parent) {}

/*bool Manejar_despesa::inserirDespesa(QString email, QString descricao,
                    QString data, QString moeda,
                    QString categoria, QString frequencia){
   std::unique_ptr<std::vector<std::unique_ptr<Usuario>>> usuario;
   // usuario = getActiveUser();

   return false;
}*/

/*bool Manejar_despesa::removerDespesa(QString email, QString descricao){

    return false;
}*/
