/*
 * libnitroshareutil
 * Copyright (C) 2013  Nathan Osman
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 */

#ifndef NSU_ASYNCTASK_H
#define NSU_ASYNCTASK_H

#include <QObject>

#include <nitroshare/util/promise.h>
#include "export.h"

namespace NitroShare
{
    namespace Util
    {
        class NSU_EXPORT AsyncTaskPrivate;

        /**
         * @brief Base class for all asynchronous tasks
         *
         * Asynchronous tasks that inherit from this class implement the the
         * actual task to be performed in the virtual run() method.
         */
        class NSU_EXPORT AsyncTask : public QObject
        {
            Q_OBJECT

            public:

                /**
                 * @brief Creates an instance of the asynchronous task
                 * @param parent the parent QObject
                 */
                explicit AsyncTask(QObject * parent = nullptr);

                /**
                 * @brief Destroys the asynchronous task
                 */
                virtual ~AsyncTask();

            protected:

                /**
                 * @brief Indicates whether the task was canceled
                 * @return true if the task was canceled
                 */
                bool wasCanceled() const;

            protected Q_SLOTS:

                /**
                 * @brief Performs the task
                 * @param parameters any data expected by the task
                 */
                virtual void run(const QVariantMap & parameters) = 0;

            private:

                AsyncTaskPrivate * const d;
        };
    }
}

#endif // NSU_ASYNCTASK_H
