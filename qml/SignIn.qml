import QtQuick 2.0
import QtQuick.Controls 2.12

Rectangle{
    id: loginWindow
    Image {
            id: logo
            source: "images/Logo.JPG"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
    }
    ScrollView {
        id: scroll_bar
        width:  300
        height: ((parent.height - logo.height - button_row.height) < 250) ?
                    parent.height - logo.height - button_row.height: 250
        clip: true
        anchors.top: logo.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        property int y_mainColumn: 13
        property int width_texMessage: 70
        Column {
            id: main_column
            spacing: 10
            y: scroll_bar.y_mainColumn
            Row {
                id: row1
                spacing: 10
             Text {
                 id: name
                 text: qsTr("Nome")
                 width: scroll_bar.width_texMessage
             }
             TextField {
                 id: name_typed
                 placeholderText: qsTr("Digite seu nome")
                 anchors.verticalCenter: name.verticalCenter
             }
            }
            Row {
                id: row2
                spacing: 10
             Text {
                 id: surname
                 text: qsTr("Sobrenome")
                 width: scroll_bar.width_texMessage
             }
             TextField {
                 id: surname_typed
                 placeholderText: qsTr("Digite seu sobrenome")
                 anchors.verticalCenter: surname.verticalCenter
             }
            }
            Row {
                id: row3
                spacing: 10
             Text {
                 id: age
                 text: qsTr("Idade")
                 width: scroll_bar.width_texMessage
             }
             TextField {
                 id: age_typed
                 placeholderText: qsTr("Digite sua idade")
                 anchors.verticalCenter: age.verticalCenter
             }
            }
            Row {
                id: row4
                spacing: 10
             Text {
                 id: password
                 text: qsTr("Senha")
                 width: scroll_bar.width_texMessage
             }
             TextField {
                 id: password_typed
                 placeholderText: qsTr("Digite sua senha")
                 anchors.verticalCenter: password.verticalCenter
                 echoMode: TextInput.Password
             }
            }
            Row {
                id: row5
                spacing: 10
             Text {
                 id: email
                 text: qsTr("E-mail")
                 width: scroll_bar.width_texMessage
             }
             TextField {
                 id: email_typed
                 placeholderText: qsTr("Digite seu e-mail")
                 anchors.verticalCenter: email.verticalCenter
             }
            }
        }
    }
    Row {
        id: button_row
        width: 300
        height: 100
        spacing: 10
        anchors.top: scroll_bar.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        Button{
            y:10
            width: 150
            text: "Registrar"
            /*onClicked: onClicked: cadastrarUsuario.inserirUsuario("exemplo@gmail.com",
                                                               "123456", "12",
                                                               "Fulano", "De Tal", "21")*/
        }
        Button{
            width: 150
            y:10
            text: "Voltar"
            onClicked: stack.pop()
        }
    }
}


