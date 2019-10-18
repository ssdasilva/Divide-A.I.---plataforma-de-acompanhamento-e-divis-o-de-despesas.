import QtQuick 2.0
import QtQuick.Controls 2.12
//import "../js/componentCreation.js" as ComponentCreationScript

Item {
    id: expenseDisplay
    width: parent.width

    property int expenseHeight: 80
    property var expenses: []
    property int numberOfExpenses: 0
    property bool hasLoadedObjects: false
    property int contentY
    property int contentHeight

    function createObjects(){
        if (!hasLoadedObjects){
            var emailLogado = secaoUsuario.getEmailLogado()
            var quantidade = manejarDespesa.quantidadeDespesasUsuario(emailLogado)
            height = expenseHeight*quantidade

            var i;
            for (i=0; i<quantidade; i++){
                var component
                component = Qt.createComponent("Expense.qml")
                expenses[i] = component.createObject(expenseDisplay)
                if (expenses[i] !== null){
                    expenses[i].setHeight(expenseDisplay.height)
                    expenses[i].setY(expenseDisplay.expenseHeight*i)

                    var description = manejarDespesa.getDescricaoDespesaUsuario(emailLogado, i)
                    expenses[i].setDescription(description)
                    var category = manejarDespesa.getCategoriaDespesaUsuario(emailLogado, i)
                    expenses[i].setCategory(category)
                    var amount = manejarDespesa.getQuantiaDespesaUsuario(emailLogado, i)
                    expenses[i].setAmount(amount)
                }
                expenses[i].onRequestDeletion.connect(showDialog)
            }
            numberOfExpenses = quantidade
            hasLoadedObjects = true
        }
    }

    function showDialog(descriptionText){
        confirmDeletionDialog.descriptionText = descriptionText
        confirmDeletionDialog.open()
    }

    Dialog {
        id: confirmDeletionDialog
        x: (parent.width - width) / 2
        y: (contentHeight - height) / 2 + contentY / 2
        modal: true

        standardButtons: Dialog.Yes | Dialog.No
        property string descriptionText
        title: "Você deseja realmente deletar<br/>"+descriptionText+"?"
        onAccepted: console.log("Aceitou o botão ", descriptionText)
        onRejected: console.log("Rejeitou o botão ", descriptionText)

    }

    function deleteObjects(){
        var i
        for (i=0; i<numberOfExpenses; i++){
            expenses[i].destroy()
        }
        numberOfExpenses = 0
        hasLoadedObjects = false
    }
}
