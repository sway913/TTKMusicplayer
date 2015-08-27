#ifndef MUSICLRCFLOATSETTINGWIDGET_H
#define MUSICLRCFLOATSETTINGWIDGET_H

#include "musiclrcfloatabstractwidget.h"

class MUSIC_WIDGET_EXPORT MusicLrcFloatSettingWidget : public MusicLrcFloatAbstractWidget
{
    Q_OBJECT
public:
    explicit MusicLrcFloatSettingWidget(QWidget *parent = 0);

signals:
    void widgetClose();

public slots:
    void show();
    void lrcSizeUpChanged();
    void lrcSizeLowChanged();
    void lrcMusicBackgroundChanged();
    void lrcArtBackgroundChanged();

protected:
    virtual void enterEvent(QEvent *){}
    virtual void leaveEvent(QEvent *event);

};

#endif // MUSICLRCFLOATSETTINGWIDGET_H