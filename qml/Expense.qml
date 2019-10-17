import QtQuick 2.0

Item {
    id: expense
    width: parent.width

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
            spacing: 10
            anchors.horizontalCenter: parent.horizontalCenter
            Text {
                id: currency
                font.pixelSize: 12
            }
            Text {
                id: amount
                font.pixelSize: 12
            }
        }
    }

    function setHeight(value) {expense.height = value}
    function setY(value) {expense.y = value}
    function setDescription(text) {description.text = text}
    function setCurrency(text) {currency.text = text}
    function setCategory(text) {category.text = text}
    function setAmount(text) {amount.text = text}
    function destroy() {expense.destroy()}
}
