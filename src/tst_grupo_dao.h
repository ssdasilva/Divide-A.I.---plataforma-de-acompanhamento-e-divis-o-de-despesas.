#include <QtTest/QtTest>
#include "grupo_dao.h"
#include "grupo.h"

#ifndef TST_GRUPO_DAO_H
#define TST_GRUPO_DAO_H


class tst_grupo_dao: public QObject
{
    Q_OBJECT
    public:
        tst_grupo_dao();
    private:
        GrupoDAO* grupoDAO;
    private slots:
        void testInsertGrupo();
        void testRemoveGrupo();
        void testGrupoCount();
        void testAdicionarUmaPessoaAoGrupo();
        void usuarios();
};

#endif // TST_GRUPO_DAO_H
