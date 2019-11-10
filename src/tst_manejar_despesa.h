#include <QObject>
#include <QDebug>
#include <QtTest/QtTest>
#include "manejar_despesa.h"
#include "cadastrar_usuario.h"

#ifndef TST_MANEJAR_DESPESA_H
#define TST_MANEJAR_DESPESA_H

class tst_manejar_despesa: public QObject
{
    Q_OBJECT
    public:
        tst_manejar_despesa();

    private:
        QString email;
        QString senha;
        QString idade;
        QString nome;
        QString sobrenome;
        QString saldo;
        bool simplificar;
        QString descricao;
        QString data;
        QString categoria;
        QString frequencia;
        QString quantia;
        Manejar_despesa *manejar_despesa;
        CadastrarUsuario *cadastrarUsuario;

    private slots:
        void initTestCase();
        void testInserirDespesa();
        void testRemoverDespesa();
        void testQuantidadeDespesasUsuario();
        void testGetDescricaoDespesaUsuario();
        void testGetCategoriaDespesaUsuario();
        void testGetDataDespesaUsuario();
        void testGetFrequenciaDespesaUsuario();
        void testGetQuantiaDespesaUsuario();

};

#endif // TST_MANEJAR_DESPESA_H
