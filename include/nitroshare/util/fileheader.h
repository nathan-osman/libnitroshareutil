/*
 * libnitroshareutil
 * Copyright (C) 2013  Nathan Osman
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 */

#ifndef NSU_FILEHEADER_H
#define NSU_FILEHEADER_H

#include <QFileInfo>

#include "export.h"

namespace NitroShare
{
    namespace Util
    {
        class NSU_EXPORT FileHeaderPrivate;

        /**
         * @brief Stores information about a file or directory
         */
        class NSU_EXPORT FileHeader
        {
            public:

                /**
                 * @brief Creates the file header
                 * @param info a QFileInfo for the file
                 * @param relative_filename the relative filename for the file
                 */
                FileHeader(const QFileInfo & info, const QString & relative_filename = QString());

                /**
                 * @brief Destroys the file header
                 */
                virtual ~FileHeader();

                /**
                 * @brief Returns the absolute filename of the file
                 * @return the absolute filename
                 */
                QString absoluteFilename() const;

                /**
                 * @brief Returns the relative filename of the file
                 * @return the relative filename
                 */
                QString relativeFilename() const;

                /**
                 * @brief Returns the size of the file
                 * @return the file size in bytes
                 */
                qint64 size() const;

                /**
                 * @brief Indicates if the file can be written to
                 * @return true if the file is writable
                 */
                bool writable() const;

                /**
                 * @brief Indicates if the file can be executed
                 * @return true if the file is executable
                 *
                 * Note: not all filesystems support this feature.
                 */
                bool executable() const;

            private:

                FileHeaderPrivate * const d;
        };
    }
}

#endif // NSU_FILEHEADER_H
