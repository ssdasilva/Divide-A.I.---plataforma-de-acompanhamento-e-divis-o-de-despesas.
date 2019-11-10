#include <QObject>
#include <QDebug>
#include <QtTest/QtTest>
#include "despesa_dao.h"
#include "despesa.h"

#ifndef TST_DESPESA_DAO_H
#define TST_DESPESA_DAO_H

class tst_despesa_dao: public QObject
{
    Q_OBJECT
    public:
        tst_despesa_dao();

    private:
        QString email;
        QString descricao;
        QString data;
        QString categoria;
        QString frequencia;
        QString quantia;
        DespesaDAO *despesa_dao;
        Despesa despesa;

    private slots:
        void initTestCase();
        void testInsertDespesa();
        void testRemoveDespesa();
        void testRemoveTodasDespesasUsuario();
        void testRemoveAll();
        void testDespesaCount();
        void testDespesaCountUsuario();
        void testUsuarios();
        void testAtualizarQuantia();
        void testGastoPorCategoria();
};

#endif // TST_DESPESA_DAO_H
