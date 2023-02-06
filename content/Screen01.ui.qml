

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
            antialiasingMode: SceneEnvironment.MSAA
            antialiasingQuality: SceneEnvironment.High
        }

        Node {
            id: scene
            DirectionalLight {
                id: directionalLight
            }

            PerspectiveCamera {
                id: sceneCamera
                z: 350
            }

            Model {
                id: cubeModel
                eulerRotation.y: 45
                eulerRotation.x: 30
                materials: defaultMaterial
                source: "#Cube"
            }
        }
    }

    Button {
        id: buttonSendRequest
        x: 821
        width: 279
        height: 111
        text: qsTr("Send Request")
        anchors.top: parent.top
        anchors.topMargin: 155
        font.pointSize: 32
    }

    Button {
        id: pointlessButton
        x: 780
        y: 786
        width: 362
        height: 145
        text: qsTr("Pointless Button")
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 149
        font.pointSize: 36
    }

    Button {
        id: leftButton
        x: 289
        y: 485
        width: 276
        height: 110
        text: qsTr("Button")
    }

    Item {
        id: __materialLibrary__
        DefaultMaterial {
            id: defaultMaterial
            objectName: "Default Material"
            diffuseColor: "#4aee45"
        }
    }
}
