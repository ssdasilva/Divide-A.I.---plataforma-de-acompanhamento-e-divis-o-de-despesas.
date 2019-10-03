import QtQuick 2.11
import QtQuick.Controls 2.12

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    minimumWidth: 340
    minimumHeight: 360

    header: Rectangle{
        width: parent.width
        height: 100
        Image {
            anchors.centerIn: parent
            height: 100
            fillMode: Image.PreserveAspectFit
            source: "../images/Logo.JPG"
        }
    }

    SwipeView {
        id: view
        anchors.fill: parent


        Page {
            id: mainDashboard_View
            MainDashboard{}
        }

        Page {
            PerfilUsuario{
                id: perfilUsuario_View
                anchors.fill: parent
            }
        }
    }
}
