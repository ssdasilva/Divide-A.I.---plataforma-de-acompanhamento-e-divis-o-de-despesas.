#include "manejar_despesa.h"
#include "despesa.h"
#include "despesa_dao.h"
#include "usuario_dao.h"
#include "database_manager.h"

#include <QDebug>

Manejar_despesa::Manejar_despesa(QObject *parent) : QObject(parent) {}

bool Manejar_despesa::inserirDespesa(QString email, QString descricao,
                    QString data, QString moeda, QString categoria,
                    QString frequencia, QString quantia){

   Despesa despesa;

   DespesaDAO *despesaDAO = DatabaseManager::instance().despesaDAO();

   despesa.setEmail(email);
   despesa.setDescricao(descricao);
   despesa.setData(data);
   despesa.setMoeda(moeda);
   despesa.setCategoria(categoria);
   despesa.setFrequencia(frequencia);
   despesa.setQuantia(quantia.toInt());

   bool inseriu = despesaDAO->insertDespesa(despesa);

   return inseriu;
}

/*bool Manejar_despesa::removerDespesa(QString email, QString descricao){

    return false;
}*/

int Manejar_despesa::quantidadeDespesasUsuario(QString email){
    DespesaDAO *despesaDAO = DatabaseManager::instance().despesaDAO();
    int quantidade = despesaDAO->despesaCountUsuario(email);
    return quantidade;
}

QString Manejar_despesa::getDescricaoDespesaUsuario(QString email, unsigned long order){
    DespesaDAO *despesaDAO = DatabaseManager::instance().despesaDAO();

    std::unique_ptr<std::vector<std::unique_ptr<Despesa>>> list;
    list = despesaDAO->usuarios(email);

    return list->at(order)->getDescricao();

}

QString Manejar_despesa::getCategoriaDespesaUsuario(QString email, unsigned long order){
    DespesaDAO *despesaDAO = DatabaseManager::instance().despesaDAO();

    std::unique_ptr<std::vector<std::unique_ptr<Despesa>>> list;
    list = despesaDAO->usuarios(email);

    return list->at(order)->getCategoria();
}

QString Manejar_despesa::getMoedaDespesaUsuario(QString email, unsigned long order){
    DespesaDAO *despesaDAO = DatabaseManager::instance().despesaDAO();

    std::unique_ptr<std::vector<std::unique_ptr<Despesa>>> list;
    list = despesaDAO->usuarios(email);

    return list->at(order)->getMoeda();
}

int Manejar_despesa::getQuantiaDespesaUsuario(QString email, unsigned long order){
    DespesaDAO *despesaDAO = DatabaseManager::instance().despesaDAO();

    std::unique_ptr<std::vector<std::unique_ptr<Despesa>>> list;
    list = despesaDAO->usuarios(email);

    return list->at(order)->getQuantia();
};
