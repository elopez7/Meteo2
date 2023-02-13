

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick 2.15

//import org.esteban.Locations 1.0
Item {
    id: delegate
    width: ListView.view.width
    height: ListView.view.height * 0.2

    Text {
        id: label
        color: "white"
        anchors.top: parent.top
        text: country
        anchors.left: parent.left
        anchors.margins: 24
        font.pixelSize: 24
        anchors.leftMargin: 16
    }
    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: delegate.ListView.view.currentIndex = index
    }

    states: [
        State {
            name: "Highlighted"

            when: delegate.ListView.isCurrentItem
            PropertyChanges {
                target: label
                color: "white"
                font.pixelSize: 24
                font.bold: true
            }
        }
    ]
}
