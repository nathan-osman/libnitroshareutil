/*
 * libnitroshareutil
 * Copyright (C) 2013  Nathan Osman
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 */

#ifndef NSU_BLOCKINGASYNCTASK_H
#define NSU_BLOCKINGASYNCTASK_H

#include <nitroshare/util/asynctask.h>
#include "export.h"

namespace NitroShare
{
    namespace Util
    {
        class NSU_EXPORT BlockingAsyncTaskPrivate;

        /**
         * @brief Base class for all blocking asynchronous tasks.
         *
         * This class provides an interface for running a blocking operation
         * in an asynchronous manner. The operation is moved to a separate
         * thread where it can use queued signals to communicate status.
         */
        class NSU_EXPORT BlockingAsyncTask : public AsyncTask
        {
            Q_OBJECT

            public:

                /**
                 * @brief Creates the asynchronous task
                 * @param parent the parent QObject
                 */
                explicit BlockingAsyncTask(QObject * parent = nullptr);

                /**
                 * @brief Destroys the task
                 */
                virtual ~BlockingAsyncTask();

            public Q_SLOTS:

                virtual void start(const QVariantMap & parameters = QVariantMap());

            protected:

                /**
                 * @brief Indicates if the task was canceled
                 * @return true if the task was canceled
                 */
                bool wasCanceled() const;

            private:

                BlockingAsyncTaskPrivate * const d;
        };
    }
}

#endif // NSU_BLOCKINGASYNCTASK_H
