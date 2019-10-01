import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls 2.12

Rectangle {
    id: newExpenseWindow
    width: root.width
    height: root.height

    Rectangle {
        width: 320
        height: parent.height
        anchors.centerIn: parent
        Text {
            id: title
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 10
            font.pointSize: 15
            color: "#222222"
            text: "Nova despesa"
            lineHeight: 1.5
        }
        ScrollView {
            id: scroll_bar
            width:  320
            height: ((parent.height - title.height - button_row.height) < 320) ?
                        parent.height - title.height - button_row.height : 320
            clip: true
            anchors.top: title.bottom

            property int y_mainColumn: 20
            property int textMessages_width: 100
            property int input_width: 200
            property int input_height: 40
            Column {
                id: scrollColumn
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
                        width: scroll_bar.textMessages_width
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
                        width: scroll_bar.textMessages_width
                    }
                    TextField {
                        id: date_selected
                        placeholderText: qsTr("Selecione uma data")
                        anchors.verticalCenter: date.verticalCenter

                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                calendar_rectangle.visible = true
                                disableAllInputs()
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
                        width: scroll_bar.textMessages_width
                    }
                    Rectangle {
                        anchors.verticalCenter: currency.verticalCenter
                        width: scroll_bar.input_width
                        height: scroll_bar.input_height
                        ComboBox {
                            id: currency_combo_box
                            anchors.fill: parent
                            model: ["Reais (R$)", "Dólar (US$)"]
                        }
                    }
                }
                Row {
                    id: row4
                    spacing: 10
                    Text {
                        id: category
                        text: qsTr("Categoria")
                        width: scroll_bar.textMessages_width
                    }
                    Rectangle {
                        anchors.verticalCenter: category.verticalCenter
                        width: scroll_bar.input_width
                        height: scroll_bar.input_height
                        ComboBox {
                            id: category_combo_box
                            anchors.fill: parent
                            model: ["Alimentação","Transporte","Lazer"]
                        }
                    }
                }
                Row {
                    id: row5
                    height: 20
                    spacing: 10
                    Text {
                        id: recurrentExpense
                        text: qsTr("Despesa recorrente?")
                        width: scroll_bar.textMessages_width
                    }
                    Rectangle {
                        anchors.verticalCenter: recurrentExpense.verticalCenter
                        width: scroll_bar.input_width
                        height: scroll_bar.input_height
                        Row {
                            id: radioButtonRow
                            spacing: 10
                            RadioButton {
                                id: recurrentExpense_no_radio_button
                                checked: true
                                text: qsTr("Não")
                                transformOrigin: Item.Left
                                scale: 0.6
                                font.pointSize: 16
                                onClicked: frequency_combo_box.enabled = false
                            }
                            RadioButton {
                                id: recurrentExpense_yes_radio_button
                                text: qsTr("Sim")
                                transformOrigin: Item.Left
                                scale: 0.6
                                font.pointSize: 16
                                onClicked: frequency_combo_box.enabled = true
                            }
                        }
                    }
                }
                Row {
                    id: row6
                    spacing: 10
                    height: 75
                    Text {
                        id: frequency
                        text: qsTr("Selecione a<br/>frequência de<br/>cobrança")
                        width: scroll_bar.textMessages_width
                    }
                    Rectangle {
                        anchors.verticalCenter: frequency.verticalCenter
                        width: scroll_bar.input_width
                        height: scroll_bar.input_height
                        ComboBox {
                            id: frequency_combo_box
                            anchors.fill: parent
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
        }
        Row {
            id: button_row
            width: 320
            height: 80
            spacing: 10
            anchors.top: scroll_bar.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            Button {
                y:10
                width: 150
                text: "Confirmar"
                onClicked: stack.pop()
            }
            Button {
                y:10
                width: 150
                text: "Cancelar"
                onClicked: stack.pop()
            }
        }
        Rectangle {
            id: calendar_rectangle
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: title.bottom
            width: 320
            height: 250
            visible: false
            Calendar {
                id: calendar
                anchors.fill: parent
                minimumDate: new Date()
                onClicked: {
                    calendar_rectangle.visible = false
                    enableAllInputs()
                    date_selected.text = Qt.formatDateTime(date, "dd/MM/yyyy")
                }
            }
        }
    }
    function disableAllInputs() {
        name_typed.enabled = false
        date_selected.enabled = false
        currency_combo_box.enabled = false
        category_combo_box.enabled = false
        recurrentExpense_no_radio_button.enabled = false
        recurrentExpense_yes_radio_button.enabled = false
        frequency_combo_box.enabled = false
    }
    function enableAllInputs() {
        name_typed.enabled = true
        date_selected.enabled = true
        currency_combo_box.enabled = true
        category_combo_box.enabled = true
        recurrentExpense_no_radio_button.enabled = true
        recurrentExpense_yes_radio_button.enabled = true
        if (recurrentExpense_yes_radio_button.checked == true){
            frequency_combo_box.enabled = true
        }
    }
}
