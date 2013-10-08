/*
 * libnitroshareutil
 * Copyright (C) 2013  Nathan Osman
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 */

#include <QEventLoop>

#include <nitroshare/util/asynctask.h>

using namespace NitroShare::Util;

AsyncTask::AsyncTask(QObject * parent)
    : QObject(parent)
{
    connect(this, &AsyncTask::canceled,  this, &AsyncTask::finished);
    connect(this, &AsyncTask::error,     this, &AsyncTask::finished);
    connect(this, &AsyncTask::completed, this, &AsyncTask::finished);
}

bool AsyncTask::progressive() const
{
    return false;
}

bool AsyncTask::cancelable() const
{
    return false;
}

bool AsyncTask::waitForFinished()
{
    QEventLoop loop;
    bool completed = false;

    loop.connect(this, &AsyncTask::canceled, &loop, &QEventLoop::quit);
    loop.connect(this, &AsyncTask::error,    &loop, &QEventLoop::quit);
    loop.connect(this, &AsyncTask::completed, [&loop, &completed]()
    {
        completed = true;
        loop.quit();
    });

    loop.exec();
    return completed;
}

void AsyncTask::start(const QVariantMap & parameters)
{
    run(parameters);
}
