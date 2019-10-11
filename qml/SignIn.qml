import QtQuick 2.0
import QtQuick.Controls 2.12

Rectangle{
    id: signInWindow

    Image {
            id: logo
            source: "/images/Logo.JPG"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
    }

    ScrollView {
        id: scroll_bar
        width:  300
        height: ((parent.height - logo.height - bottom_column.height) < 250) ?
                    parent.height - logo.height - bottom_column.height: 250
        clip: true
        anchors.top: logo.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        property int y_mainColumn: 13
        property int width_textMessage: 70

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
                     width: scroll_bar.width_textMessage
                }
                TextField {
                     id: name_typed
                     placeholderText: qsTr("Digite seu nome")
                     anchors.verticalCenter: name.verticalCenter
                     Keys.onPressed:
                     if (event.key === Qt.Key_Enter ||
                         event.key === Qt.Key_Return)
                         registrar()
                }
            }
            Row {
                id: row2
                spacing: 10
                Text {
                     id: surname
                     text: qsTr("Sobrenome")
                     width: scroll_bar.width_textMessage
                }
                TextField {
                     id: surname_typed
                     placeholderText: qsTr("Digite seu sobrenome")
                     anchors.verticalCenter: surname.verticalCenter
                     Keys.onPressed:
                     if (event.key === Qt.Key_Enter ||
                         event.key === Qt.Key_Return)
                         registrar()
                }
            }
            Row {
                id: row3
                spacing: 10
                Text {
                     id: age
                     text: qsTr("Idade")
                     width: scroll_bar.width_textMessage
                }
                TextField {
                     id: age_typed
                     placeholderText: qsTr("Digite sua idade")
                     anchors.verticalCenter: age.verticalCenter
                     Keys.onPressed:
                     if (event.key === Qt.Key_Enter ||
                         event.key === Qt.Key_Return)
                         registrar()
                }
            }
            Row {
                id: row4
                spacing: 10
                Text {
                     id: password
                     text: qsTr("Senha")
                     width: scroll_bar.width_textMessage
                }
                TextField {
                     id: password_typed
                     placeholderText: qsTr("Digite sua senha")
                     anchors.verticalCenter: password.verticalCenter
                     echoMode: TextInput.Password
                     Keys.onPressed:
                     if (event.key === Qt.Key_Enter ||
                         event.key === Qt.Key_Return)
                         registrar()
                }
            }
            Row {
                id: row5
                spacing: 10
                Text {
                     id: email
                     text: qsTr("E-mail")
                     width: scroll_bar.width_textMessage
                }
                TextField {
                     id: email_typed
                     placeholderText: qsTr("Digite seu e-mail")
                     anchors.verticalCenter: email.verticalCenter
                     Keys.onPressed:
                     if (event.key === Qt.Key_Enter ||
                         event.key === Qt.Key_Return)
                         registrar()
                }
            }
        }
    }

    Column {
            id: bottom_column
            spacing: 10
            width: 300
            height: 80
            anchors.top: scroll_bar.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            Row {
                 id: button_row
                 spacing: 10
                 Button{
                        y:10
                        width: 150
                        text: "Registrar"
                        onClicked: registrar()
                }
                Button{
                        width: 150
                        y:10
                        text: "Voltar"
                        onClicked: stack.pop()
                }
            }
            Text{
                 id: error_message
                 anchors.horizontalCenter: parent.horizontalCenter
                 visible: false
                 color: 'red'
                 text: qsTr("Você não preencheu todos os campos")
            }
    }

    function registrar() {
        if (name_typed.text == "" || surname_typed.text == "" ||
                age_typed.text == "" || password_typed.text == "" ||
                email_typed.text == "")
            error_message.visible = true;
        else {
            // por padrão, ao inserir um usuário novo, seu saldo será zero
            cadastrarUsuario.inserirUsuario(email_typed.text, password_typed.text, age_typed.text,
                                                name_typed.text, surname_typed.text, "0");
            stack.pop()
        }
    }
}
