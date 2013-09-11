/*
 * libnitroshareutil
 * Copyright (C) 2013  Nathan Osman
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 */

#ifndef NSU_PROMISE_H
#define NSU_PROMISE_H

#include <QObject>

#include "export.h"

namespace NitroShare
{
    namespace Util
    {
        class NSU_EXPORT Promise : public QObject
        {
            Q_OBJECT
            
            public:
            
                Promise(QObject * parent = nullptr);
                virtual ~Promise();
        };
    }
}

#endif // NSU_PROMISE_H

