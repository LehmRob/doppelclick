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

#include "doppelclick_time.h"

/**
 * This is the default construtor
 */
DoppelclickTime::DoppelclickTime(void)
{
        startTime = 0;
        stopTime = 0;
}

/**
 * Constructor for a given start Time
 */
DoppelclickTime::DoppelclickTime(qint64 startTime)
{
        this->startTime = startTime;
        this->stopTime = stopTime;
}

/**
 * Get the difference between the start and the stop Time
 */
qint64 DoppelclickTime::getDiffTime(void)
{
        return stopTime - startTime;
}
