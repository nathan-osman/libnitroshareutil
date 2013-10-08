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

    public:

        TestFileHeaderList();

    private Q_SLOTS:

        void run();

    private:

        void createAndFillDirectory(const QString & );
        void createEmptyFile(const QString & filename);

        int count;
        qint64 size;
};

#endif // TESTFILEHEADERLIST_H
