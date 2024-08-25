import QtQuick 2.0
import Sailfish.Silica 1.0

import "../elements"

Page {
    id: page
    allowedOrientations: Orientation.All

    Rectangle {
        anchors.fill: parent
        color: "white"
    }

    Header {
        id: header
    }

    Text {
        anchors.top: header.bottom
        anchors.bottom: footer.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: Theme.paddingLarge
        text: qsTr("No notes have been made at this time. Click any button below to create a note.")
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        wrapMode: Text.WordWrap
        color: "gray"
    }

    Footer {
        id: footer
    }
}
