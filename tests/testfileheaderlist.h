/*
 * libnitroshareutil
 * Copyright (C) 2013  Nathan Osman
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 */

#ifndef TESTFILEHEADERLIST_H
#define TESTFILEHEADERLIST_H

#include <QObject>

class TestFileHeaderList : public QObject
{
    Q_OBJECT

    private Q_SLOTS:

        void run();

    private:

        void createEmptyFile(const QString & filename);
};

#endif // TESTFILEHEADERLIST_H
