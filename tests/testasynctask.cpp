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
#include "task.h"
#include "testasynctask.h"

void TestAsyncTask::testCompleted()
{
    Task task;
    run(task, false);
}

void TestAsyncTask::testBlockingCompleted()
{
    BlockingTask task;
    run(task, false);
}

void TestAsyncTask::testCanceled()
{
    Task task;
    run(task, true);
}

void TestAsyncTask::testBlockingCanceled()
{
    BlockingTask task;
    run(task, true);
}

void TestAsyncTask::run(NitroShare::Util::AsyncTask & task, bool cancel)
{
    QSignalSpy progress_spy(&task,  SIGNAL(progress(int)));
    QSignalSpy canceled_spy(&task,  SIGNAL(canceled()));
    QSignalSpy completed_spy(&task, SIGNAL(completed(QVariantMap)));
    QSignalSpy finished_spy(&task,  SIGNAL(finished()));

    task.start(NitroShare::Util::ParameterBuilder("param", 42));
    QTest::qWait(cancel?300:600);

    if(cancel)
    {
        task.cancel();
        QTest::qWait(300);
    }

    // If we canceled, fewer than five progress signals should have been emitted
    if(cancel)
        QVERIFY(0 < progress_spy.count() < 5);
    else
        QCOMPARE(progress_spy.count(), 5);

    QCOMPARE(canceled_spy.count(),  cancel?1:0);
    QCOMPARE(completed_spy.count(), cancel?0:1);
    QCOMPARE(finished_spy.count(), 1);

    if(!cancel)
        QCOMPARE(completed_spy.at(0).at(0).toMap().value("param").toInt(), 42);
}
