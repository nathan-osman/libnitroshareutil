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

TestFileHeaderList::TestFileHeaderList()
    : count(0), size(0)
{
}

void TestFileHeaderList::run()
{
    QDir temp(QDir::temp());

    // Test for the temp directory and purge it if it exists
    if(temp.cd("headertest"))
    {
        QVERIFY(temp.removeRecursively());
        QVERIFY(temp.cdUp());
    }

    QVERIFY(temp.mkdir("headertest"));
    QVERIFY(temp.cd("headertest"));

    for(int i = 1; i <= 5; ++i)
        createAndFillDirectory(temp.absoluteFilePath(QString("dir%1").arg(i)));

    FileHeaderList list;
    QVERIFY(list.addDirectory(temp.absolutePath())->waitForFinished());

    QCOMPARE(list.headers().count(), count);
    QCOMPARE(list.size(),            size);

    // Clean up the test directory
    temp.removeRecursively();
}

void TestFileHeaderList::createAndFillDirectory(const QString & directory)
{
    QDir dir(directory);
    dir.mkdir(directory);

    for(int i = 1; i <= 5; ++i)
        createEmptyFile(dir.absoluteFilePath(QString("file%1.txt").arg(i)));

    count += 5;
}

void TestFileHeaderList::createEmptyFile(const QString & filename)
{
    QFile file(filename);

    QVERIFY(file.open(QIODevice::WriteOnly));
    QVERIFY(file.write("42"));

    size += 2;
}
