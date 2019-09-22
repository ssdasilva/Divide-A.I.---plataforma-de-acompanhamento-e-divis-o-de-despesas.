#include "cadastrar_usuario.h"
#include "usuario.h"
#include "usuario_dao.h"
#include "database_manager.h"

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
                                      QString sobrenome, QString saldo) {
  Usuario usuario;

  UsuarioDAO *usuarioDAO = DatabaseManager::instance().usuarioDAO();

  usuario.setEmail(email);
  usuario.setSenha(senha);
  usuario.setIdade(idade.toInt());
  usuario.setNome(nome);
  usuario.setSobrenome(sobrenome);
  usuario.setSaldo(saldo.toFloat());

  bool inseriu = usuarioDAO->insertUsuario(usuario);

  return inseriu;
}
