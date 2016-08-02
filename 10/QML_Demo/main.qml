import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.1
import QtQuick.Controls 1.2

Window {
    visible: true


    MainForm {
        anchors.fill: parent
        mouseArea.onClicked: {
            Qt.quit();
        }
        Button {
            text: "Attach"
            menu: Menu {
                MenuItem { text: "Image" }
                MenuItem { text: "Document" }
            }
        }
    }
}
