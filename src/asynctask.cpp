/*
 * libnitroshareutil
 * Copyright (C) 2013  Nathan Osman
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 */

#include <QMutexLocker>

#include <nitroshare/util/asynctask.h>
#include "asynctask_p.h"

using namespace NitroShare::Util;

AsyncTask::AsyncTask(QObject * parent)
    : QObject(parent), d(new AsyncTaskPrivate)
{
}

AsyncTask::~AsyncTask()
{
    delete d;
}

bool AsyncTask::wasCanceled()
{
    QMutexLocker locker(&d->mutex);
    return d->canceled;
}
