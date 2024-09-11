import QtQuick 2.0
import Sailfish.Silica 1.0

Rectangle {
    id: root
    width: parent.width
    height: Theme.itemSizeMedium
    anchors.top: parent.top
    color: "white"
    //border { width: 1; color: "red" }

    // INFO: https://stackoverflow.com/questions/34592916/qml-property-hooks
    property alias noteTitle: noteTitle.text

    signal backClicked()
    signal removeClicked()

    ImageButton {
        id: backButton
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        anchors.margins: Theme.paddingMedium
        image: Qt.resolvedUrl("../icons/back.svg")
        onClicked: {
            backClicked()
            pageStack.pop()
        }
    }

    TextField {
        id: noteTitle
        anchors.left: backButton.right
        anchors.right: removeButton.left
        anchors.verticalCenter: parent.verticalCenter
        anchors.margins: Theme.paddingMedium
        placeholderText: qsTr("Note title...")
        color: "black"
        placeholderColor: "gray"
        labelVisible: false
        backgroundStyle: TextEditor.UnderlineBackground
    }

    ImageButton {
        id: removeButton
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        anchors.margins: Theme.paddingMedium
        image: Qt.resolvedUrl("../icons/bin.svg")
        onClicked: {
            removeClicked()
            pageStack.pop()
        }
    }
}
