import QtQuick 2.0
import Sailfish.Silica 1.0

Item {
    id: root
    anchors.fill: parent
    clip: true

    Text {
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.margins: Theme.paddingMedium
        text: model.title
    }

    Text {
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: Theme.paddingMedium
        text: model.modifiedAt
    }
}
