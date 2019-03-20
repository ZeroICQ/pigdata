import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12
import Qt.labs.calendar 1.0
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("pigdata visualizer")

    menuBar: MenuBar {
        id: menuBar

        Menu {
            id: fileMenu
            title: qsTr("&File")

            MenuItem {
                text: qsTr("Open")
                onTriggered:imageFileDialog.open()
            }

        }

        Menu {
            id: editMenu
            title: qsTr("&Edit")
        }

        Menu {
            id: viewMenu
            title: qsTr("&View")

        }

        Menu {
            id: helpMenu
            title: qsTr("&Help")
        }
    }

    ImageFileDialog {
        id: imageFileDialog
        onAccepted: {
            console.log("Canceled")
            Qt.quit()
        }
    }

}


