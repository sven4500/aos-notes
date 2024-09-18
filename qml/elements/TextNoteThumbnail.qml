import QtQuick 2.0
import Sailfish.Silica 1.0

Rectangle {
    id: root
    anchors.fill: parent
    clip: true
    //border { color: "red" }

    Label {
        id: title
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        color: "black"
        text: model.title
    }

    Label {
        id: body
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: title.bottom
        anchors.bottom: dateTime.top
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
        truncationMode: TruncationMode.Fade
        clip: true
        color: "gray"
    }

    Label {
        id: dateTime
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        color: "gray"
        text: Qt.formatDateTime(model.modifiedAt, "yyyy.MM.dd hh:mm")
        font.pixelSize: Theme.fontSizeSmall
    }
}
