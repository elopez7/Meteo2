import QtQuick 6.4
import QtQuick.Controls 6.4
import QtQuick3D 6.4
import Meteo2
import QtQuick.Layouts 6.3

Item {
    id: cardRoot
    height: 512
    property string cardTitle: "This is a string"
    property real feelsLikeVal: 12
    property real humidityPercentageVal: 12
    property real windSpeedVal: 12
    property real cloudPercentageVal: 12

    Item {
        id: __materialLibrary__
    }

    ColumnLayout {
        id: columnLayout
        anchors.fill: parent
        anchors.rightMargin: 16
        anchors.leftMargin: 16

        Text {
            id: text1
            color: "#ffffff"
            text: qsTr(cardRoot.cardTitle)
            font.pixelSize: 24
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        RowLayout {
            id: rowLayout
            width: 100
            height: 100
            Layout.fillHeight: true
            Layout.fillWidth: true

            Text {
                id: text2
                color: "#ffffff"
                text: qsTr("Feels Like")
                font.pixelSize: 24
                verticalAlignment: Text.AlignVCenter
                Layout.preferredWidth: columnLayout.width * 0.5
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Text {
                id: text3
                color: "#ffffff"
                text: cardRoot.feelsLikeVal
                font.pixelSize: 24
                horizontalAlignment: Text.AlignRight
                verticalAlignment: Text.AlignVCenter
                Layout.preferredWidth: columnLayout.width * 0.5
                Layout.fillHeight: true
                Layout.fillWidth: true
            }
        }

        RowLayout {
            id: rowLayout1
            width: 100
            height: 100
            Layout.fillHeight: true
            Layout.fillWidth: true

            Text {
                id: text4
                color: "#ffffff"
                text: qsTr("Humidity")
                font.pixelSize: 24
                verticalAlignment: Text.AlignVCenter
                Layout.preferredWidth: columnLayout.width * 0.5
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Text {
                id: text5
                color: "#ffffff"
                text: cardRoot.humidityPercentageVal
                font.pixelSize: 24
                horizontalAlignment: Text.AlignRight
                verticalAlignment: Text.AlignVCenter
                Layout.preferredWidth: columnLayout.width * 0.5
                Layout.fillHeight: true
                Layout.fillWidth: true
            }
        }

        RowLayout {
            id: rowLayout2
            width: 100
            height: 100
            Layout.fillHeight: true
            Layout.fillWidth: true

            Text {
                id: text6
                color: "#ffffff"
                text: qsTr("Wind")
                font.pixelSize: 24
                verticalAlignment: Text.AlignVCenter
                Layout.preferredWidth: columnLayout.width * 0.5
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Text {
                id: text7
                color: "#ffffff"
                text: cardRoot.windSpeedVal
                font.pixelSize: 24
                horizontalAlignment: Text.AlignRight
                verticalAlignment: Text.AlignVCenter
                Layout.preferredWidth: columnLayout.width * 0.5
                Layout.fillHeight: true
                Layout.fillWidth: true
            }
        }

        RowLayout {
            id: rowLayout3
            width: 100
            height: 100

            Text {
                id: text8
                color: "#ffffff"
                text: qsTr("Clouds")
                font.pixelSize: 24
                verticalAlignment: Text.AlignVCenter
                Layout.preferredWidth: columnLayout.width * 0.5
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Text {
                id: text9
                color: "#ffffff"
                text: cardRoot.cloudPercentageVal
                font.pixelSize: 24
                horizontalAlignment: Text.AlignRight
                verticalAlignment: Text.AlignVCenter
                Layout.preferredWidth: columnLayout.width * 0.5
                Layout.fillHeight: true
                Layout.fillWidth: true
            }
        }
    }
}
