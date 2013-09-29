/*
 * libnitroshareutil
 * Copyright (C) 2013  Nathan Osman
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 */

#include <QTest>

#include "blockingtask.h"

void BlockingTask::run(const QVariantMap & parameters)
{
    for(int i = 1; i <= 5; ++i)
    {
        QTest::qSleep(100);
        Q_EMIT progress(i * 20);

        if(wasCanceled())
        {
            Q_EMIT canceled();
            return;
        }
    }

    Q_EMIT completed(parameters);
}
