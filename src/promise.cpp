/*
 * libnitroshareutil
 * Copyright (C) 2013  Nathan Osman
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 */

#include <nitroshare/util/promise.h>

using namespace NitroShare::Util;

Promise::Promise(QObject * parent)
    : QObject(parent)
{
}

Promise::~Promise()
{
}
