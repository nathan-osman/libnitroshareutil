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

#include <QSignalSpy>
#include <QTest>

#include <nitroshare/util/parameterbuilder.h>
#include "blockingtask.h"
#include "nonblockingtask.h"
#include "testasynctask.h"

void TestAsyncTask::testBlocking()
{
    BlockingTask task;
    run(task);
}

void TestAsyncTask::testNonBlocking()
{
    NonBlockingTask task;
    run(task);
}

void TestAsyncTask::run(NitroShare::Util::AsyncTask & task)
{
    QSignalSpy progress_spy(&task, SIGNAL(progress(int)));
    QSignalSpy completed_spy(&task, SIGNAL(completed(QVariantMap)));
    QSignalSpy finished_spy(&task, SIGNAL(finished()));

    task.start(NitroShare::Util::ParameterBuilder("param", 42));
    QTest::qWait(600);

    QCOMPARE(progress_spy.count(), 5);
    QCOMPARE(completed_spy.count(), 1);
    QCOMPARE(finished_spy.count(), 1);

    QCOMPARE(completed_spy.at(0).at(0).toMap().value("param").toInt(), 42);
}
