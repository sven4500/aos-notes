import QtQuick 2.0
import Sailfish.Silica 1.0

import ViewModels 1.0
import "../elements"

Page {
    id: page
    allowedOrientations: Orientation.All
    showNavigationIndicator: false

    Rectangle {
        anchors.fill: parent
        color: "white"
    }

    Header {
        id: header
        headerType: HeaderViewModel.NoteHeader
    }

    TextArea {
        id: textArea
        width: parent.width
        anchors.top: header.bottom
        anchors.bottom: parent.bottom
        anchors.margins: Theme.paddingMedium
        backgroundStyle: TextEditor.NoBackground
        placeholderText: qsTr("Enter text...")
        placeholderColor: "gray"
        color: "black"
    }
}
