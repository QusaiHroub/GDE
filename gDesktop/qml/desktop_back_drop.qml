/*
 * This file is part of GDE
 *
 * Copyright © 2020 Qusai Hroub
 *
 * GDE is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 */

import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Controls.Styles 1.4

Item {
    id: root

    transformOrigin: Item.Bottom

    QtObject {
        id: internal

        property int viewTopBottonMargin: root.width > root.height ? root.height * 0.118518518518 : root.height * 0.1
        property int viewRightLeftMargin: root.height > root.width ? root.width * 0.118518518518 : root.width * 0.1
    }

    Rectangle {
        id: background
        color: "black"
        radius: 0
        anchors.fill: parent

        Image {
            id: backgroundImg
            anchors.fill: parent

            OpacityAnimator {
                id: backDropAnim
                target: root
                from: 0
                to: 1
                duration: 1500
            }

            Component.onCompleted: {
                backDropAnim.running = true
            }
        }
    }

    Item {
        id: view
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.topMargin: internal.viewTopBottonMargin
        anchors.bottomMargin: internal.viewTopBottonMargin
        anchors.leftMargin: internal.viewRightLeftMargin
        anchors.rightMargin: internal.viewRightLeftMargin

    }

}
