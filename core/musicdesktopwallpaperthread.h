#ifndef MUSICDESKTOPWALLPAPERTHREAD_H
#define MUSICDESKTOPWALLPAPERTHREAD_H

#include <QThread>
#include <QMap>
#include <QVariant>
#include "musiclibexportglobal.h"

class MUSIC_EXPORT MusicDesktopWallpaperThread : public QThread
{
    Q_OBJECT
public:
    explicit MusicDesktopWallpaperThread(QObject *parent = 0);
    ~MusicDesktopWallpaperThread();

    void setParamters(const QMap<QString,QVariant>&);
    void stopAndQuitThread();

signals:
    void getCurrentFileName(QString&);

public slots:
    void start();
    void run();

protected:
    void setWallpaper(const QString&, int);

    bool m_run;
    bool m_returnToOrigin;
    int m_currentImageIndex;
    int m_originType;
    QMap<QString,QVariant> m_paramter;
    QString m_originPath;

};

#endif // MUSICDESKTOPWALLPAPERTHREAD_H