import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Rectangle{
    id: perfilUsuarioRoot
    width: parent.width
    height: parent.height

    property color corTextField: "#0f9ad3"

    Image {
        id: imagem
        source: "/images/account-circle.png"
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Grid{
        width: 281
        anchors.top: imagem.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: -50
        spacing: 5

        columns: 2
        rows: 5

        Label{
            id: lbNome
            text: "Nome: "
            font.pointSize: 12
            color: "black"
            width: 80
            height: 30
            verticalAlignment: Text.AlignVCenter
        }

        TextField{
            id: txNome
            text : perfilUsuario.nome()
            font.pointSize: 12
            width: 220
            height: 30

            horizontalAlignment: Text.AlignHCenter

            background: Rectangle{
                anchors.fill: parent
                border.color: perfilUsuarioRoot.corTextField
                border.width: 2
            }
        }


        Label{
            text: "Sobrenome: "
            font.pointSize: 12
            color: "black"
            width: 80
            height: 30
            verticalAlignment: Text.AlignVCenter
        }

        TextField{
            id: txSobrenome
            text : perfilUsuario.sobrenome()
            font.pointSize: 12
            width: 220
            height: 30

            horizontalAlignment: Text.AlignHCenter

            background: Rectangle{
                anchors.fill: parent
                border.color: perfilUsuarioRoot.corTextField
                border.width: 2
            }
        }

        Label{
            text: "Email: "
            font.pointSize: 12
            color: "black"
            width: 80
            height: 30
            verticalAlignment: Text.AlignVCenter
        }

        TextField{
            id: txEmail
            text : perfilUsuario.email()
            font.pointSize: 12
            readOnly: true
            width: 220
            height: 30

            horizontalAlignment: Text.AlignHCenter

            background: Rectangle{
                anchors.fill: parent
                border.color: perfilUsuarioRoot.corTextField
                border.width: 2
            }
        }

        Label{
            text: "Idade: "
            font.pointSize: 12
            color: "black"
            width: 80
            height: 30
            verticalAlignment: Text.AlignVCenter
        }

        TextField{
            id: txIdade
            text : perfilUsuario.idade()
            font.pointSize: 12
            width: 220
            height: 30

            horizontalAlignment: Text.AlignHCenter

            background: Rectangle{
                anchors.fill: parent
                border.color: perfilUsuarioRoot.corTextField
                border.width: 2
            }
        }

        Label{
            id: txSaldo
            text: "Saldo: "
            font.pointSize: 12
            color: "black"
            width: 80
            height: 30
            verticalAlignment: Text.AlignVCenter
        }

        TextField{
            text : perfilUsuario.saldo()
            font.pointSize: 12
            readOnly: true
            width: 220
            height: 30

            horizontalAlignment: Text.AlignHCenter

            background: Rectangle{
                anchors.fill: parent
                border.color: perfilUsuarioRoot.corTextField
                border.width: 2
            }
        }
    }

    Rectangle{
        id: alert_message
        anchors.top: imagem.top
        anchors.horizontalCenter: imagem.horizontalCenter
        color: change_preference.state? "#00AA00":"#AA0000"
        opacity: 1
        height: 20
        width: 300
        anchors.topMargin: 50
        visible: false
        Text{
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            text: change_preference.state? "Recurso de simplificação de dívidas ativado":
                                           "Recurso de simplificação de dívidas desativado"

            font.bold: true
            color: "white"
        }
        PropertyAnimation {
            id: animation_alert
            running: true
            target: alert_message
            property: 'visible'
            to: false
            duration: 2000 //Duração de 2 segundos
        }
    }

    Row{
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 10

        Botao{
            id: change_preference
            property bool state: perfilUsuario.simplificar()
            anchors.bottomMargin: 5
            textoBotao:"<b> Simplificar </b>"
            corBotao: change_preference.state? "#00AA00":"#AA0000"
            width: 120
            onClicouBotao: {
                alert_message.visible = true
                animation_alert.running = true
                change_preference.state = change_preference.state? false:true
                perfilUsuario.setSimplificar(change_preference.state)
            }
        }

        Botao{
            id: logout_button
            anchors.bottomMargin: 5
            textoBotao: "Logout"
            onClicouBotao: {
                salvar_usuario.deleteSettings()
                stack.pop()
            }
        }

    }

    Connections{
        target: perfilUsuario

        onMudouPerfil: {
            txNome = perfilUsuario.nome()
            txSobrenome = perfilUsuario.sobrenome()
            txEmail = perfilUsuario.email()
            txIdade = perfilUsuario.idade()
            txSaldo = perfilUsuario.saldo()
        }

        onMudouSaldo: {
            txSaldo = saldo
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
