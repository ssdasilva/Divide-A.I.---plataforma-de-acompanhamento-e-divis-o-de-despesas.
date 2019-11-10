import QtQuick 2.0
import QtTest 1.12
import "../qml"

Rectangle {
    id: root
    width: 640
    height: 480

    TestCase {
        name: "UnitTestGustavo"

        function test_login(){
            var component = Qt.createComponent("Expense.qml")
            var item = component.createObject(root)
            item.logIn()
        }

    }
}

