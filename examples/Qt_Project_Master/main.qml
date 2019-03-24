import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.0
Rectangle{
    visible: true
    width: 800
    height: 400
    color: "#a6a6a6"
    signal sW1Clicked()
    objectName: "rect"

    Slider {
        id: slider0
        x: 394
        y: 56
        width: 398
        height: 40
        value: 0.5
        objectName: "slider1"

    }

    Switch {
        id: switch1
        x: 25
        y: 56
        text: qsTr("Switch 1")
        font.pointSize: 14
        font.bold: true
        objectName: "sw1"

    }

    Label {
        id: label
        x: 309
        y: 65
        text: qsTr("Analog1")
        font.bold: true
        font.pointSize: 15
    }

    Slider {
        id: slider1
        x: 394
        y: 149
        width: 398
        height: 40
        value: 0.5
        objectName: "slider2"

    }

    Switch {
        id: switch2
        x: 25
        y: 149
        text: qsTr("Switch 2")
        font.bold: true
        font.pointSize: 14
        objectName: "sw2"

    }

    Label {
        id: label1
        x: 309
        y: 158
        text: qsTr("Analog2")
        font.bold: true
        font.pointSize: 15
    }

    Slider {
        id: slider3
        x: 394
        y: 326
        width: 398
        height: 40
        value: 0.5
        objectName: "slider4"

    }

    Switch {
        id: switch3
        x: 25
        y: 326
        text: qsTr("Switch 4")
        font.bold: true
        font.pointSize: 14
        objectName: "sw4"

    }

    Label {
        id: label2
        x: 309
        y: 335
        text: qsTr("Analog4")
        font.bold: true
        font.pointSize: 15

    }

    Slider {
        id: slider2
        x: 394
        y: 238
        width: 398
        height: 40
        value: 0.5
        objectName: "slider3"

    }

    Switch {
        id: switch4
        x: 25
        y: 238
        text: qsTr("Switch 3")
        font.bold: true
        font.pointSize: 14
        objectName: "sw3"
    }

    Label {
        id: label3
        x: 309
        y: 247
        text: qsTr("Analog3")
        font.bold: true
        font.pointSize: 15
    }

}
