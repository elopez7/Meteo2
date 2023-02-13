import QtQuick 6.4
import QtQuick.Controls 6.4
import QtQuick3D 6.4
import Meteo2
import QtQuick.Layouts 6.3
import org.esteban.data 1.0

RowLayout {
    id: searchField
    width: 768
    height: 128

    Item {
        id: __materialLibrary__
    }

    CustomTextInput {
        id: myTextInput
    }

    Button {
        id: button
        text: qsTr("Button")
        Layout.maximumHeight: 128
        Layout.maximumWidth: 128
        Layout.minimumHeight: 128
        Layout.minimumWidth: 128
        Layout.preferredHeight: 128
        icon.height: 64
        icon.width: 64
        icon.source: "images/searchIcon.svg"
        display: AbstractButton.IconOnly
        Layout.preferredWidth: 128
        Layout.fillHeight: true
        Layout.fillWidth: true
        background: Rectangle {
            color: "orange"
        }
        Connections {
            target: button
            onClicked: DataSource.onSearchButtonPressed(myTextInput.userInput)
        }
    }

}
