

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick 2.15

import org.esteban.meteoApp 1.0
ListView {
    id: view
    width: 420
    height: 420
    interactive: false

    highlightMoveDuration: 0

    model: LocationModel

    highlight: Rectangle {
        width: view.width
        height: 120
        color: "#29ffffff"
        radius: 4
    }

    delegate: CountriesDelegate {
    }
}
