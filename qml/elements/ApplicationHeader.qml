import QtQuick 2.0
import Sailfish.Silica 1.0

Rectangle {
    id: root
    width: parent.width
    height: Theme.itemSizeMedium
    anchors.top: parent.top
    color: "white"
    border { width: 1; color: "red" }

    Text {
        id: applicationName
        anchors.left: parent.left
        anchors.leftMargin: Theme.paddingMedium
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: Theme.fontSizeLarge
        text: qsTr("Notes")
    }
}
