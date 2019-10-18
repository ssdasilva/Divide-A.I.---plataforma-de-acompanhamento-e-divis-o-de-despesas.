#ifndef MANEJAR_DESPESA_H
#define MANEJAR_DESPESA_H

#include <QObject>

class Manejar_despesa : public QObject {
    Q_OBJECT
public:
    Manejar_despesa(QObject *parent = nullptr);

    Q_INVOKABLE bool inserirDespesa(QString email, QString descricao,
                                   QString data, QString categoria,
                                   QString frequencia, QString quantia);
    //Permite a inserção de uma nova dívida para o usuário do usuário email.
    //Retorna true se a inserção foi bem sucedida e false caso contrário

    //Q_INVOKABLE bool removerDespesa(QString email, QString descricao);
    //Permite a remoção de uma dívida de um usuário. Retorna true se a
    //remoção foi bem sucedida (ou seja, se a dívida existe), e false se
    //a remoção não foi bem sucedida

    Q_INVOKABLE int quantidadeDespesasUsuario(QString email);
    //Retorna a quantidade de despesas daquele usuário

    Q_INVOKABLE QString getDescricaoDespesaUsuario(QString email, unsigned long order);

    Q_INVOKABLE QString getCategoriaDespesaUsuario(QString email, unsigned long order);

    Q_INVOKABLE int getQuantiaDespesaUsuario(QString email, unsigned long order);

};

#endif // MANEJAR_DESPESA_H
