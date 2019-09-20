import QtQuick 2.0
import QtQuick.Controls 2.12

Rectangle{
    width: 640
    height: 480
    Image {
            id: logo
            source: "images/Logo.JPG"
            x: 240
            y: 0
    }
    Text {
            id: username
            text: qsTr("Nome de Usuário")
            x: 180
            y: 160
    }
    Text {
            id: password
            text: qsTr("Senha")
            x: 180
            y: 210
    }
    Button{
        id: okButton
        x: 280
        y: 300
        text: "Entrar"
        //onClicked: //tenho que terminar de implementar isso
    }
    TextField{
        placeholderText: qsTr("Digite nome do usuário")
        x: 280
        y: 150
    }
    TextField{
        placeholderText: qsTr("Digite sua senha")
        x: 280
        y: 210
    }
}

