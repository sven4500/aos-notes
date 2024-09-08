import QtQuick 2.0
import Sailfish.Silica 1.0

import "../elements"

Rectangle {
    id: root
    width: parent.width
    height: Theme.itemSizeMedium
    anchors.bottom: parent.bottom
    color: "white"
    //border { width: 1; color: "red" }

    ImageButton {
        id: writeButton
        anchors.left: parent.left
        anchors.leftMargin: Theme.paddingMedium
        anchors.verticalCenter: parent.verticalCenter
        image: Qt.resolvedUrl("../icons/pen.svg")
        onClicked: pageStack.push(Qt.resolvedUrl("../pages/TextNotePage.qml"))
    }

    ImageButton {
        id: sketchButton
        anchors.left: writeButton.right
        anchors.leftMargin: Theme.paddingMedium
        anchors.verticalCenter: parent.verticalCenter
        image: Qt.resolvedUrl("../icons/marker.svg")
    }

    ImageButton {
        id: recordButton
        anchors.left: sketchButton.right
        anchors.leftMargin: Theme.paddingMedium
        anchors.verticalCenter: parent.verticalCenter
        image: Qt.resolvedUrl("../icons/tape.svg")
    }
}
