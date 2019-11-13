#include <QObject>
#include <QtTest/QtTest>
#include "divida.h"

#ifndef TST_DIVIDA_H
#define TST_DIVIDA_H

class tst_divida: public QObject
{
    Q_OBJECT
    public:
        tst_divida();
    private:
        Divida *divida;
    private slots:
        void initTestCase();
        void testM_emailDevedor();
        void testM_emailCredor();
        void testM_quantia();
        void testM_tipoMoeda();
        void testM_categoria();
};

#endif // TST_DIVIDA_H
