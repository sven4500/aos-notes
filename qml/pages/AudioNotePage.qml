import QtMultimedia 5.6
import QtQuick 2.0
import Sailfish.Silica 1.0

import Managers 1.0
import "../elements"

Page {
    id: page
    allowedOrientations: Orientation.All
    showNavigationIndicator: false

    states: [
        State {
            name: "ExistingNoteState"
            when: noteId !== 0
            PropertyChanges { target: playbackControls; visible: true }
            PropertyChanges { target: header; canRemove: true }
            PropertyChanges { target: recordButton; visible: false }
            PropertyChanges { target: recordTimeLabel; visible: false }
            PropertyChanges { target: player; source: _audioNoteViewModel.mediaPath }
        },
        State {
            name: "NewNoteState"
            when: noteId === 0
            PropertyChanges { target: playbackControls;
                visible: recorder.duration > 0 &&
                         recorder.state !== AudioRecorder.RecordingState }
            PropertyChanges { target: header; canRemove: false }
            PropertyChanges { target: recordButton; visible: true }
            PropertyChanges { target: recordTimeLabel; visible: recorder.state === AudioRecorder.RecordingState }
            PropertyChanges { target: player; source: _audioNoteViewModel.outputLocation }
        }
    ]

    property int noteId: 0

    Component.onCompleted: {
        console.log("AudioNotePage", noteId, _audioNoteViewModel.title)

        // INFO: http://imaginativethinking.ca/bi-directional-data-binding-qt-quick/
        header.noteTitle = _audioNoteViewModel.title
    }

    Binding {
        target: _audioNoteViewModel
        property: "id"
        value: noteId
    }

    AudioRecorder {
        id: recorder
        outputLocation: _audioNoteViewModel.outputLocation
    }

    Audio {
        id: player
    }

    Rectangle {
        anchors.fill: parent
        color: "white"
    }

    NoteHeader {
        id: header
        canRemove: noteId !== 0
        onBackClicked: _audioNoteViewModel.insertNote()
        onRemoveClicked: _audioNoteViewModel.removeNote()

        Binding {
            target: _audioNoteViewModel
            property: "title"
            value: header.noteTitle
        }
    }

    Rectangle {
        id: playbackControls
        height: childrenRect.height
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        anchors.margins: Theme.paddingMedium
        //border.color: "red"

        Label {
            id: positionLabel
            anchors.top: parent.top
            anchors.left: slider.left
            text: _audioNoteViewModel.parseTime(player.position)
            font.pixelSize: Theme.fontSizeSmall
            color: "gray"
        }

        Label {
            id: durationLabel
            anchors.top: parent.top
            anchors.right: slider.right
            text: _audioNoteViewModel.parseTime(player.duration)
            font.pixelSize: Theme.fontSizeSmall
            color: "gray"
        }

        ImageButton {
            id: playButton
            anchors.left: parent.left
            anchors.verticalCenter: slider.verticalCenter
            image: player.playbackState === Audio.PlayingState ?
                       Qt.resolvedUrl("../icons/pause.svg") :
                       Qt.resolvedUrl("../icons/play.svg")
            onClicked: player.playbackState === Audio.PlayingState ?
                           player.pause() :
                           player.play()

        }

        Slider {
            id: slider
            anchors.left: playButton.right
            anchors.leftMargin: Theme.paddingMedium
            anchors.right: parent.right
            anchors.top: durationLabel.bottom
            anchors.topMargin: Theme.paddingMedium
            maxValue: player.duration
            onValueChanged: player.seek(value)

            Binding {
                target: slider
                property: "value"
                value: player.position
            }
        }
    }

    ImageButton {
        id: recordButton
        anchors.top: playbackControls.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.margins: Theme.paddingMedium
        radius: height * 0.5
        image: recorder.state === AudioRecorder.RecordingState ?
                   Qt.resolvedUrl("../icons/mute.svg") :
                   Qt.resolvedUrl("../icons/microphone.svg")
        onClicked: recorder.state === AudioRecorder.RecordingState ?
                       recorder.pause() :
                       recorder.record()
    }

    Label {
        id: recordTimeLabel
        anchors.top: recordButton.bottom
        anchors.topMargin: Theme.paddingMedium
        anchors.horizontalCenter: recordButton.horizontalCenter
        text: _audioNoteViewModel.parseTime(recorder.duration)
        color: "gray"
    }
}
