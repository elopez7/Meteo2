

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick 6.4
import QtQuick.Controls 6.4
import QtQuick3D 6.4
import Meteo2
import QtQuick.Layouts 6.3
import Quick3DAssets.PipeHouse 1.0

Rectangle {
    id: rectangle
    width: Constants.width
    height: Constants.height

    color: Constants.backgroundColor

    View3D {
        id: view3D
        anchors.fill: parent

        environment: sceneEnvironment

        SceneEnvironment {
            id: sceneEnvironment
            clearColor: "#0c1425"
            backgroundMode: SceneEnvironment.Color
            antialiasingMode: SceneEnvironment.MSAA
            antialiasingQuality: SceneEnvironment.High
        }

        Node {
            id: scene
            DirectionalLight {
                id: directionalLight
                brightness: 5
                eulerRotation.z: -0.00001
                eulerRotation.y: 59.85394
                eulerRotation.x: -46.3484
            }

            PipeHouse {
                id: pipeHouse
                x: 0
                eulerRotation.z: 0
                eulerRotation.y: 37.54223
                eulerRotation.x: -0
                z: 0
            }

            OrthographicCamera {
                id: cameraOrthographic
                x: 9.543
                y: 15.462
                eulerRotation.z: -0
                eulerRotation.y: 0
                eulerRotation.x: -25.15905
                verticalMagnification: 50
                horizontalMagnification: 50
                z: 20.61482
            }
        }
    }

    Item {
        id: __materialLibrary__
        DefaultMaterial {
            id: defaultMaterial
            objectName: "Default Material"
            diffuseColor: "#4aee45"
        }
    }

    WeatherInformationCard {
        id: weatherInformationFlickable
        x: 1152
        width: 768
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.topMargin: 0
        anchors.bottomMargin: 0
        anchors.rightMargin: 0
    }

    CurrentWeatherCard {
        id: currentWeatherCard
        x: 67
        y: 699
    }

    Text {
        id: titleText
        x: 67
        y: 53
        width: 464
        height: 192
        color: "#ffffff"
        text: qsTr("Meteo")
        font.pixelSize: 128
        verticalAlignment: Text.AlignVCenter
    }

}
