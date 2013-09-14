/*
 * libnitroshareutil
 * Copyright (C) 2013  Nathan Osman
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 */

#include <QTest>

#include <nitroshare/util/parameterbuilder.h>
#include "testparameterbuilder.h"

using namespace NitroShare::Util;

void TestParameterBuilder::run()
{
    ParameterBuilder builder("a", 42);
    QCOMPARE(builder.count(), 1);
    QVERIFY(builder.contains("a"));
    QCOMPARE(builder.value("a").toInt(), 42);

    builder << "b";
    QCOMPARE(builder.count(), 1);

    builder << 43;
    QCOMPARE(builder.count(), 2);
    QVERIFY(builder.contains("b"));
    QCOMPARE(builder.value("b").toInt(), 43);
}
