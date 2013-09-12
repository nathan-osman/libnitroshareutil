/*
 * libnitroshareutil
 * Copyright (C) 2013  Nathan Osman
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 */

#ifndef NSU_ASYNCTASK_P_H
#define NSU_ASYNCTASK_P_H

#include <QMutex>

namespace NitroShare
{
    namespace Util
    {
        class AsyncTaskPrivate
        {
            public:

                QMutex mutex;
                bool canceled;
        };
    }
}

#endif // NSU_ASYNCTASK_P_H

