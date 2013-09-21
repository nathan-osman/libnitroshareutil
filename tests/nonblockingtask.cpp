/*
 * NitroShare - Send Any File to Any Device
 * Copyright (C) 2013  Nathan Osman
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "nonblockingtask.h"

void NonBlockingTask::run(const QVariantMap & parameters)
{
    connect(&timer, &QTimer::timeout, [this, parameters]()
    {
        Q_EMIT progress(++count * 20);

        if(count == 5)
        {
            Q_EMIT completed(parameters);
            timer.stop();
        }
    });

    timer.start(100);
    count = 0;
}
