/*
 * doppelclick: This Programm is for how to learn the double click on the
 * computer
 * Copyright (C) 2013  Robert Lehmann <lehmrob@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#include <QtWidgets>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDateTime>

#include "doppelclick.h"

Doppelclick::Doppelclick (QWidget *parent) :
        QWidget(parent) 
{
        /* Initialize variables */
        gameState = false;
        startTime = 0;
        badImage = "<img src='images/bad.jpg'>";
        godImage = "<img src='images/god.jpg'>";
        neutralImage= "<img src='images/neutral.jpg'>";
		state = wait;

        /* Initialize the UI */
        initializeUi();

        /* Connect signals */
        connect(doppelButton, SIGNAL(clicked()), this, SLOT(buttonClicked()));
}

/******************************************************************************
 * Private Slots                                                              *
 *****************************************************************************/
/**
 * Main Action whe the button is clicked
 */
void Doppelclick::buttonClicked(void)
{
        if (!gameState) {
                gameState = true;
                startTime = QDateTime::currentMSecsSinceEpoch();
                gameStateLabel->setText("<b>Start ...</b>");
        } else {
                gameState = false;
                qint64 stopTime = QDateTime::currentMSecsSinceEpoch();
                qint64 diffTime = stopTime - startTime;
                QString result = "<b>Ergebnis: ";
                result.append(QString::number(diffTime));
                result.append(" </b>");
                gameStateLabel->setText(result);
        }
}


/*****************************************************************************
 * Private Methods                                                           *
 *****************************************************************************/
/**
 * Initialize the User interface
 */
void Doppelclick::initializeUi(void) 
{
        /* Settings for the Main Window */
        setWindowTitle("Doppelclick Spiel");
        /*
         *setMinimumHeight(200);
         *setMinimumWidth(200);gameIcon);gameIcon);gameIcon);
         */

        /* Settings for the MainLayout */
        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->setObjectName("MainLayout");

        /* Layout for Button and smilies */
        QHBoxLayout *doppelLayout = new QHBoxLayout(this);
        doppelLayout->setObjectName("DoppelLayout");

        /* Settings for the doppelButton */
        doppelButton = new QPushButton("Doppelclick");
        doppelButton->setObjectName("DoppelButton");
        doppelButton->setMinimumHeight(60);
        doppelButton->setMinimumWidth(100);

        gameIcon = new QLabel(neutralImage);

        doppelLayout->addWidget(doppelButton);
        doppelLayout->addWidget(gameIcon);
        
        /* Settings for the gameState */
        QLabel *line = new QLabel("<hr>");
        gameStateLabel = new QLabel("<b>Bereit ...</b>");

        /* Add widgets to the MainLayout */
        mainLayout->insertLayout(-1, doppelLayout, 0);
        mainLayout->addWidget(line);
        mainLayout->addWidget(gameStateLabel);
}


