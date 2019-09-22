import QtQuick 2.0
import QtQuick.Controls 2.12

Rectangle {
    id: singInWindow
    Text {
        id: texto_temporario
        text: qsTr("Tela de cadastro temporária")
        anchors.centerIn: parent
    }

    Button{
        width: 150
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 100
        text: "Cadastrar Usuário"
        onClicked: {
            if (cadastrarUsuario.inserirUsuario("exemplo@gmail.com",
                                                   "123456", "12",
                                                   "Fulano", "De Tal", "21"))
                stack.pop()
        }
    }
}
