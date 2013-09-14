/*
 * libnitroshareutil
 * Copyright (C) 2013  Nathan Osman
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 */

#include <QCoreApplication>
#include <QList>
#include <QTest>

#include "testasynctask.h"
#include "testparameterbuilder.h"

int main(int argc, char * argv[])
{
    QCoreApplication app(argc, argv);
    
    QList<QObject *> tests;
    tests << new TestAsyncTask
          << new TestParameterBuilder;
    
    int success = 0;
    foreach(QObject * test, tests)
        success |= QTest::qExec(test);
    
    return success;
}
