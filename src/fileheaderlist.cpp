/*
 * libnitroshareutil
 * Copyright (C) 2013  Nathan Osman
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 */

#include <QFileInfo>

#include <nitroshare/util/fileheaderlist.h>
#include <nitroshare/util/parameterbuilder.h>
#include "directoryenumerator.h"
#include "fileheaderlist_p.h"

using namespace NitroShare::Util;

FileHeaderListPrivate::FileHeaderListPrivate()
    : size(0)
{
}

FileHeaderList::FileHeaderList()
    : d(new FileHeaderListPrivate)
{
}

FileHeaderList::~FileHeaderList()
{
    delete d;
}

void FileHeaderList::addFile(const QString & filename)
{
    d->headers.append(FileHeaderPointer(new FileHeader(QFileInfo(filename))));
}

void FileHeaderList::addHeader(FileHeaderPointer header)
{
    d->headers.append(header);
}

AsyncTask * FileHeaderList::addDirectory(const QString & directory)
{
    DirectoryEnumerator * enumerator = new DirectoryEnumerator;

    QObject::connect(enumerator, &AsyncTask::completed, [this](const QVariantMap & parameters)
    {
        // TODO: add the new headers to the list
        d->size += parameters["size"].toLongLong();
    });
    QObject::connect(enumerator, &AsyncTask::finished, enumerator, &QObject::deleteLater);

    enumerator->start(ParameterBuilder("directory", directory));
    return enumerator;
}

qint64 FileHeaderList::size() const
{
    return d->size;
}
