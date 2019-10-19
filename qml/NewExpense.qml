import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
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
            height: ((parent.height - title.height - button_column.height) < 420) ?
                        parent.height - title.height - button_column.height : 420
            clip: true
            anchors.top: title.bottom

            property int scrollColumn_y: 20
            property int textMessages_width: 100
            property int input_width: 200
            property int input_height: 40

            Column {
                id: scrollColumn
                spacing: 10
                y: scroll_bar.scrollColumn_y
                Row {
                    id: rowName
                    height: 50
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
                    id: rowAmount
                    height: 30
                    spacing: 10
                    Text {
                        id: amount
                        text: qsTr("Quantia")
                        width: scroll_bar.textMessages_width
                    }
                    TextField {
                        id: amount_typed
                        placeholderText: qsTr("Insira um valor")
                        anchors.verticalCenter: amount.verticalCenter
                        onEditingFinished: {
                            if (isNaN(parseInt(amount_typed.text)))
                                amount_typed.text = ""
                        }
                    }
                }
                Row {
                    id: rowExpenseType
                    height: 30
                    spacing: 10
                    Text {
                        id: expenseType
                        text: qsTr("Tipo de despesa")
                        width: scroll_bar.textMessages_width
                    }
                    Rectangle {
                        anchors.verticalCenter: expenseType.verticalCenter
                        width: scroll_bar.input_width
                        height: scroll_bar.input_height
                        Row {
                            id: rowExpenseTypeRadioButton
                            spacing: -30
                            RadioButton {
                                id: expenseType_expense_radio_button
                                checked: true
                                text: qsTr("Despesa")
                                transformOrigin: Item.Left
                                scale: 0.6
                                font.pointSize: 16
                                Keys.onPressed: {
                                    if (event.key === Qt.Key_Enter ||
                                        event.key === Qt.Key_Return) {
                                        expenseType_expense_radio_button.checked = true
                                        date_selected.focus = true
                                    }
                                }
                            }
                            RadioButton {
                                id: expenseType_gain_radio_button
                                text: qsTr("Entrada")
                                transformOrigin: Item.Left
                                scale: 0.6
                                font.pointSize: 16
                                Keys.onPressed: {
                                    if (event.key === Qt.Key_Enter ||
                                        event.key === Qt.Key_Return) {
                                        expenseType_gain_radio_button.checked = true
                                        date_selected.focus = true
                                    }
                                }
                            }
                        }
                    }
                }
                Row {
                    id: rowDate
                    spacing: 10
                    Text {
                        id: date
                        text: qsTr("Data da despesa")
                        width: scroll_bar.textMessages_width
                    }
                    Rectangle {
                        id: date_selected_rectangle
                        width: scroll_bar.input_width
                        height: scroll_bar.input_height
                        anchors.verticalCenter: date.verticalCenter
                        border.color: "#bdbdbd"
                        border.width: 1

                        Text {
                            id: date_selected
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.left: parent.left
                            anchors.leftMargin: 10
                            color: "#bdbdbd"
                            text: qsTr("Selecione uma data")
                        }

                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                showCalendar()
                            }
                        }
                        Keys.onPressed: {
                            if (event.key === Qt.Key_Enter ||
                                event.key === Qt.Key_Return) {
                                showCalendar()
                            }
                        }
                    }
                }
                Row {
                    id: rowCategory
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
                            model: ["Alimentação","Transporte",
                                "Lazer","Supermercado","Compras",
                                "Viagem","Saúde","Educação",
                                "Trabalho","Família", "Hobbies",
                                "Esporte","Presentes","Doações",
                                "Casa","Contas"]
                        }
                    }
                }
                Row {
                    id: rowRecurrentExpense
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
                            id: rowRecurrentExpenseRadioButton
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
                    id: rowFrequency
                    spacing: 10
                    height: 54
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
        Column{
            id: button_column
            width: 320
            height: 80
            spacing: 10
            anchors.top: scroll_bar.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            Row {
                id: button_row
                spacing: 10
                Button {
                    y:10
                    width: 150
                    text: "Confirmar"
                    onClicked: confirm()
                }
                Button {
                    y:10
                    width: 150
                    text: "Cancelar"
                    onClicked: cancel()
                }
            }
            Text {
                id: alert_message
                anchors.horizontalCenter: parent.horizontalCenter
                visible: false
                color:'red'
                text: qsTr("Preencha os campos obrigatórios")
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
        category_combo_box.enabled = false
        recurrentExpense_no_radio_button.enabled = false
        recurrentExpense_yes_radio_button.enabled = false
        frequency_combo_box.enabled = false
        amount_typed.enabled = false
    }
    function enableAllInputs() {
        name_typed.enabled = true
        date_selected.enabled = true
        category_combo_box.enabled = true
        recurrentExpense_no_radio_button.enabled = true
        recurrentExpense_yes_radio_button.enabled = true
        if (recurrentExpense_yes_radio_button.checked == true){
            frequency_combo_box.enabled = true
        }
        amount_typed.enabled = true
    }
    function confirm() {
        var email = secaoUsuario.getEmailLogado()
        var description = name_typed.text
        var date = date_selected.text
        var category = category_combo_box.currentText
        var frequency
        if (recurrentExpense_yes_radio_button.checked)
            frequency = frequency_combo_box.currentText
        else
            frequency = ""
        var amount = amount_typed.text
        if (amount === "") amount = "0"
        if (expenseType_gain_radio_button.checked) amount *= -1
        if (description !== "") {
            var x = manejarDespesa.inserirDespesa(email, description, date,
                                          category, frequency, amount)
            clearInputs()
            returnToDashboard()
        }
        else
            alert_message.visible = true
    }

    function cancel() {
        clearInputs()
        returnToDashboard()
    }

    function returnToDashboard(){
        stack.pop()
    }

    function showCalendar(){
        date_selected.color = "#000000"
        calendar_rectangle.visible = true
        disableAllInputs()
    }

    function clearInputs() {
        name_typed.text = ""
        expenseType_expense_radio_button.checked = true
        expenseType_gain_radio_button.checked = false
        date_selected.text = ""
        category_combo_box.currentIndex = 0
        recurrentExpense_no_radio_button.checked = true
        recurrentExpense_yes_radio_button.checked = false
        frequency_combo_box.currentIndex = 0
        amount_typed.text = ""
    }
}
