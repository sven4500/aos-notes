import QtQuick 2.0
import Sailfish.Silica 1.0

import QmlItems 1.0
import "../elements"

Page {
    id: page
    allowedOrientations: Orientation.All
    showNavigationIndicator: false
    backNavigation: false

    property int noteId: 0

    Component.onCompleted: {
        console.log("SketchNotePage", noteId)

        header.noteTitle = _sketchNoteViewModel.title
        sketchItem.image = _sketchNoteViewModel.image
    }

    Binding {
        target: _sketchNoteViewModel
        property: "id"
        value: noteId
    }

    Rectangle {
        anchors.fill: parent
        color: "white"
    }

    NoteHeader {
        id: header
        canRemove: noteId !== 0
        onBackClicked: _sketchNoteViewModel.insertNote()
        onRemoveClicked: _sketchNoteViewModel.removeNote()

        Binding {
            target: _sketchNoteViewModel
            property: "title"
            value: header.noteTitle
        }
    }

    SketchItem {
        id: sketchItem
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: header.bottom
        anchors.topMargin: Theme.paddingMedium
        anchors.bottom: parent.bottom
        anchors.bottomMargin: Theme.paddingMedium

        Binding {
            target: _sketchNoteViewModel
            property: "grab"
            value: sketchItem.grab
        }

        Binding {
            target: _sketchNoteViewModel
            property: "empty"
            value: sketchItem.empty
        }
    }
}
