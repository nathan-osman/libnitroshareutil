/*
 * libnitroshareutil
 * Copyright (C) 2013  Nathan Osman
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 */

#include <nitroshare/util/parameterbuilder.h>
#include "parameterbuilder_p.h"

using namespace NitroShare::Util;

ParameterBuilder::ParameterBuilder()
    : d(new ParameterBuilderPrivate)
{
}

ParameterBuilder::ParameterBuilder(QString key, QVariant value)
    : d(new ParameterBuilderPrivate)
{
    insert(key, value);
}

ParameterBuilder::~ParameterBuilder()
{
    delete d;
}

ParameterBuilder & ParameterBuilder::operator<<(const QVariant & parameter)
{
    if(d->key.isNull())
        d->key = parameter.toString();
    else
    {
        insert(d->key, parameter);
        d->key.clear();
    }

    return *this;
}
