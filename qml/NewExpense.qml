import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls 2.12

Rectangle {
    id: newExpenseWindow
    anchors.fill: parent
    width: parent.width
    height: parent.height

    Column {
        id: mainColumn
        anchors.centerIn: parent
        width: 320
        height: parent.height
        spacing: 10
        Text {
            id: title
            anchors.horizontalCenter: parent.horizontalCenter
            font.pointSize: 15
            color: "#222222"
            text: "Nova despesa"
            lineHeight: 1.5
        }
        ScrollView {
            id: scroll_bar
            width:  320
            height: ((parent.height - title.height - button_row.height) < 300) ?
                        parent.height - title.height - button_row.height : 300
            clip: true
            anchors.top: title.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            property int y_mainColumn: 20
            property int width_texMessage: 100
            Column {
                id: scrollColumn
                anchors.centerIn: parent
                spacing: 10
                y: scroll_bar.y_mainColumn
                Row {
                    id: row1
                    height: 53
                    spacing: 10
                    Text {
                        id: name
                        y: 13
                        text: qsTr("Nome da despesa")
                        width: scroll_bar.width_texMessage
                    }
                    TextField {
                        id: name_typed
                        placeholderText: qsTr("Digite o nome da despesa")
                        anchors.verticalCenter: name.verticalCenter
                    }
                }
                Row {
                    id: row2
                    spacing: 10
                    Text {
                        id: date
                        text: qsTr("Data da despesa")
                        width: scroll_bar.width_texMessage
                    }
                    TextField {
                        id: date_selected
                        placeholderText: qsTr("Selecione uma data")
                        anchors.verticalCenter: date.verticalCenter

                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                calendar.visible = true
                            }
                        }
                    }
                }
                Row {
                    id: row3
                    spacing: 10
                    Text {
                        id: currency
                        text: qsTr("Moeda")
                        width: scroll_bar.width_texMessage
                    }
                    ComboBox {
                        id: currency_combo_box
                        anchors.left: date_selected.left
                        anchors.verticalCenter: currency.verticalCenter
                        width: date_selected.width
                        model: ["Reais (R$)", "Dólar (US$)"]
                    }
                }
                Row {
                    id: row4
                    spacing: 10
                    Text {
                        id: category
                        text: qsTr("Categoria")
                        width: scroll_bar.width_texMessage
                    }
                    ComboBox {
                        id: category_combo_box
                        anchors.left: date_selected.left
                        anchors.verticalCenter: category.verticalCenter
                        width: date_selected.width
                        //model: ["Reais (R$)", "Dólar (US$)"]
                    }
                }
                Row {
                    id: row5
                    height: 20
                    spacing: 10
                    Text {
                        id: recurrentExpense
                        text: qsTr("Despesa recorrente?")
                        width: scroll_bar.width_texMessage
                    }
                    RadioButton {
                        id: recurrentExpense_no_radio_button
                        anchors.verticalCenter: recurrentExpense.verticalCenter
                        checked: true
                        text: qsTr("Não")
                        transformOrigin: Item.Left
                        scale: 0.6
                        font.pointSize: 16
                        onClicked: {
                            frequency_combo_box.enabled = false
                        }
                    }
                    RadioButton {
                        id: recurrentExpense_yes_radio_button
                        anchors.verticalCenter: recurrentExpense.verticalCenter
                        text: qsTr("Sim")
                        transformOrigin: Item.Left
                        scale: 0.6
                        font.pointSize: 16
                        onClicked: {
                            frequency_combo_box.enabled = true
                        }
                    }
                }
                Row {
                    id: row6
                    spacing: 10
                    Text {
                        id: frequency
                        text: qsTr("Selecione a<br/>frequência de<br/>cobrança")
                        width: scroll_bar.width_texMessage
                    }
                    ComboBox {
                        id: frequency_combo_box
                        anchors.left: date_selected.left
                        anchors.verticalCenter: category.verticalCenter
                        width: date_selected.width
                        enabled: false
                        model: ["A cada 2 dias",
                                "Semanal",
                                "Quinzenal",
                                "Mensal",
                                "Dias da semana",
                                "Finais de semana"]
                    }
                }
            }
        }
        Row {
            id: button_row
            width: 320
            height: 100
            spacing: 10
            anchors.top: scroll_bar.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            Button{
                y:10
                width: 150
                text: "Confirmar"
                onClicked: stack.pop()
            }
            Button{
                width: 150
                y:10
                text: "Cancelar"
                onClicked: stack.pop()
            }
        }
    }
    Calendar {
        id: calendar
        anchors.horizontalCenter: parent.horizontalCenter
        //anchors.verticalCenter: parent.verticalCenter
        y: 30 + title.height + row1.height + row2.height
        width: 260
        height: 200
        visible: false
        minimumDate: new Date()
        onClicked: {
            visible = false
            date_selected.text = Qt.formatDateTime(date, "dd/MM/yyyy")
        }
    }
}
