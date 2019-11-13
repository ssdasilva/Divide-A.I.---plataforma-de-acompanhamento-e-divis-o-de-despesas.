#include <QObject>
#include <QDebug>
#include <QtTest/QtTest>
#include "divida_dao.h"
#include "divida.h"

#ifndef TST_DIVIDA_DAO_H
#define TST_DIVIDA_DAO_H

class tst_divida_dao: public QObject
{
    Q_OBJECT
    public:
        tst_divida_dao();
    private:
        QString m_emailDevedor;
        QString m_emailCredor;
        int m_quantia;
        QString m_tipoMoeda;
        QString m_categoria;
        DividaDAO *divida_dao;
        Divida divida;
    private slots:
        void initTestCase();
        void testInsertDivida();
        void testRemoveDivida();
        void testDividaCount();
        void testUsuarios();
};

#endif // TST_DIVIDA_DAO_H
