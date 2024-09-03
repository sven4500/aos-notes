import QtQuick 2.0
import Sailfish.Silica 1.0

Rectangle {
    id: root
    width: parent.width
    height: Theme.itemSizeMedium
    anchors.top: parent.top
    color: "white"
    border { width: 1; color: "red" }

    property string noteTitle: noteTitle.text.length !== 0 ? noteTitle.text : defaultNoteTitle
    readonly property string defaultNoteTitle: qsTr("New note") + " " + Qt.formatDateTime(new Date(), "yyyy.MM.dd hh:mm")

    signal backClicked()

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
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        anchors.margins: Theme.paddingMedium
        placeholderText: defaultNoteTitle
        color: "black"
        placeholderColor: "gray"
        labelVisible: false
        backgroundStyle: TextEditor.UnderlineBackground
    }
}
