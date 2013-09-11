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

#include <nitroshare/util/promise.h>

using namespace NitroShare::Util;

Promise::Promise(bool delete_on_finished, QObject * parent)
    : QObject(parent)
{
    connect(this, &Promise::canceled,  this, &Promise::finished);
    connect(this, &Promise::error,     this, &Promise::finished);
    connect(this, &Promise::completed, this, &Promise::finished);

    if(delete_on_finished)
        connect(this, &Promise::finished, this, &Promise::deleteLater);
}

bool Promise::waitForFinished()
{
    QEventLoop loop;
    bool completed = false;

    connect(this, &Promise::completed, [&completed]()
    {
        completed = true;
    });
    connect(this, &Promise::finished, &loop, &QEventLoop::quit);

    loop.exec();
    return completed;
}
