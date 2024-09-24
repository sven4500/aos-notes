import QtQuick 2.0
import Sailfish.Silica 1.0

import DTO 1.0
import "../elements"

Rectangle {
    id: root
    width: Theme.itemSizeMedium
    height: Theme.itemSizeHuge
    clip: true
    radius: 20
    border.color: "gray"
    border.width: 2

    states: [
        State {
            name: "TextNoteState"
            when: model.type === DatabaseEntry.TextNote
            PropertyChanges { target: textNoteThumbnail; visible: true }
            PropertyChanges { target: mouseArea; onClicked: pageStack.push("../pages/TextNotePage.qml",
                                                                           {noteId: model.id}) }
            PropertyChanges { target: image; source: Qt.resolvedUrl("../icons/pen.svg") }
        },
        State {
            name: "SketchNoteState"
            when: model.type === DatabaseEntry.SketchNote
            PropertyChanges { target: sketchNoteThumbnail; visible: true }
            PropertyChanges { target: mouseArea; onClicked: pageStack.push("../pages/SketchNotePage.qml",
                                                                           {noteId: model.id}) }
            PropertyChanges { target: image; source: Qt.resolvedUrl("../icons/marker.svg") }
        },
        State {
            name: "AudioNoteState"
            when: model.type === DatabaseEntry.AudioNote
            PropertyChanges { target: audioNoteThumbnail; visible: true }
            PropertyChanges { target: mouseArea; onClicked: pageStack.push("../pages/AudioNotePage.qml",
                                                                           {noteId: model.id}) }
            PropertyChanges { target: image; source: Qt.resolvedUrl("../icons/tape.svg") }
        }
    ]

    property real maxHeight: Theme.itemSizeExtraLarge

    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }

    Label {
        id: title
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.margins: Theme.paddingMedium
        truncationMode: TruncationMode.Fade
        color: "black"
        text: model.title
    }

    Item {
        anchors.top: title.bottom
        anchors.bottom: dateTime.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: Theme.paddingMedium

        TextNoteThumbnail {
            id: textNoteThumbnail
            anchors.fill: parent
            visible: false
            //border { color: "red" }
        }

        AudioNoteThumbnail {
            id: audioNoteThumbnail
            anchors.fill: parent
            visible: false
            //border { color: "red" }
        }

        SketchNoteThumbnail {
            id: sketchNoteThumbnail
            anchors.fill: parent
            visible: false
            //border { color: "red" }
        }
    }

    Image {
        id: image
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.margins: Theme.paddingMedium
        sourceSize.width: Theme.iconSizeSmall
        sourceSize.height: Theme.iconSizeSmall
    }

    Label {
        id: dateTime
        anchors.left: image.right
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: Theme.paddingMedium
        horizontalAlignment: Text.AlignRight
        truncationMode: TruncationMode.Fade
        color: "gray"
        text: Qt.formatDateTime(model.modifiedAt, "yyyy.MM.dd hh:mm")
        font.pixelSize: Theme.fontSizeSmall
    }
}
