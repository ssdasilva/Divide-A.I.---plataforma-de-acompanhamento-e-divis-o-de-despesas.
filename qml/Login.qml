import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Window 2.12

Rectangle {
    id: loginWindow
    width: parent.width
    height: parent.height

    Image {
        id: logo
        source: "/images/Logo.JPG"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
    }

    Rectangle {
        id: loginFields
        width: 300
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
        }
        TextField{
            id: usernameTextField
            placeholderText: qsTr("Digite nome do usuário")
            anchors.right: parent.right
            anchors.verticalCenter: username.verticalCenter
            Keys.onPressed: {
                if (event.key === Qt.Key_Enter ||
                    event.key === Qt.Key_Return) {
                    logIn()
                }
            }
        }
        Text {
            id: password
            text: qsTr("Senha")
            anchors.top: username.bottom
            anchors.left: parent.left
            anchors.topMargin: 40

        }
        TextField{
            placeholderText: qsTr("Digite sua senha")
            anchors.right: parent.right
            anchors.verticalCenter: password.verticalCenter
            echoMode: TextInput.Password
            Keys.onPressed: {
                if (event.key === Qt.Key_Enter ||
                    event.key === Qt.Key_Return) {
                    logIn()
                }
            }
        }

        Button{
            id: okButton
            width: 150
            anchors.top: password.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 30
            text: "Entrar"
            onClicked: logIn()
            Keys.onPressed: {
                if (event.key === Qt.Key_Enter ||
                    event.key === Qt.Key_Return) {
                    logIn()
                }
            }
        }
        Rectangle {
            id: divisor
            width: parent.width
            height: 2
            anchors.top: okButton.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 10
            color: "#cccccc"
        }
        Button{
            id: signInButton
            width: 150
            anchors.top: divisor.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 10
            text: "Quero me cadastrar"
            onClicked: stack.push(signIn_View)
            Keys.onPressed: {
                if (event.key === Qt.Key_Enter ||
                    event.key === Qt.Key_Return) {
                    stack.push(signIn_View)
                }
            }
        }
    }

    function logIn() {
        if (usernameTextField.text == ""){
            //Depois tem que arrumar um jeito de mostrar na tela essas informações
            console.log("Insira um usuário!")
        } else {
            var userExists = cadastrarUsuario.usuarioExiste(usernameTextField.text)
            if (!userExists) {
                console.log("E-mail inexistente")
            } else {
                console.log("E-mail encontrado!")
                stack.push(mainDashboard_View)
                //var isPasswordCorrect = cadastrarUsuario.
                //if (isPasswordCorrect) {
                    //stack.push(mainApp_View)
                //} else {
                //  console.log("Senha incorreta")
                //}
            }
        }
    }
}

