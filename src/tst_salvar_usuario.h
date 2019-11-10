#include <QObject>
#include <QDebug>
#include <QtTest/QtTest>

#ifndef TST_SALVAR_USUARIO_H
#define TST_SALVAR_USUARIO_H


class tst_salvar_usuario: public QObject
{
    Q_OBJECT
    public:
        tst_salvar_usuario();
    private slots:
        void testSave();
        void testDeleteSettings();
};

#endif // TST_SALVAR_USUARIO_H
