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
         */
        class NSU_EXPORT DirectoryEnumerator : public BlockingAsyncTask
        {
            Q_OBJECT

            public:

                /**
                 * @brief Indicates if the task can be canceled once started
                 * @return true
                 */
                virtual bool isCancelable() const;

            private Q_SLOTS:

                /**
                 * @brief Runs the task
                 * @param parameters see below
                 *
                 * This task expects a single parameter, "directory", which
                 * represents the directory to be enumerated.
                 */
                virtual void run(const QVariantMap & parameters);
        };
    }
}

#endif // NSU_DIRECTORYENUMERATOR_H
