import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: "Device Monitor"

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 20

        Text {
            text: "Qt/QML Device Monitor"
            font.pixelSize: 28
            Layout.alignment: Qt.AlignHCenter
        }

        Text {
            text: "Temperature: " + temperatureSensor.temperature + "°F"
            font.pixelSize: 22
            Layout.alignment: Qt.AlignHCenter
        }

        Button {
            text: "Increase Temperature"
            Layout.alignment: Qt.AlignHCenter

            onClicked: {
                temperatureSensor.temperature += 1
            }
        }
    }
}