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
#include <QVariantMap>

#include "export.h"

namespace NitroShare
{
    namespace Util
    {
        /**
         * @brief Base class for all asynchronous tasks
         */
        class NSU_EXPORT AsyncTask : public QObject
        {
            Q_OBJECT

            public:

                /**
                 * @brief Creates the asynchronous task
                 * @param parent the parent QObject
                 */
                explicit AsyncTask(QObject * parent = nullptr);

                /**
                 * @brief Indicates if the task emits progress updates
                 * @return true if the task is progressive
                 *
                 * By default, this method returns false.
                 */
                virtual bool isProgressive() const;

                /**
                 * @brief Indicates if the task can be canceled once started
                 * @return true if the task is cancelable
                 *
                 * By default, this method returns false.
                 */
                virtual bool isCancelable() const;

            Q_SIGNALS:

                /**
                 * @brief Indicates the current progress of the task
                 * @param value an integer between 0 and 100 inclusive
                 */
                void progress(int value);

                /**
                 * @brief Indicates that the task has been canceled
                 */
                void canceled();

                /**
                 * @brief Indicates that an error has occurred
                 * @param message a description of the error
                 */
                void error(const QString & message);

                /**
                 * @brief Indicates that the task successfully completed
                 * @param parameters any data returned by the task
                 */
                void completed(const QVariantMap & parameters = QVariantMap());

                /**
                 * @brief Indicates that the task has finished
                 *
                 * This signal is emitted in addition to canceled(), error(), or
                 * completed(). If you need to invoke a slot regardless of
                 * whether the task completes or not, you should use this
                 * signal.
                 */
                void finished();

                // Semantically speaking, this should really be a slot.
                // However, because it behaves differently depending on
                // whether this is a blocking task or not, it's a signal.

                /**
                 * @brief Cancels the task
                 *
                 * Not all tasks can be canceled. You can determine if a task
                 * can be canceled with isCancelable().
                 */
                void cancel();

            public Q_SLOTS:

                /**
                 * @brief Starts the task
                 * @param parameters any data expected by the task
                 */
                virtual void start(const QVariantMap & parameters = QVariantMap());

            protected Q_SLOTS:

                /**
                 * @brief Runs the task
                 * @param parameters any data expected by the task
                 *
                 * This method is overridden in derived classes and performs
                 * the operations of the task. If this is a blocking task, you
                 * must emit one of canceled(), error(), or completed() before
                 * this function returns.
                 */
                virtual void run(const QVariantMap & parameters) = 0;
        };
    }
}

#endif // NSU_ASYNCTASK_H
