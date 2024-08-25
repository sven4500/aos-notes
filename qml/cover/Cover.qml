import QtQuick 2.0
import Sailfish.Silica 1.0

CoverBackground {
    id: root

    Image {
        anchors.centerIn: parent
        source: Qt.resolvedUrl("../icons/notes-cover.svg")
        sourceSize {
            width: root.width * 0.8
            height: root.height * 0.8
        }
    }
}
