import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12
import Qt.labs.calendar 1.0
import QtQuick.Dialogs 1.2
import Qt.labs.settings 1.1

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("pigdata visualizer")

    Settings {
        id: settings
        category: "QQControlsFileDialog"
        property bool sidebarVisible: false
    }

    menuBar: MenuBar {
        id: menuBar
        anchors.top: window.bottom
        Menu {
            id: fileMenu
            title: qsTr("&File")

            MenuItem {
                text: qsTr("&Open")
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


    Image {
        id: image
        source: "image://fromjson/1"
        cache: false
    }

    Timer {
        interval: 1000
        running: true
        repeat: true
        onTriggered: {
//            console.log("interval fired" + image.source)
            console.log(jsonImageModel.filePath)
            //hack
            var prevSource = image.source
        }
    }

    ImageFileDialog {
        id: imageFileDialog
        onAccepted: {
            jsonImageModel.filePath = qsTr(imageFileDialog.fileUrl.toString())
            console.log(jsonImageModel.filePath)
        }
        onRejected: {
            console.log("Canceled")
        }
    }

}


