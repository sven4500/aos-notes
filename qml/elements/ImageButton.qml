import QtQuick 2.0
import Sailfish.Silica 1.0

Rectangle {
    id: root
    width: Theme.iconSizeMedium
    height: Theme.iconSizeMedium
    color: "transparent"
    border { color: "#ff0000" }

    property alias image: image.source
    signal clicked()

    Image {
        id: image
        anchors.centerIn: parent
        sourceSize.width: root.width * 0.8
        sourceSize.height: root.height * 0.8
    }

    MouseArea {
        anchors.fill: parent
        onClicked: root.clicked()
    }
}
