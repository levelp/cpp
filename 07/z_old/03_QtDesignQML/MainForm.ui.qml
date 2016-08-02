import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {
    width: 640
    height: 480

    property alias button3: exit
    property alias button1: concatButton

    RowLayout {
        anchors.centerIn: parent

        Button {
            id: concatButton
            text: qsTr("Конкатенация")
            scale: 1
        }

        Button {
            id: exit
            text: qsTr("Выход")
        }
    }

    TextInput {
        id: textInput1
        x: 224
        y: 69
        width: 139
        height: 18
        text: qsTr("Text Input")
        font.family: "Verdana"
        font.pixelSize: 15
    }

    TextInput {
        id: textInput2
        x: 229
        y: 133
        width: 139
        height: 22
        text: qsTr("Text Input")
        font.family: "Verdana"
        font.pixelSize: 18
    }

    TextEdit {
        id: resultEdit
        x: 229
        y: 175
        width: 139
        height: 20
        text: qsTr("Text Edit")
        font.pixelSize: 12
    }
}
