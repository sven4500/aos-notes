import QtQuick 2.0
import Sailfish.Silica 1.0

import ViewModels 1.0
import "../elements"

Page {
    id: page
    allowedOrientations: Orientation.All
    showNavigationIndicator: false

    property int id: 0

    Binding {
        target: _textNoteViewModel
        property: "id"
        value: id
    }

    Binding {
        target: _textNoteViewModel
        property: "title"
        value: header.noteTitle
    }

    Binding {
        target: _textNoteViewModel
        property: "body"
        value: textArea.text
    }

    Rectangle {
        anchors.fill: parent
        color: "white"
    }

    Header {
        id: header
        headerType: AbstractNoteViewModel.NoteHeader
        onBackClicked: _textNoteViewModel.saveNote()
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
