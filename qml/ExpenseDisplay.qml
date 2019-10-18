import QtQuick 2.0
//import "../js/componentCreation.js" as ComponentCreationScript

Item {
    id: expenseDisplay
    width: parent.width

    property int expenseHeight: 80
    property var expenses: []
    property int numberOfExpenses: 0
    property bool hasLoadedObjects: false

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
            }
            numberOfExpenses = quantidade
            hasLoadedObjects = true
        }
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
