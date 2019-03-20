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
        source: ""
        cache: false
        width: 90
        height: 90
    }

    Timer {
        id: updateImgTimer
        interval: 1000
        running: false
        repeat: true
        onTriggered: {

            //hack
            var prevSource = image.source
            image.source = ""
            image.source = "image://fromjson/1"
        }
    }

    ImageFileDialog {
        id: imageFileDialog
        onAccepted: {
            //todo: restart timer. mb stop on open

            var path = imageFileDialog.fileUrl.toString();
            // remove prefixed "file:///"
            path = path.replace(/^(file:\/{3})/,"");
            // unescape html codes like '%23' for '#'
            var cleanPath = decodeURIComponent(path);
            jsonImageModel.filePath = cleanPath
            console.log("accepted " + cleanPath)
            updateImgTimer.start()
        }
        onRejected: {
            console.log("Canceled")
        }
    }

}


