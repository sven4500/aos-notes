import QtQuick 2.0
import Sailfish.Silica 1.0

import "../elements"

Rectangle {
    id: root
    width: parent.width
    height: Theme.itemSizeMedium
    anchors.top: parent.top
    color: "white"
    //border { width: 1; color: "red" }

    Text {
        anchors.left: parent.left
        anchors.leftMargin: Theme.paddingLarge
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: Theme.fontSizeExtraLarge
        text: qsTr("Notes")
    }
}
