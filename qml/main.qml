import QtQuick 2.12
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

    signal conectar(string a)

    function conexao(a){
        conectar(a)
    }

    StackView {
        id: stack
        initialItem: login_View
        anchors.fill: parent
    }
    Component {
        id: login_View
        Login{
            Component.onCompleted: notify.connect(root.conexao)
        }
    }
    Component{
        id: signIn_View
        SignIn{}
    }
    Component {
        id: mainDashboard_View

        MainDashboard{
            id: mainDashboard

            Component.onCompleted: root.conectar.connect(reciever)
        }
    }
    Component {
        id: newExpense_View
        NewExpense{}
    }
}
