/*
 * libnitroshareutil
 * Copyright (C) 2013  Nathan Osman
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 */

#ifndef NSU_ASYNCTASK_H
#define NSU_ASYNCTASK_H

#include <QObject>

#include <nitroshare/util/promise.h>
#include "export.h"

namespace NitroShare
{
    namespace Util
    {
        class NSU_EXPORT AsyncTask : public QObject
        {
            Q_OBJECT

            public:

                explicit AsyncTask(QObject * parent = nullptr);

            Q_SIGNALS:

                //...
        };
    }
}

#endif // NSU_ASYNCTASK_H
