import QtQuick 2.0
import Sailfish.Silica 1.0

import "../elements"

Page {
    id: page
    allowedOrientations: Orientation.All
    showNavigationIndicator: false

    property int noteId: 0

    Component.onCompleted: {
        console.log("TextNotePage", noteId, _textNoteViewModel.title)

        // INFO: http://imaginativethinking.ca/bi-directional-data-binding-qt-quick/
        header.noteTitle = _textNoteViewModel.title
        textArea.text = _textNoteViewModel.body
    }

    Binding {
        target: _textNoteViewModel
        property: "id"
        value: noteId
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

    NoteHeader {
        id: header
        canRemove: noteId !== 0
        onBackClicked: _textNoteViewModel.insertNote()
        onRemoveClicked: _textNoteViewModel.removeNote()
    }

    TextArea {
        id: textArea
        width: parent.width
        anchors.top: header.bottom
        anchors.bottom: parent.bottom
        anchors.margins: Theme.paddingMedium
        backgroundStyle: TextEditor.NoBackground
        placeholderText: qsTr("Note text...")
        placeholderColor: "gray"
        color: "black"
    }
}
