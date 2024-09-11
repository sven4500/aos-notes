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

    ApplicationHeader {
        id: header
    }

    Text {
        anchors.top: header.bottom
        anchors.bottom: footer.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: Theme.paddingMedium
        text: qsTr("No notes have been made at this time. Click any button below to create a note.")
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        wrapMode: Text.WordWrap
        color: "gray"
        visible: _listViewModel.length === 0
    }

    SilicaFlickable {
        anchors.top: header.bottom
        anchors.bottom: footer.top
        anchors.left: parent.left
        anchors.leftMargin: Theme.paddingMedium
        anchors.right: parent.right
        anchors.rightMargin: Theme.paddingMedium
        //contentWidth: flow.childrenRect.width
        contentHeight: flow.childrenRect.height
        clip: true

        // INFO: https://stackoverflow.com/questions/60316465/is-it-possible-to-display-items-from-a-data-model-in-a-flow-layout
        Grid {
            id: flow
            width: parent.width
            spacing: Theme.paddingMedium
            columns: 2

            property int columnCount: 2

            Repeater {
                model: _listViewModel
                delegate: NotePreview {
                    width: flow.width * 0.5 - flow.spacing * (flow.columnCount - 1)
                }
            }
        }
    }

    Footer {
        id: footer
    }
}
