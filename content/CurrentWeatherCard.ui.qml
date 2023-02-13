import QtQuick 6.4
import QtQuick.Controls 6.4
import QtQuick3D 6.4
import Meteo2
import QtQuick.Layouts 6.3
import Quick3DAssets.PipeHouse 1.0

Item {
    id: currentWeatherCard
    width: 768
    height: 256

    RowLayout {
        id: rowLayout
        anchors.fill: parent

        Text {
            id: text1
            width: 102
            height: 107
            color: "#ffffff"
            text: qsTr("16°")
            font.pixelSize: 168
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            fontSizeMode: Text.Fit
            font.bold: true
            Layout.maximumWidth: 256
            Layout.minimumHeight: 256
            Layout.minimumWidth: 256
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        ColumnLayout {
            id: columnLayout
            width: 100
            height: 100
            Layout.maximumHeight: 256
            Layout.minimumHeight: 256

            Text {
                id: text2
                width: 102
                height: 107
                color: "#ffffff"
                text: qsTr("London")
                font.pixelSize: 64
                verticalAlignment: Text.AlignBottom
                Layout.maximumWidth: 256
                Layout.minimumWidth: 256
                Layout.minimumHeight: 128
                Layout.maximumHeight: 128
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Text {
                id: text3
                width: 102
                height: 107
                color: "#ffffff"
                text: qsTr("4:14-Sunday,5 Feb 2023 ")
                font.pixelSize: 32
                fontSizeMode: Text.Fit
                Layout.maximumWidth: 256
                Layout.minimumWidth: 256
                Layout.minimumHeight: 128
                Layout.maximumHeight: 128
                Layout.fillHeight: true
                Layout.fillWidth: true
            }
        }

        ColumnLayout {
            id: columnLayout1
            width: 100
            height: 100

            Image {
                id: image
                width: 100
                height: 100
                source: "images/cloud.svg"
                Layout.maximumHeight: 128
                Layout.maximumWidth: 256
                Layout.minimumHeight: 128
                Layout.minimumWidth: 256
                Layout.fillHeight: true
                Layout.fillWidth: true
                fillMode: Image.PreserveAspectFit
            }

            Text {
                id: text4
                color: "#ffffff"
                text: qsTr("Cloudy")
                font.pixelSize: 32
                horizontalAlignment: Text.AlignHCenter
                fontSizeMode: Text.Fit
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.maximumHeight: 128
                Layout.maximumWidth: 256
                Layout.minimumHeight: 128
                Layout.minimumWidth: 256
            }
        }
    }

    Item {
        id: __materialLibrary__
    }
}
