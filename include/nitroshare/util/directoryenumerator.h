/*
 * libnitroshareutil
 * Copyright (C) 2013  Nathan Osman
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 */

#ifndef NSU_DIRECTORYENUMERATOR_H
#define NSU_DIRECTORYENUMERATOR_H

#include <nitroshare/util/blockingasynctask.h>
#include "export.h"

namespace NitroShare
{
    namespace Util
    {
        /**
         * @brief Enumerates all files and subdirectories in a directory
         *
         * The run() method expects a single parameter, "directory", which
         * is a QString containing an absolute filesystem path. Assuming no
         * errors occurred, the completed() signal will be emitted with two
         * parameters:
         *
         * \li headers a QList<FileHeaderPointer>
         * \li size a qint64 containing the total size of all files
         */
        class NSU_EXPORT DirectoryEnumerator : public BlockingAsyncTask
        {
            Q_OBJECT

            public:

                virtual bool cancelable() const;

            private Q_SLOTS:

                virtual void run(const QVariantMap & parameters);
        };
    }
}

#endif // NSU_DIRECTORYENUMERATOR_H
