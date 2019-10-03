import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Window 2.12

Rectangle {
    id: mainDashboardWindow
    width: parent.width
    height: parent.height


    Column {
        id: groupColumn
        y: 0
        width: parent.width

        Image {
            id: image
            width: parent.width
            height: 100
            fillMode: Image.PreserveAspectFit
            source: "../images/Logo.JPG"
        }

        Row {
            id: headerRow
            width: parent.width
            height: 50

            Button {
                id: groupButton
                width: parent.width/3
                height: parent.height
                text: qsTr("Grupos")
                font.bold: true
                font.pointSize: 15
                onClicked: setflag(1)
            }

            Button {
                id: expensesButton
                width: parent.width/3
                height: parent.height
                text: qsTr("Dívidas")
                font.bold: true
                font.pointSize: 15
                onClicked: setflag(0)
            }

            Button {
                id: perfilUsuarioButton
                width: parent.width/3
                height: parent.height
                text: qsTr("Perfil")
                font.bold: true
                font.pointSize: 15
                onClicked: setflag(2)
            }
        }


    }

    ScrollView {
        id: scroll_bar
        y: 160
        width: parent.width
        height: parent.height - 160
        anchors.top: groupColumn.bottom
        anchors.left: parent.left
        anchors.right: parent.height
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
        ScrollBar.vertical.policy: ScrollBar.AlwaysOn


        Column {
            id: groupContent
            y: 0
            height: scroll_bar.height
            width: scroll_bar.width
            anchors.top: parent.top

            Row {
                id: group1
                height: 100
                width: parent.width
                //anchors.centerIn: parent.Center

                Image {
                    id: group1_image
                    width: 100
                    height: 100
                    clip: false
                    fillMode: Image.PreserveAspectFit
                    source: "../images/Logo.JPG"
                }

                Column {
                    id: group1_info
                    width: parent.width - group1_image.width
                    height: parent.height
                    anchors.left: group1_image.right

                    Text {
                        id: group1_name
                        width: parent.width
                        height: parent.height/3
                        text: qsTr("Nome - Grupo 1")
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        font.pixelSize: 15
                    }

                    Text {
                        id: group1_members
                        width: parent.width
                        height: (parent.height - group1_name.height)/2
                        text: qsTr("Membros: fulano, sicrano, beltrano.")
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        font.pixelSize: 12
                    }

                    Text {
                        id: group1_expenses
                        width: parent.width
                        height: (parent.height - group1_name.height)/2
                        color: "#eb0808"
                        text: qsTr("Você deve R$7.")
                        font.bold: true
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        font.pixelSize: 12
                    }
                }
            }

            Row {
                id: group2
                width: parent.width
                height: 100
                Image {
                    id: group2_image
                    width: 100
                    height: 100
                    fillMode: Image.PreserveAspectFit
                    clip: false
                    source: "../images/Logo.JPG"
                }

                Column {
                    id: group2_info
                    width: parent.width - group2_image.width
                    height: parent.height
                    Text {
                        id: group2_name
                        width: parent.width
                        height: parent.height/3
                        text: qsTr("Nome - Grupo 2")
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        font.pixelSize: 15
                    }

                    Text {
                        id: group2_members
                        width: parent.width
                        height: (parent.height - group2_name.height)/2
                        text: qsTr("Membros: Julinho, Maurílio, Rogerinho.")
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        font.pixelSize: 12
                    }

                    Text {
                        id: group2_expenses
                        width: parent.width
                        height: (parent.height - group2_name.height)/2
                        color: "#2e7610"
                        text: qsTr("Você recebe R$30.")
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        font.pixelSize: 12
                        font.bold: true
                    }
                }
            }

            Row {
                id: group3
                width: parent.width
                height: 100
                anchors.centerIn: parent.Center

                Image {
                    id: group3_image
                    width: 100
                    height: 100
                    clip: false
                    fillMode: Image.PreserveAspectFit
                    source: "../images/Logo.JPG"
                }

                Column {
                    id: group3_info
                    width: parent.width - group3_image.width
                    height: parent.height
                    anchors.left: group3_image.right

                    Text {
                        id: group3_name
                        width: parent.width
                        height: parent.height/3
                        text: qsTr("Nome - Grupo 3")
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        font.pixelSize: 15
                    }

                    Text {
                        id: group3_members
                        width: parent.width
                        height: (parent.height - group3_name.height)/2
                        text: qsTr("Membros: fulano, sicrano, beltrano.")
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        font.pixelSize: 12
                    }

                    Text {
                        id: group3_expenses
                        width: parent.width
                        height: (parent.height - group3_name.height)/2
                        color: "#eb0808"
                        text: qsTr("Você deve R$7.")
                        font.bold: true
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        font.pixelSize: 12
                    }
                }
            }

            Row {
                id: group4
                width: parent.width
                height: 100
                anchors.centerIn: parent.Center

                Image {
                    id: group4_image
                    width: 100
                    height: 100
                    clip: false
                    fillMode: Image.PreserveAspectFit
                    source: "../images/Logo.JPG"
                }

                Column {
                    id: group4_info
                    width: parent.width - group4_image.width
                    height: parent.height
                    anchors.left: group4_image.right

                    Text {
                        id: group4_name
                        width: parent.width
                        height: parent.height/3
                        text: qsTr("Nome - Grupo 4")
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        font.pixelSize: 15
                    }

                    Text {
                        id: group4_members
                        width: parent.width
                        height: (parent.height - group4_name.height)/2
                        text: qsTr("Membros: fulano, sicrano, beltrano.")
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        font.pixelSize: 12
                    }

                    Text {
                        id: group4_expenses
                        width: parent.width
                        height: (parent.height - group4_name.height)/2
                        color: "#eb0808"
                        text: qsTr("Você deve R$7.")
                        visible: true
                        font.bold: true
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        font.pixelSize: 12
                    }
                }
            }


        }

        Column {
            id: expensesContent
            y: 0
            height: scroll_bar.height
            width: scroll_bar.width
            anchors.top: parent.top
            visible: false

            Row {
                id: egroup1
                height: 100
                width: parent.width
                anchors.centerIn: parent.Center

                Image {
                    id: egroup1_image
                    width: 100
                    height: 100
                    clip: false
                    fillMode: Image.PreserveAspectFit
                    source: "../images/Logo.JPG"
                }

                Column {
                    id: egroup1_info
                    width: parent.width - egroup1_image.width
                    height: parent.height
                    anchors.left: egroup1_image.right

                    Text {
                        id: egroup1_name
                        width: parent.width
                        height: parent.height/3
                        text: qsTr("Despesa com Beltrano")
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        font.pixelSize: 15
                    }

                    Text {
                        id: egroup1_members
                        width: parent.width
                        height: (parent.height - egroup1_name.height)/2
                        text: qsTr("Açaí - 30/10")
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        font.pixelSize: 12
                    }

                    Text {
                        id: egroup1_expenses
                        width: parent.width
                        height: (parent.height - egroup1_name.height)/2
                        color: "#eb0808"
                        text: qsTr("Você deve R$7.")
                        font.bold: true
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        font.pixelSize: 12
                    }
                }
            }

        }

        Column{
            id: perfilUsuarioContent
            y: 0
            height: scroll_bar.height
            width: scroll_bar.width
            anchors.top: parent.top
            visible: false

            PerfilUsuario{

            }
        }

    }

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





    function setflag(mudaFlag) {
        switch(mudaFlag){
        case 0:
            groupContent.visible = false;
            expensesContent.visible = true;
            perfilUsuarioContent.visible = false;
            break;

        case 1:
            groupContent.visible = true;
            expensesContent.visible = false;
            perfilUsuarioContent.visible = false;
            break;

        case 2:
            groupContent.visible = false;
            expensesContent.visible = false;
            perfilUsuarioContent.visible = true;
            break;

        default:
            break;
        }
    }

}


/*##^##
Designer {
    D{i:6;anchors_height:100;anchors_y:0}
}
##^##*/
