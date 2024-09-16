import QtQuick 2.0
import Sailfish.Silica 1.0

Rectangle {
    id: root
    width: Theme.itemSizeHuge
    height: Theme.itemSizeExtraSmall * 0.35
    color: "transparent"
    //border { color: "red" }

    property alias enabled: mouseArea.enabled
    property int value: 0
    property int maxValue: 100

    Rectangle {
        id: slider
        x: pin.width * 0.5
        width: parent.width - pin.width
        height: parent.height * 0.35
        anchors.verticalCenter: parent.verticalCenter
        color: "lightGray"
    }

    Rectangle {
        id: pin
        x: (parent.width - width) * value / maxValue
        width: parent.height
        height: parent.height
        radius: height * 0.5
        color: "gray"

//        MouseArea {
//            anchors.fill: parent
//            drag.target: parent
//            drag.axis: Drag.XAxis
//        }
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: root.value = root.maxValue * (mouse.x / width)
    }
}
