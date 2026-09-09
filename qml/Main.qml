import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    id: root

    required property TemperatureSensor temperatureSensor

    width: 640
    height: 480
    visible: true
    title: "Device Monitor"

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 20

        Label {
            text: "Qt/QML Device Monitor"
            font.pixelSize: 28
            Layout.alignment: Qt.AlignHCenter
        }

        Label {
            text: "Temperature: " + root.temperatureSensor.temperature + "°F"
            font.pixelSize: 22
            Layout.alignment: Qt.AlignHCenter
        }

        Button {
            text: "Increase Temperature"
            Layout.alignment: Qt.AlignHCenter

            onClicked: {
                root.temperatureSensor.temperature += 1;
            }
        }

        Button {
            text: "Decrease Temperature"
            Layout.alignment: Qt.AlignHCenter

            onClicked: {
                root.temperatureSensor.temperature -= 1;
            }
        }

        Button {
            text: "Start Monitoring"
            visible: !root.temperatureSensor.running
            Layout.alignment: Qt.AlignHCenter
            onClicked: {
                if (!root.temperatureSensor.running) {
                    root.temperatureSensor.start();
                }
            }
        }

        Button {
            text: "Stop Monitoring"
            visible: root.temperatureSensor.running
            Layout.alignment: Qt.AlignHCenter
            onClicked: {
                root.temperatureSensor.stop();
            }
        }

        Label {
            text: "WARNING: Temperature too high!"
            visible: root.temperatureSensor.temperature >= 75
            font.pixelSize: 20
            font.bold: true
            color: "red"
            Layout.alignment: Qt.AlignHCenter
        }
    }
}
