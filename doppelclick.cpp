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
#include <QLabel>

#include "doppelclick.h"

Doppelclick::Doppelclick (QWidget *parent) :
        QWidget(parent) 
{
        initializeUi();
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
         *setMinimumWidth(200);
         */

        /* Settings for the MainLayout */
        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->setObjectName("MainLayout");

        /* Settings for the doppelButton */
        doppelButton = new QPushButton("Doppelclick");
        doppelButton->setObjectName("DoppelButton");
        doppelButton->setMinimumHeight(60);
        
        /* Settings for the gameState */
        QLabel *line = new QLabel("<hr>");
        gameState = new QLabel("<b>Bereit ...</b>");

        /* Add widgets to the MainLayout */
        mainLayout->addWidget(doppelButton);
        mainLayout->addWidget(line);
        mainLayout->addWidget(gameState);
}
