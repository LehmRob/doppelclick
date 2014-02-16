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
	gameRunning = false;
	startTime = 0;
	bad = "<img src='images/bad.jpg'>";
	god = "<img src='images/god.jpg'>";
    neutral = "<img src='images/neutral.jpg'>";

    /* Initialize the UI */
    initializeUi();

    /* Connect signals */
    connect(doppelButton, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    connect(diffiSlider, SIGNAL(valueChanged(int)), this, SLOT(changeDifficulty));
}

/******************************************************************************
 * Private Slots                                                              *
 *****************************************************************************/
/**
 * Main Action whe the button is clicked
 */
void Doppelclick::buttonClicked(void)
{
	if (!gameRunning) {
		gameRunning = true;
		startTime = QDateTime::currentMSecsSinceEpoch();
		gameStateLabel->setText("<b>Start ...</b>");
		gameIcon->setText(neutral);
	} else {
		gameRunning = false;
		qint64 stopTime = QDateTime::currentMSecsSinceEpoch();
		qint64 diffTime = stopTime - startTime;
        if (diffTime <= diffiVal)
			gameIcon->setText(god);
		else
			gameIcon->setText(bad);
		QString result = "<b>Ergebnis: ";
		result.append(QString::number(diffTime));
		result.append(" </b>");
		gameStateLabel->setText(result);
	}
}

void Doppelclick::changeDifficulty()
{
    switch(diffiSlider->value())
    {
        case 1:
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

	/* Settings for the MainLayout */
	QVBoxLayout *mainLayout = new QVBoxLayout(this);
	mainLayout->setObjectName("MainLayout");

	/* Layout for Button and smilies */
	QHBoxLayout *doppelLayout = new QHBoxLayout();
	doppelLayout->setObjectName("DoppelLayout");

	/* Settings for the doppelButton */
	doppelButton = new QPushButton("Doppelclick");
	doppelButton->setObjectName("DoppelButton");
	doppelButton->setMinimumHeight(60);
	doppelButton->setMinimumWidth(100);

	gameIcon = new QLabel(neutral);

	/* Settings for Difficulty Slider*/
	diffiSlider = new QSlider();
	diffiSlider->setMinimum(1);
    diffiSlider->setMaximum(3);
	diffiSlider->setTickPosition(QSlider::TicksRight);

	doppelLayout->addWidget(doppelButton);
	doppelLayout->addWidget(gameIcon);
	doppelLayout->addWidget(diffiSlider);
	
	/* Settings for the gameState */
	QLabel *line = new QLabel("<hr>");
	gameStateLabel = new QLabel("<b>Bereit ...</b>");

	/* Add widgets to the MainLayout */
	mainLayout->insertLayout(-1, doppelLayout, 0);
	mainLayout->addWidget(line);
	mainLayout->addWidget(gameStateLabel);
}


