import QtQuick 2.0
import Sailfish.Silica 1.0

Rectangle {
    id: root
    clip: true

    Label {
        id: body
        anchors.fill: parent
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
        truncationMode: TruncationMode.Fade
        clip: true
        color: "gray"
    }
}
