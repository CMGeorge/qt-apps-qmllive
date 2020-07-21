/****************************************************************************
**
** Copyright (C) 2018 Luxoft Sweden AB
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QmlLive tool.
**
** $QT_BEGIN_LICENSE:GPL-QTAS$
** Commercial License Usage
** Licensees holding valid commercial Qt Automotive Suite licenses may use
** this file in accordance with the commercial license agreement provided
** with the Software or, alternatively, in accordance with the terms
** contained in a written agreement between you and The Qt Company.  For
** licensing terms and conditions see https://www.qt.io/terms-conditions.
** For further information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
** SPDX-License-Identifier: GPL-3.0
**
****************************************************************************/

#ifndef RUNTIMEMANAGER_H
#define RUNTIMEMANAGER_H

#include <QObject>
#include <QProcess>
#include "livehubengine.h"
#include "runtimeprocess.h"

QT_FORWARD_DECLARE_CLASS(QDockWidget);

class RuntimeManager : public QObject
{
    Q_OBJECT
public:
    explicit RuntimeManager(QObject *parent = nullptr);
    ~RuntimeManager();

    void startPrimeRuntime();
    void setRuntimeBinaryPath(const QString &path);
    void setLiveHubEngine(LiveHubEngine *engine);
    void setWorkspace(const QString &workspace);
    void finishProcesses();
    void setPluginPath(const QString& path);
    void setImportPathList(const QStringList& paths);
    void restartAll();

private:
    QStringList argumentsList(const int& port, const QString& titles, const bool hideButtons = false);
    void restartPrimeRuntime();
    void stopPrimeRuntime();

signals:
    void logWidgetAdded(QDockWidget* log);
    void logWidgetRemoved(QDockWidget* log);

public slots:
    void onPrimeRuntimeError(QProcess::ProcessError error);
    void onPrimeRuntimeChanged();
    void onPrimeRuntimeConnected();
    void setPrimeCurrentFile(const LiveDocument &currentFile);
    void newRuntimeWindow(const QString &document);
    void initConnectToServer();
    void onConnected();
    void onRuntimeStarted();
    void updateRuntimePath(const QString& path);
    void onError(QProcess::ProcessError error);

private:
    int m_port;
    QString m_runtimeBinaryPath;
    QString m_workspace;
    RuntimeProcess *m_primeRuntime; //this prime runtime supposed to be QML Live runtime which follows the activeDocumetChanged Slot
    LiveHubEngine *m_engine;
    LiveDocument* m_currentFile;
    RuntimeProcess* m_curproc;
    QStringList* m_imports;
    QString* m_pluginPath;
    QList<QDockWidget*> m_logDocks;
    QList<RuntimeProcess*> m_runtimes;
    bool m_primeRuntimeConnected;
    LiveDocument* m_primeCurrentFile;
};

#endif // RUNTIMEMANAGER_H
