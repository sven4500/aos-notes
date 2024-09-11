import QtQuick 2.0
import Sailfish.Silica 1.0

ApplicationWindow {
    id: root
    allowedOrientations: defaultAllowedOrientations
    initialPage: Qt.resolvedUrl("pages/NoteListPage.qml")
    cover: Qt.resolvedUrl("cover/Cover.qml")
}
