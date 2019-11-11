#include <QObject>
#include <QtTest/QtTest>
#include "despesa.h"

#ifndef TST_DESPESA_H
#define TST_DESPESA_H


class tst_despesa: public QObject
{
    Q_OBJECT
    public:
        tst_despesa();
    private:
        Despesa *despesa;
    private slots:
        void initTestCase();
        void testEmail();
        void testDescricao();
        void testData();
        void testCategoria();
        void testFrequencia();
        void testQuantia();
};

#endif // TST_DESPESA_H
