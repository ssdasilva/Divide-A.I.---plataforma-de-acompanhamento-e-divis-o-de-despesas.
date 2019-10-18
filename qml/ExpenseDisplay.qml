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

    signal requestHeightReduction(int expenseHeight)

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
                    var date = manejarDespesa.getDataDespesaUsuario(emailLogado, i)
                    expenses[i].setDate(date)
                    var frequency = manejarDespesa.getFrequenciaDespesaUsuario(emailLogado, i)
                    expenses[i].setFrequency(frequency)
                    var amount = manejarDespesa.getQuantiaDespesaUsuario(emailLogado, i)
                    expenses[i].setAmount(amount)
                }
                expenses[i].position = i
                expenses[i].onRequestDeletion.connect(showDialog)
            }
            numberOfExpenses = quantidade
            hasLoadedObjects = true
        }
    }

    function showDialog(position, descriptionText){
        confirmDeletionDialog.position = position
        confirmDeletionDialog.descriptionText = descriptionText
        confirmDeletionDialog.open()
    }

    Dialog {
        id: confirmDeletionDialog
        x: (parent.width - width) / 2
        y: (contentHeight - height) / 2 + contentY / 2
        modal: true

        standardButtons: Dialog.Yes | Dialog.No
        property int position
        property string descriptionText
        title: "Você deseja realmente deletar<br/>"+descriptionText+"?"
        onAccepted: deleteExpense(position, descriptionText)

    }

    function deleteExpense(position, descriptionText){
        var emailLogado = secaoUsuario.getEmailLogado()
        manejarDespesa.removerDespesa(emailLogado, descriptionText)
        expenses[position].destroy()
        var i
        for (i=position; i<numberOfExpenses-1; i++){
            expenses[i] = expenses[i+1]
            expenses[i].setY(expenseHeight*i)
        }
        numberOfExpenses--
        height -= expenseHeight
        requestHeightReduction(expenseHeight)
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
