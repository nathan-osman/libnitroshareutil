/*
 * libnitroshareutil
 * Copyright (C) 2013  Nathan Osman
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 */

#include <QDir>
#include <QFile>
#include <QTest>

#include <nitroshare/util/fileheaderlist.h>
#include "testfileheaderlist.h"

using namespace NitroShare::Util;

void TestFileHeaderList::run()
{
    QDir temp(QDir::temp());

    // Create a directory to use for testing
    QVERIFY(temp.mkdir("headertest"));
    QVERIFY(temp.cd("headertest"));

    // Create a and an empty file or two
    QVERIFY(temp.mkdir("a"));
    createEmptyFile(temp.absoluteFilePath("a/file1"));
    createEmptyFile(temp.absoluteFilePath("a/file2"));

    // Add them to the file list
    FileHeaderList list;
    list.addDirectory(temp.absolutePath());
}

void TestFileHeaderList::createEmptyFile(const QString & filename)
{
    QFile file(filename);
    QVERIFY(file.open(QIODevice::WriteOnly));
    QVERIFY(file.write("42"));
}
