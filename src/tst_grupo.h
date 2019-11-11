#include <QObject>
#include <QtTest/QtTest>
#include "grupo.h"

#ifndef TST_GRUPO_H
#define TST_GRUPO_H


class tst_grupo: public QObject
{
    Q_OBJECT
    public:
        tst_grupo();
    private:
        Grupo *grupo;
    private slots:
        void testIdentificador();
        void testSetIdentificador();
        void testNome();
        void testSetNome();
        void testNumPessoas();
        void testSetNumPessoas();
};

#endif // TST_GRUPO_H
