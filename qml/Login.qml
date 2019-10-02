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

    Column {
        id: loginFields
        width: 300
        height: parent.height - logo.height
        anchors.top: logo.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.rightMargin: 20
        anchors.leftMargin: 20
        spacing: 10

        property int label_width: 90
        property int input_width: 200

        Row {
            id: row1
            spacing: 10
            height: 40
            Text {
                id: email
                text: qsTr("E-mail")
                width: loginFields.label_width
            }
            TextField{
                id: emailTextField
                anchors.verticalCenter: email.verticalCenter
                width: loginFields.input_width
                placeholderText: qsTr("Digite e-mail")
                Keys.onPressed: {
                    if (event.key === Qt.Key_Enter ||
                        event.key === Qt.Key_Return) {
                        logIn()
                    }
                }
            }
        }

        Text {
            id: email_alert_text
            x: loginFields.label_width + loginFields.spacing
            height: 0
            visible: false
        }

        Row {
            id: row2
            spacing: 10
            Text {
                id: password
                text: qsTr("Senha")
                width: loginFields.label_width
            }
            TextField{
                id: passwordTextField
                placeholderText: qsTr("Digite sua senha")
                anchors.verticalCenter: password.verticalCenter
                echoMode: TextInput.Password
                Keys.onPressed: {
                    if (event.key === Qt.Key_Enter ||
                        event.key === Qt.Key_Return) {
                        logIn()
                    }
                }
            }
        }

        Text {
            id: password_alert_text
            x: loginFields.label_width + loginFields.spacing
            height: 0
            visible: false
        }

        Button{
            id: okButton
            width: 150
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Entrar")
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
            anchors.horizontalCenter: parent.horizontalCenter
            color: "#cccccc"
        }
        Button{
            id: signInButton
            width: 150
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Quero me cadastrar")
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
        var email = emailTextField.text
        var senha = passwordTextField.text
        if (email === "") {
            showEmailAlert("Insira um e-mail!")
            hidePasswordAlert()
        } else {
            var userExists = cadastrarUsuario.usuarioExiste(email)
            if (!userExists) {
                hideEmailAlert()
                showPasswordAlert("E-mail ou senha incorretos!")
            } else {
                var isPasswordCorrect = cadastrarUsuario.senhaCorreta(email, senha)
                if (isPasswordCorrect) {
                    stack.push(mainDashboard_View)
                } else {
                    hideEmailAlert()
                    showPasswordAlert("E-mail ou senha incorretos!")
                }
            }
        }
    }

    function showEmailAlert(message) {
        row1.height = 30
        email_alert_text.visible = true
        email_alert_text.height = 30
        email_alert_text.text = message
    }

    function hideEmailAlert(){
        email_alert_text.visible = false
        email_alert_text.height = 0
        row1.height = 40
    }

    function showPasswordAlert(message){
        password_alert_text.visible = true
        password_alert_text.height = 20
        password_alert_text.text = message
        row2.height = 30
    }

    function hidePasswordAlert(){
        password_alert_text.visible = false
        password_alert_text.height = 0
        row2.height = 40
    }
}

