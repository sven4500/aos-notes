import QtQuick 2.0
import Sailfish.Silica 1.0

import DTO 1.0
import "../elements"

Rectangle {
    id: root
    width: Theme.itemSizeMedium
    height: Theme.itemSizeHuge * 1.5
    radius: 20
    border.color: "gray"
    border.width: 2

    states: [
        State {
            name: "TextNoteState"
            when: model.type === DatabaseEntry.TextNote
            PropertyChanges { target: textNotePreview; visible: true }
        },
        State {
            name: "SketchNoteState"
            when: model.type === DatabaseEntry.SketchNote
        },
        State {
            name: "AudioNoteState"
            when: model.type === DatabaseEntry.AudioNote
        }
    ]

    property real maxHeight: Theme.itemSizeExtraLarge

    TextNotePreview {
        id: textNotePreview
        anchors.fill: parent
        anchors.margins: Theme.paddingMedium
        visible: false

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            onClicked: pageStack.push("../pages/TextNotePage.qml",
                                      {noteId: model.id, index: model.index})
        }
    }
}
