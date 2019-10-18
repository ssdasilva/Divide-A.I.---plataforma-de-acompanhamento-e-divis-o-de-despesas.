import QtQuick 2.0

Item {
    id: expense
    width: parent.width

    property int position
    signal requestDeletion(int position, string descriptionText)

    Column{
        spacing: 10
        anchors.fill: parent
        anchors.margins: 10

        Row{
            spacing: 10
            anchors.horizontalCenter: parent.horizontalCenter
            Text {
                id: description
                font.pixelSize: 15
            }
            Text {
                id: category
                font.pixelSize: 12
                color: "#cfa556"
                font.bold: true
            }
        }
        Row{
            spacing: 5
            anchors.horizontalCenter: parent.horizontalCenter
            Text {
                id: currency
                font.pixelSize: 12
                text: qsTr("R$")
            }
            Text {
                id: amount
                font.pixelSize: 12
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
    function setCategory(text) {category.text = text}
    function setAmount(text) {amount.text = text}
    function destroy() {expense.destroy()}
}
