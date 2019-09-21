import QtQuick 2.0
import QtQuick.Controls 2.12

Rectangle{
    width: parent.width
    height: parent.height

    Image {
            id: logo
            source: "images/Logo.JPG"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 20
    }

    Rectangle {
        id: loginFields
        width: parent.width>300 ? 300 : parent.width
        height: parent.height - logo.height
        anchors.top: logo.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.rightMargin: 20
        anchors.leftMargin: 20
        Text {
            id: username
            text: qsTr("Nome de Usuário")
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.topMargin: 20
        }
        Text {
            id: password
            text: qsTr("Senha")
            anchors.top: username.bottom
            anchors.left: parent.left
            anchors.topMargin: 40
        }
        Button{
            id: okButton
            anchors.top: password.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 40
            text: "Entrar"
            //onClicked: //tenho que terminar de implementar isso
        }
        TextField{
            placeholderText: qsTr("Digite nome do usuário")
            anchors.right: parent.right
            anchors.verticalCenter: username.verticalCenter
        }
        TextField{
            placeholderText: qsTr("Digite sua senha")
            anchors.right: parent.right
            anchors.verticalCenter: password.verticalCenter
        }
    }
}

