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
#include <QFileInfo>
#include <QTest>

#include <nitroshare/util/fileheader.h>
#include "testfileheader.h"

using namespace NitroShare::Util;

void TestFileHeader::run()
{
    QDir temp(QDir::temp());
    QString filename(temp.absoluteFilePath("test.txt"));

    // Create a file that is writable and executable
    QFile file(filename);
    QVERIFY(file.open(QIODevice::WriteOnly));
    QVERIFY(file.write("42"));
    file.close();

    QFileInfo info(filename);
    FileHeader header(info);
    QCOMPARE(header.absoluteFilename(), filename);
    QCOMPARE(header.relativeFilename(), QString("test.txt"));
    QCOMPARE(header.size(),             qint64(2));
    QCOMPARE(header.writable(),         true);
    // There is no platform-independent way to test executable()

    temp.remove("test.txt");
}
