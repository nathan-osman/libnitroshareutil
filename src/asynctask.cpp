/*
 * libnitroshareutil
 * Copyright (C) 2013  Nathan Osman
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 */

#include <QThread>

#include <nitroshare/util/asynctask.h>
#include "asynctask_p.h"

using namespace NitroShare::Util;

AsyncTask::AsyncTask(QObject * parent)
    : QObject(parent), d(new AsyncTaskPrivate)
{
    connect(this, &AsyncTask::canceled,  this, &AsyncTask::finished);
    connect(this, &AsyncTask::error,     this, &AsyncTask::finished);
    connect(this, &AsyncTask::completed, this, &AsyncTask::finished);
}

AsyncTask::~AsyncTask()
{
    delete d;
}

void AsyncTask::start(const QVariantMap & parameters)
{
    if(isBlocking())
    {
        QThread * thread = new QThread;
        moveToThread(thread);
        thread->start();

        connect(this, &AsyncTask::finished, thread, &QThread::quit);
        connect(thread, &QThread::finished, thread, &QThread::deleteLater);

        QMetaObject::invokeMethod(this, "run", Qt::QueuedConnection, Q_ARG(QVariantMap, parameters));
    }
    else
        run(parameters);
}

void AsyncTask::cancel()
{
    d->canceled = true;
}

bool AsyncTask::wasCanceled() const
{
    return d->canceled;
}
