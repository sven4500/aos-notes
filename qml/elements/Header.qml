import QtQuick 2.0
import Sailfish.Silica 1.0

import ViewModels 1.0
import "../elements"

Rectangle {
    id: root
    width: parent.width
    height: Theme.itemSizeMedium
    anchors.top: parent.top
    color: "white"
    border { width: 1; color: "red" }

    states: [
        State {
            name: "MainHeaderState"; when: headerType === HeaderViewModel.MainHeader
        },
        State {
            name: "NoteHeaderState"; when: headerType === HeaderViewModel.NoteHeader
            PropertyChanges { target: applicationName; visible: false }
            PropertyChanges { target: backButton; visible: true }
            PropertyChanges { target: noteTitle; visible: true }
        }
    ]

    property int headerType: HeaderViewModel.MainHeader

    ImageButton {
        id: backButton
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        anchors.margins: Theme.paddingMedium
        image: Qt.resolvedUrl("../icons/back.svg")
        visible: false
        onClicked: pageStack.pop()
    }

    Text {
        id: applicationName
        anchors.left: parent.left
        anchors.leftMargin: Theme.paddingMedium
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: Theme.fontSizeLarge
        text: qsTr("Notes")
    }

    TextField {
        id: noteTitle
        anchors.left: backButton.right
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        anchors.margins: Theme.paddingMedium
        text: _headerViewModel.noteTitle.length !== 0 ? _headerViewModel.noteTitle : qsTr("New note")
        labelVisible: false
        color: "black"
        backgroundStyle: TextEditor.UnderlineBackground
        visible: false
    }
}
