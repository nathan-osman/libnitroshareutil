/*
 * libnitroshareutil
 * Copyright (C) 2013  Nathan Osman
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 */

#ifndef TESTASYNCTASK_H
#define TESTASYNCTASK_H

#include <QObject>

#include <nitroshare/util/asynctask.h>

class TestAsyncTask : public QObject
{
    Q_OBJECT
    
    private Q_SLOTS:

        void testCompleted();
        void testBlockingCompleted();

        void testCanceled();
        void testBlockingCanceled();

    private:

        void run(NitroShare::Util::AsyncTask &, bool);
};

#endif // TESTASYNCTASK_H
