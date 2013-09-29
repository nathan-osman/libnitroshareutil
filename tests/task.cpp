/*
 * libnitroshareutil
 * Copyright (C) 2013  Nathan Osman
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 */

#include "task.h"

void Task::run(const QVariantMap & parameters)
{
    connect(&timer, &QTimer::timeout, [this, parameters]()
    {
        Q_EMIT progress(++count * 20);

        if(count == 5)
        {
            timer.stop();
            Q_EMIT completed(parameters);
        }
    });

    connect(this, &AsyncTask::cancel, &timer, &QTimer::stop);
    connect(this, &AsyncTask::cancel, this,   &AsyncTask::canceled);

    timer.start(100);
    count = 0;
}
