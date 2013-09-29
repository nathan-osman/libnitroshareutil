/*
 * libnitroshareutil
 * Copyright (C) 2013  Nathan Osman
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 */

#ifndef TASK_H
#define TASK_H

#include <QTimer>

#include <nitroshare/util/asynctask.h>

class Task : public NitroShare::Util::AsyncTask
{
    Q_OBJECT

    public:

        virtual bool progressive() const { return true; }
        virtual bool cancelable() const { return true; }

    private Q_SLOTS:

        virtual void run(const QVariantMap &);

    private:

        QTimer timer;
        int count;
};

#endif // TASK_H
