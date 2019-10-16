import QtQuick 2.0
//import "../js/componentCreation.js" as ComponentCreationScript

Item {
    id: expenseDisplay

    function createObjects(){
        var emailLogado = secaoUsuario.getEmailLogado()
        var quantidade = manejarDespesa.quantidadeDespesasUsuario(emailLogado)
        var i;
        for (i=0; i<quantidade; i++){
            var component, expense
            component = Qt.createComponent("Expense.qml")
            expense = component.createObject(expenseDisplay)
            if (expense !== null){
                expense.setColor("#ff5555")
                expense.setY(70*i)
            }
        }
    }
}
