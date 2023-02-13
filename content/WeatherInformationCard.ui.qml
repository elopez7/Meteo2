import QtQuick 6.4
import QtQuick.Controls 6.4
import QtQuick3D 6.4
import Meteo2
import QtQuick.Layouts 6.3

Flickable {
    id: flickable
    width: 768
    height: 1080
    boundsBehavior: Flickable.StopAtBounds
    pixelAligned: true
    flickableDirection: Flickable.VerticalFlick
    contentHeight: columnLayout.childrenRect.height
    clip: true

    Rectangle {
        id: background
        color: "#00ffffff"
        anchors.fill: parent
    }

    ColumnLayout {
        id: columnLayout
        anchors.fill: parent


        SearchField {
            id: searchField
            Layout.minimumHeight: 128
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        Countries {
            id: countries
            Layout.fillWidth: true
        }




        Separator {
            id: separator
        }




        WeatherDetailsCard {
            id: weatherDetails
            cardTitle: "Weather Details"
            Layout.minimumHeight: 512
            Layout.preferredHeight: 512
            Layout.fillHeight: true
            Layout.fillWidth: true
        }





        Separator {
            id: separator1
        }

        Label {
            id: dailyLabel
            color: "#ffffff"
            text: qsTr("Daily Weather")
            font.pixelSize: 32
            Layout.leftMargin: 16
            Layout.fillWidth: true
            font.bold: true
        }

        Separator {
            id: separator2
        }

        WeatherDetailsCard {
            id: weatherDetails1
            Layout.preferredHeight: 512
            Layout.fillHeight: true
            Layout.minimumHeight: 512
            Layout.fillWidth: true
            cardTitle: "Weather Details"
        }


        Separator {
            id: separator3
        }

        WeatherDetailsCard {
            id: weatherDetails2
            Layout.preferredHeight: 512
            Layout.fillHeight: true
            Layout.minimumHeight: 512
            Layout.fillWidth: true
            cardTitle: "Weather Details"
        }



        Separator {
            id: separator4
        }

        WeatherDetailsCard {
            id: weatherDetails3
            Layout.preferredHeight: 512
            Layout.fillHeight: true
            Layout.minimumHeight: 512
            Layout.fillWidth: true
            cardTitle: "Weather Details"
        }




        Separator {
            id: separator5
        }

        WeatherDetailsCard {
            id: weatherDetails4
            Layout.preferredHeight: 512
            Layout.fillHeight: true
            Layout.minimumHeight: 512
            Layout.fillWidth: true
            cardTitle: "Weather Details"
        }





        Separator {
            id: separator6
        }

        WeatherDetailsCard {
            id: weatherDetails5
            Layout.preferredHeight: 512
            Layout.fillHeight: true
            Layout.minimumHeight: 512
            Layout.fillWidth: true
            cardTitle: "Weather Details"
        }






        Separator {
            id: separator7
        }

        WeatherDetailsCard {
            id: weatherDetails6
            Layout.preferredHeight: 512
            Layout.fillHeight: true
            Layout.minimumHeight: 512
            Layout.fillWidth: true
            cardTitle: "Weather Details"
        }







        Separator {
            id: separator8
        }

        WeatherDetailsCard {
            id: weatherDetails7
            Layout.preferredHeight: 512
            Layout.fillHeight: true
            Layout.minimumHeight: 512
            Layout.fillWidth: true
            cardTitle: "Weather Details"
        }





















































    }

    Item {
        id: __materialLibrary__
    }
}
