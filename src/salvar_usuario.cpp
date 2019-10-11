#include "salvar_usuario.h"

#include <QDebug>
#include <qsettings.h>

Salvar_usuario::Salvar_usuario(QObject *parent) : QObject(parent) {
    organization = "DivideAI_Organization";
    aplication = "Divide_AI";
    group_name = "User_settings";
}

QString Salvar_usuario::loadEmail() {
    QSettings setting(organization,aplication);
    setting.beginGroup(group_name);
    QString user_email = setting.value("Email","").toString();
    setting.endGroup();
    //qDebug() << user_email;
    return user_email;
}

QString Salvar_usuario::loadPassword(){
    QSettings setting(organization,aplication);
    setting.beginGroup(group_name);
    QString password = setting.value("Senha","").toString();
    setting.endGroup();
    //qDebug() << password;
    return password;
}

void Salvar_usuario::save(const QString &email, const QString &senha) {
    QSettings setting(organization,aplication);
    setting.beginGroup(group_name);
    setting.setValue("Email", email);
    setting.setValue("Senha", senha);
    setting.endGroup();
}

void Salvar_usuario::deleteSettings() {
    this->save("","");
}
