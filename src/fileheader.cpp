/*
 * libnitroshareutil
 * Copyright (C) 2013  Nathan Osman
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 */

#include <nitroshare/util/fileheader.h>
#include "fileheader_p.h"

using namespace NitroShare::Util;

FileHeaderPrivate::FileHeaderPrivate()
    : size(0), writable(false), executable(false)
{
}

FileHeader::FileHeader(const QFileInfo & info, const QString & relative_filename)
    : d(new FileHeaderPrivate)
{
    d->absolute_filename = info.absoluteFilePath();
    d->relative_filename = relative_filename.isNull()?info.fileName():relative_filename;

    if(!info.isDir())
    {
        d->size = info.size();

        d->writable   = info.isWritable();
        d->executable = info.isExecutable();
    }
}

FileHeader::~FileHeader()
{
    delete d;
}

QString FileHeader::absoluteFilename() const
{
    return d->absolute_filename;
}

QString FileHeader::relativeFilename() const
{
    return d->relative_filename;
}

qint64 FileHeader::size() const
{
    return d->size;
}

bool FileHeader::writable() const
{
    return d->writable;
}

bool FileHeader::executable() const
{
    return d->executable;
}
