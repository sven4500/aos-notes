import QtQuick 2.0
import Sailfish.Silica 1.0

import "../elements"

Page {
    id: page
    allowedOrientations: Orientation.All
    showNavigationIndicator: false

    property int noteId: 0

    Rectangle {
        anchors.fill: parent
        color: "white"
    }

    NoteHeader {
        id: header
        canRemove: noteId !== 0
    }

    ImageButton {
        id: playButton
        anchors.verticalCenter: parent.verticalCenter
        anchors.margins: Theme.paddingMedium
        image: Qt.resolvedUrl("../icons/play.svg")
    }

    Slider {
        id: slider
        anchors.left: playButton.right
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        anchors.margins: Theme.paddingMedium
    }

    ImageButton {
        anchors.top: slider.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.margins: Theme.paddingMedium
        image: Qt.resolvedUrl("../icons/microphone.svg")
    }
}
