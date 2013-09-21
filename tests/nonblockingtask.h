/*
 * NitroShare - Send Any File to Any Device
 * Copyright (C) 2013  Nathan Osman
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NONBLOCKINGTASK_H
#define NONBLOCKINGTASK_H

#include <QTimer>

#include <nitroshare/util/asynctask.h>

class NonBlockingTask : public NitroShare::Util::AsyncTask
{
    Q_OBJECT

    public:

        virtual bool isProgressive() const { return true; }
        virtual bool isCancelable() const { return true; }
        virtual bool isBlocking() const { return false; }

    private Q_SLOTS:

        virtual void run(const QVariantMap &);

    private:

        QTimer timer;
        int count;
};

#endif // NONBLOCKINGTASK_H
