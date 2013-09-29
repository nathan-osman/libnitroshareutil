/*
 * libnitroshareutil
 * Copyright (C) 2013  Nathan Osman
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 */

#ifndef NSU_FILEHEADER_P_H
#define NSU_FILEHEADER_P_H

#include <QString>

namespace NitroShare
{
    namespace Util
    {
        class FileHeaderPrivate
        {
            public:

                FileHeaderPrivate();

                QString absolute_filename;
                QString relative_filename;
                qint64 size;

                bool writable, executable;
        };
    }
}

#endif // NSU_FILEHEADER_P_H
