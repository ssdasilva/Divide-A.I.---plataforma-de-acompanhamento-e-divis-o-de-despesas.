import QtQuick 2.0

Item {
    Rectangle {
        id: rectangle
        width: 50
        height: 50
        color: "#4444ff"
    }

    function setColor(x){
        rectangle.color = x
    }

    function setY(y){
        this.y = y
    }
}
