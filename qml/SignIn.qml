import QtQuick 2.0

Rectangle {
    id: loginWindow
    width: parent.width
    height: parent.height
    Text {
        id: texto_temporario
        text: qsTr("Tela de cadastro temporária")
        anchors.centerIn: parent
    }
}
