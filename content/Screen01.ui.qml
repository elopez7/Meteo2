

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
import QtQuick3D.Particles3D 6.4

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
                scale.z: 10
                scale.y: 10
                scale.x: 10
                eulerRotation.z: 0
                eulerRotation.y: 37.54223
                eulerRotation.x: -0
                z: 0
            }

            OrthographicCamera {
                id: cameraOrthographic
                x: 84.085
                y: 160.592
                eulerRotation.z: -0
                eulerRotation.y: 0
                eulerRotation.x: -25.15905
                verticalMagnification: 5
                horizontalMagnification: 5
                z: 182.38942
            }

            ParticleSystem3D {
                id: snow
                x: 0
                y: 0
                visible: true
                ParticleEmitter3D {
                    id: snowEmitter
                    particleScaleVariation: 1
                    emitRate: 500
                    lifeSpan: 4000
                    velocity: snowDirection
                    shape: snowShape
                    particleScale: 2
                    VectorDirection3D {
                        id: snowDirection
                        direction.z: 0
                        direction.y: -100
                    }

                    SpriteParticle3D {
                        id: snowParticle
                        color: "#dcdcdc"
                        billboard: true
                        maxAmount: 5000
                        particleScale: 1
                        sprite: snowTexture
                        Texture {
                            id: snowTexture
                            source: "snowflake.png"
                        }
                    }
                    particle: snowParticle
                }

                ParticleShape3D {
                    id: snowShape
                    type: ParticleShape3D.Cube
                    extents.y: 1
                    extents.z: 400
                    extents.x: 400
                    fill: true
                }

                Wander3D {
                    id: wander
                    uniqueAmount.x: 50
                    uniquePace.z: 0.03
                    uniqueAmount.y: 20
                    uniqueAmountVariation: 0.1
                    uniqueAmount.z: 50
                    globalPace.x: 0.01
                    globalAmount.x: -500
                    uniquePaceVariation: 0.2
                    uniquePace.y: 0.01
                    uniquePace.x: 0.03
                    particles: snowParticle
                }
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
