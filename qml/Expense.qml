import QtQuick 2.0

Item {
    id: expense
    width: parent.width

    property int position
    property string frequency: ""
    property int amount: 0
    signal requestDeletion(int position, string descriptionText)

    Column{
        spacing: 10
        height: parent.height
        width: parent.width < 250? parent.width : 250
        anchors.centerIn: parent
        anchors.margins: 10

        Rectangle{
            anchors.left: parent.left
            height: childrenRect.height
            width: parent.width
            Text {
                id: description
                anchors.left: parent.left
                font.pixelSize: 15
            }
            Text {
                id: category
                anchors.left: description.right
                anchors.leftMargin: 10
                font.pixelSize: 12
                color: "#cfa556"
                font.bold: true
            }
            Text {
                id: dateText
                anchors.right: parent.right
                font.pixelSize: 12
                text: "04/05/2019"
            }
        }
        Row{
            spacing: 5
            anchors.left: parent.left
            Text {
                id: amountText
                font.pixelSize: 12
                font.bold: true
                text: {
                    if (amount > 0)
                        return "Despesa de R$"+amount
                    else
                        return "Entrada de R$"+(amount*-1)
                }
                color: {
                    if (amount > 0)
                        return "#eb0808"
                    else
                        return "#2e7610"
                }
            }
        }
        Row {
            spacing: 5
            anchors.left: parent.left
            Text {
                id: frequencyText
                font.pixelSize: 12
                text: {
                    if (frequency === "")
                        return "Gasto único"
                    else
                        return "Frequência: "+frequency
                }
            }
        }
    }

    Botao {
        id: deleteExpense
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.topMargin: 10
        anchors.rightMargin: 20
        height: 30
        width: 80
        lbFonte: 10

        textoBotao: qsTr("Deletar")

        onClicouBotao: {
            requestDeletion(position, description.text)
        }
    }

    function setHeight(value) {expense.height = value}
    function setY(value) {expense.y = value}
    function setDescription(text) {description.text = text}
    function setDate(text) {dateText.text = text}
    function setCategory(text) {category.text = text}
    function setFrequency(text) {frequency = text}
    function setAmount(text) {amount = text}
    function destroy() {expense.destroy()}
}
