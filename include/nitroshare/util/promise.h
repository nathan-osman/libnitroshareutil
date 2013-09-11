/*
 * libnitroshareutil
 * Copyright (C) 2013  Nathan Osman
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 */

#ifndef NSU_PROMISE_H
#define NSU_PROMISE_H

#include <QObject>
#include <QVariantMap>

#include "export.h"

namespace NitroShare
{
    namespace Util
    {
        /**
         * @brief An implementation of the promise pattern
         *
         * The Promise class represents an asynchronous task such as a network
         * request or computation. Each instance of this class can be used to
         * cancel the pending operation or receive notification when it
         * completes (by connecting to the completed() signal).
         */
        class NSU_EXPORT Promise : public QObject
        {
            Q_OBJECT
            
            public:
            
                /**
                 * @brief Creates a Promise object
                 * @param delete_on_finished whether the promise should delete itself after the finished signal is emitted
                 * @param parent the parent QObject
                 *
                 * Note: if you are creating a Promise object on the stack, you
                 * must specify false for delete_on_finished.
                 */
                Promise(bool delete_on_finished = true, QObject * parent = nullptr);
                
                /**
                 * @brief Waits for the promise to finish
                 * @return true if the promise completed
                 *
                 * Although this method blocks, it creates an event loop to
                 * allow for GUI repainting, etc.
                 */
                bool waitForFinished();

            Q_SIGNALS:

                /**
                 * @brief Emitted as progress is made
                 * @param value an integer between 0 and 100 inclusive
                 */
                void progress(int value);

                /**
                 * @brief Emitted when the promise has been canceled
                 */
                void canceled();

                /**
                 * @brief Emitted when an error occurs
                 * @param message a message describing the error
                 */
                void error(const QString & message);

                /**
                 * @brief Emitted when the promise has completed
                 * @param parameters any data expected to be returned by the task
                 */
                void completed(const QVariantMap & parameters = QVariantMap());

                /**
                 * @brief Emitted when the promise has finished
                 *
                 * This signal will always be emitted after the canceled(),
                 * error(), or completed() signal has been emitted.
                 */
                void finished();
        };
    }
}

#endif // NSU_PROMISE_H
