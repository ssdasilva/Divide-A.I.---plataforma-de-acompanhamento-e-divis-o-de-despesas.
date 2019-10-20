#include "grafico_categoria.h"
#include "despesa_dao.h"
#include "database_manager.h"
#include "salvar_usuario.h"

#include <QMap>
#include <QDebug>

GraficoCategoria::GraficoCategoria(QObject *parent) : QObject(parent) {}

void GraficoCategoria::criarGrafico() {
  DespesaDAO *despesaDAO = DatabaseManager::instance().despesaDAO();

  Salvar_usuario salvarUsuario;
  QString email = salvarUsuario.loadEmail();

  QMap<QString, int> categorias = despesaDAO->gastoPorCategoria(email);

  emit apagarDados();

  if (categorias.isEmpty())
    emit inserirCategoria("Outros", 0);
  else {
    QMapIterator<QString, int> i(categorias);

    while (i.hasNext()) {
      i.next();
      emit inserirCategoria(i.key(), i.value());
    }
  }
}
