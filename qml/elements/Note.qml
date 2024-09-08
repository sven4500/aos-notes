import QtQuick 2.0
import Sailfish.Silica 1.0

Rectangle {
    id: root
    width: Theme.itemSizeMedium
    height: Theme.itemSizeExtraLarge
    radius: 20
    border.color: "gray"
    border.width: 2

    property real maxHeight: Theme.itemSizeExtraLarge

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
