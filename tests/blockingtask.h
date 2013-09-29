/*
 * libnitroshareutil
 * Copyright (C) 2013  Nathan Osman
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 */

#ifndef BLOCKINGTASK_H
#define BLOCKINGTASK_H

#include <nitroshare/util/blockingasynctask.h>

class BlockingTask : public NitroShare::Util::BlockingAsyncTask
{
    Q_OBJECT

    public:

        virtual bool progressive() const { return true; }
        virtual bool cancelable() const { return true; }

    private Q_SLOTS:

        virtual void run(const QVariantMap &);
};

#endif // BLOCKINGTASK_H

