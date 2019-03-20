import QtQuick 2.0
import QtQuick.Dialogs 1.2

FileDialog {
    id: imageFileDialog
    title: "Please choose a file"
    folder: shortcuts.home
//    Component.onCompleted: visible = false

}
