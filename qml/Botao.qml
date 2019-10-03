import QtQuick 2.12
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3


Item{
    id: root
    property color corBotao: "#0f9ad3"
    property color corTexto: "white"
    property string textoBotao: "Clique aqui"
    property int lbFonte: 15
    width: 200
    height: 40
    signal clicouBotao
    visible: true
    enabled: true

    Rectangle{
        anchors.fill: parent
        color: root.corBotao
        radius: 5
        z: 1

        Label{
            text: root.textoBotao
            color: root.corTexto
            font.pointSize: lbFonte
            font.bold: true
            anchors.centerIn: parent
            font.family: "Times New Roman"
        }

        MouseArea{
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton
            onEntered: parent.opacity = 0.5
            onExited: parent.opacity = 1
            onClicked: {
                parent.opacity = 1
                root.clicouBotao()
            }
        }
    }
}
