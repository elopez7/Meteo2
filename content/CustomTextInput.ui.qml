import QtQuick 6.4
import QtQuick.Controls 6.4
import QtQuick3D 6.4
import Meteo2
import QtQuick.Layouts 6.3

Rectangle {
    id: rectangle
    width: 200
    height: 200
    color: "#00ffffff"
    Layout.fillHeight: true
    Layout.fillWidth: true

    property string userInput: textField.text

    Item {
        id: __materialLibrary__
    }

    ColumnLayout {
        id: columnLayout
        anchors.fill: parent

        TextField {
            id: textField
            font.pixelSize: 24
            Layout.fillHeight: true
            Layout.fillWidth: true
            verticalAlignment: Text.AlignBottom
            placeholderText: qsTr("Search Location")
            background: Rectangle {
                color: "transparent"
            }
        }

        Rectangle {
            id: line
            width: 200
            height: 200
            color: "#ffffff"
            Layout.maximumHeight: 4
            Layout.minimumHeight: 4
            Layout.preferredHeight: 4
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }
}
