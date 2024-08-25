import QtQuick 2.0
import Sailfish.Silica 1.0

Item {
    id: root
    width: Theme.iconSizeMedium
    height: Theme.iconSizeMedium

    property alias image: image.source
    signal clicked()

    Image {
        id: image
        anchors.fill: parent
        sourceSize.width: width
        sourceSize.height: height
    }

    MouseArea {
        anchors.fill: parent
        onClicked: root.clicked()
    }
}
