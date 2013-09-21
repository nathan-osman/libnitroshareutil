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
#include <QThread>

#include <nitroshare/util/blockingasynctask.h>
#include "blockingasynctask_p.h"

using namespace NitroShare::Util;

BlockingAsyncTaskPrivate::BlockingAsyncTaskPrivate()
    : canceled(false)
{
}

BlockingAsyncTask::BlockingAsyncTask(QObject * parent)
    : AsyncTask(parent), d(new BlockingAsyncTaskPrivate)
{
}

BlockingAsyncTask::~BlockingAsyncTask()
{
    delete d;
}

void BlockingAsyncTask::start(const QVariantMap & parameters)
{
    QThread * thread = new QThread;
    moveToThread(thread);
    thread->start();

    connect(this, &AsyncTask::cancel, [this]()
    {
        QMutexLocker locker(&d->mutex);
        d->canceled = true;
    });

    connect(this, &AsyncTask::finished, thread, &QThread::quit);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    QMetaObject::invokeMethod(this, "run", Qt::QueuedConnection, Q_ARG(QVariantMap, parameters));
}

bool BlockingAsyncTask::wasCanceled() const
{
    QMutexLocker locker(&d->mutex);
    return d->canceled;
}
