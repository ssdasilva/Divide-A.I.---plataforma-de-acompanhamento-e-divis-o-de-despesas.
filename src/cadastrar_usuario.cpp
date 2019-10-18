#include "cadastrar_usuario.h"
#include "usuario.h"
#include "usuario_dao.h"
#include "database_manager.h"
#include "QDebug"

CadastrarUsuario::CadastrarUsuario(QObject *parent) : QObject(parent) {}

bool CadastrarUsuario::usuarioExiste(QString email) {
  UsuarioDAO *usuarioDAO = DatabaseManager::instance().usuarioDAO();

  if (usuarioDAO->usuarios(email)->size() == 0)
    return false;
  else
    return true;
}

bool CadastrarUsuario::inserirUsuario(QString email, QString senha,
                                      QString idade, QString nome,
                                      QString sobrenome, QString saldo,
                                      bool simplificar) {
  Usuario usuario;

  UsuarioDAO *usuarioDAO = DatabaseManager::instance().usuarioDAO();

  usuario.setEmail(email);
  usuario.setSenha(senha);
  usuario.setIdade(idade.toInt());
  usuario.setNome(nome);
  usuario.setSobrenome(sobrenome);
  usuario.setSaldo(saldo.toFloat());
  usuario.setSimplificar(simplificar);


  bool inseriu = usuarioDAO->insertUsuario(usuario);

  return inseriu;
}

bool CadastrarUsuario::senhaCorreta(QString email, QString senha){
    UsuarioDAO *usuarioDAO = DatabaseManager::instance().usuarioDAO();
    if (usuarioDAO->usuarios(email)->at(0)->senha() == senha) return true;
    else return false;
}
