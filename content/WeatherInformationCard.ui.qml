import QtQuick 6.4
import QtQuick.Controls 6.4
import QtQuick3D 6.4
import Meteo2
import QtQuick.Layouts 6.3

Item {
    id: weatherInformationFlickable
    width: 768
    height: 1024

    Item {
        id: __materialLibrary__
    }

    Rectangle {
        id: background
        color: "#ffffff"
        anchors.fill: parent
    }

    Flickable {
        id: flickable
        anchors.fill: parent
        pixelAligned: true
        flickableDirection: Flickable.VerticalFlick
        contentHeight: columnLayout.childrenRect.height
        clip: true

        ColumnLayout {
            id: columnLayout
            anchors.fill: parent

            Rectangle {
                id: rectangle
                width: 200
                height: 200
                color: "#ff0000"
                Layout.minimumHeight: 512
                Layout.minimumWidth: 250
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Rectangle {
                id: rectangle1
                width: 200
                height: 200
                color: "#1000ff"
                Layout.minimumHeight: 250
                Layout.minimumWidth: 250
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Rectangle {
                id: rectangle2
                width: 200
                height: 200
                color: "#02ff00"
                Layout.minimumHeight: 250
                Layout.minimumWidth: 250
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Rectangle {
                id: rectangle3
                width: 200
                height: 200
                color: "#d8ff00"
                Layout.minimumHeight: 250
                Layout.minimumWidth: 250
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Rectangle {
                id: rectangle4
                width: 200
                height: 200
                color: "#ffffff"
                Layout.minimumHeight: 250
                Layout.minimumWidth: 250
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Rectangle {
                id: rectangle5
                width: 200
                height: 200
                color: "#ff0000"
                Layout.minimumHeight: 250
                Layout.minimumWidth: 250
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Rectangle {
                id: rectangle6
                width: 200
                height: 200
                color: "#1000ff"
                Layout.minimumHeight: 250
                Layout.minimumWidth: 250
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Rectangle {
                id: rectangle7
                width: 200
                height: 200
                color: "#02ff00"
                Layout.minimumHeight: 250
                Layout.minimumWidth: 250
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Rectangle {
                id: rectangle8
                width: 200
                height: 200
                color: "#d8ff00"
                Layout.minimumHeight: 250
                Layout.minimumWidth: 250
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Rectangle {
                id: rectangle9
                width: 200
                height: 200
                color: "#f900ff"
                Layout.minimumHeight: 512
                Layout.minimumWidth: 250
                Layout.fillHeight: true
                Layout.fillWidth: true
            }
        }
    }
}
