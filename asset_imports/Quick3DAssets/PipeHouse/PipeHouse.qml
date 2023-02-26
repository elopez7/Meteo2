import QtQuick
import QtQuick3D
import Quick3DAssets.PipeHouse 1.0

Node {
    // Materials
    // end of Materials

    Model {
        id: hexagonBase
        source: "meshes/hexagonBase.mesh"
        castsReflections: false
        receivesShadows: false
        castsShadows: false
        materials: [
            metal_material,
            iron_material,
            glass_material
        ]
    }

    Node {
        id: __materialLibrary__

        PrincipledMaterial {
            id: metal_material
            objectName: "metal_material"
            baseColor: "#ff5b564c"
            roughness: 0.5
            cullMode: Material.NoCulling
            alphaMode: PrincipledMaterial.Opaque
        }

        PrincipledMaterial {
            id: iron_material
            objectName: "iron_material"
            baseColor: "#ff1e2225"
            roughness: 0.5
            cullMode: Material.NoCulling
            alphaMode: PrincipledMaterial.Opaque
        }

        PrincipledMaterial {
            id: glass_material
            objectName: "glass_material"
            baseColor: "#ff04698d"
            roughness: 0.5
            cullMode: Material.NoCulling
            alphaMode: PrincipledMaterial.Opaque
        }

        PrincipledMaterial {
            id: _material
            objectName: "_material"
            metalness: 1
            roughness: 1
            alphaMode: PrincipledMaterial.Opaque
        }
    }
}
