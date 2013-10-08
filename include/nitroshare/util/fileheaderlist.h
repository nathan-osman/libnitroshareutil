/*
 * libnitroshareutil
 * Copyright (C) 2013  Nathan Osman
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 */

#ifndef NSU_FILEHEADERLIST_H
#define NSU_FILEHEADERLIST_H

#include <QList>
#include <QSharedPointer>

#include <nitroshare/util/asynctask.h>
#include <nitroshare/util/fileheader.h>
#include "export.h"

namespace NitroShare
{
    namespace Util
    {
        class NSU_EXPORT FileHeaderListPrivate;

        /**
         * @brief A list of FileHeaderPointers
         */
        class NSU_EXPORT FileHeaderList
        {
            public:

                /**
                 * @brief Creates an empty FileHeader list
                 */
                FileHeaderList();

                /**
                 * @brief Destroys the list
                 */
                ~FileHeaderList();

                /**
                 * @brief Adds the specified file to the list
                 * @param filename the absolute path of the file to add
                 */
                void addFile(const QString & filename);

                /**
                 * @brief Adds the header to the list
                 * @param header the header to add
                 */
                void addHeader(FileHeaderPointer header);

                /**
                 * @brief Adds the specified directory to the list
                 * @param directory the absolute path of the directory to add
                 * @return the asynchronous task created to enumerate the directory
                 *
                 * This method returns immediately but begins enumerating the
                 * contents of the directory in a separate thread.
                 */
                AsyncTask * addDirectory(const QString & directory);

                /**
                 * @brief Returns a reference to the underlying list
                 * @return a list of FileHeaderPointers
                 */
                const QList<FileHeaderPointer> & headers() const;

                /**
                 * @brief Returns the combined size of all files in the list
                 * @return the total size of all files
                 */
                qint64 size() const;

            private:

                FileHeaderListPrivate * const d;
        };

        /**
         * @brief A shared pointer to a FileHeaderList
         */
        typedef QSharedPointer<FileHeaderList> FileHeaderListPointer;
    }
}

Q_DECLARE_METATYPE(NitroShare::Util::FileHeaderListPointer)

#endif // NSU_FILEHEADERLIST_H
