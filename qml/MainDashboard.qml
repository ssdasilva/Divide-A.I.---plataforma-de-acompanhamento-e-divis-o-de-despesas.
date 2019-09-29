import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Window 2.12

Rectangle {
    id: mainDashboardWindow
    width: parent.width
    height: parent.height

    Rectangle {
        id: newExpenseButton
        width: 50
        height: 50
        radius: 25
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.margins: 20
        color: "#0f9ad3"

        Text {
            anchors.centerIn: parent
            font.pixelSize: 20
            text: "<b>+</b>"
            color: "#ffffff"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {stack.push(newExpense_View)}
        }
    }
}
