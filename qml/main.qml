import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.12
//import QtQuick.Layouts 1.3


Window {
    id: root
    visible: true
    width: 640
    height: 480
    minimumWidth: 340
    minimumHeight: 360
    title: qsTr("Divide AI")
    StackView {
        id: stack
        initialItem: login_View
        anchors.fill: parent
    }
    Component {
        id: login_View
        Login{}
    }
    Component{
        id: signIn_View
        SignIn{}
    }
}
