import QtQuick 2.0
//import "../js/componentCreation.js" as ComponentCreationScript

Item {
    id: expenseDisplay
    width: parent.width

    property int expenseHeight: 80
    property var expenses: []
    property int numberOfExpenses: 0

    function createObjects(){
        var emailLogado = secaoUsuario.getEmailLogado()
        var quantidade = manejarDespesa.quantidadeDespesasUsuario(emailLogado)
        expenseDisplay.height = expenseDisplay.expenseHeight*quantidade

        var i;
        for (i=0; i<quantidade; i++){
            var component
            component = Qt.createComponent("Expense.qml")
            expenseDisplay.expenses[i] = component.createObject(expenseDisplay)
            if (expenseDisplay.expenses[i] !== null){
                expenseDisplay.expenses[i].setHeight(expenseDisplay.height)
                expenseDisplay.expenses[i].setY(expenseDisplay.expenseHeight*i)

                var description = manejarDespesa.getDescricaoDespesaUsuario(emailLogado, i)
                expenseDisplay.expenses[i].setDescription(description)
                var category = manejarDespesa.getCategoriaDespesaUsuario(emailLogado, i)
                expenseDisplay.expenses[i].setCategory(category)
                var currency = manejarDespesa.getMoedaDespesaUsuario(emailLogado, i)
                expenseDisplay.expenses[i].setCurrency(currency)
                var amount = manejarDespesa.getQuantiaDespesaUsuario(emailLogado, i)
                expenseDisplay.expenses[i].setAmount(amount)
            }
        }
        expenseDisplay.numberOfExpenses = quantidade
    }

    function deleteObjects(){
        var i
        for (i=0; i<expenseDisplay.numberOfExpenses; i++){
            expenseDisplay.expenses[i].destroy()
        }
        expenseDisplay.numberOfExpenses = 0
    }
}
