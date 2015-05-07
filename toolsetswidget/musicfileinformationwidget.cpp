#include "musicfileinformationwidget.h"
#include "ui_musicfileinformationwidget.h"
#include "../core/musicobject.h"
#include "../core/musicfileinformation.h"
#include <QDesktopServices>

MusicFileInformationWidget::MusicFileInformationWidget(QWidget *parent) :
    MusicMoveDialogAbstract(parent),
    ui(new Ui::MusicFileInformationWidget)
{
    ui->setupUi(this);
    QBitmap bmp(this->size());
    bmp.fill();
    QPainter p(&bmp);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.drawRoundedRect(bmp.rect(),4,4);
    setMask(bmp);
    //set window radius

    ui->topTitleCloseButton->setIcon(QIcon(QPixmap(":/share/searchclosed")));
    ui->topTitleCloseButton->setStyleSheet(MusicObject::QToolButtonStyle);
    ui->topTitleCloseButton->setCursor(QCursor(Qt::PointingHandCursor));
    ui->topTitleCloseButton->setToolTip(tr("Close"));
    connect(ui->topTitleCloseButton,SIGNAL(clicked()),SLOT(close()));

    ui->viewButton->setStyleSheet(MusicObject::MusicSettingMainButton);
    ui->viewButton->setCursor(QCursor(Qt::PointingHandCursor));
    connect(ui->viewButton,SIGNAL(clicked()),SLOT(musicOpenFileDir()));
}

MusicFileInformationWidget::~MusicFileInformationWidget()
{
    delete ui;
}

void MusicFileInformationWidget::musicOpenFileDir()
{
    QDesktopServices::openUrl(QUrl(QFileInfo(m_path).absolutePath(), QUrl::TolerantMode));
}

void MusicFileInformationWidget::setFileInformation(const QString& name)
{
    MusicFileInformation info;
    bool state = info.readFile(m_path = name);
    QFileInfo fin(name);
    QString check;
    ui->filePathEdit->setText( (check = name).isEmpty() ? "-" : check );
    ui->fileFormatEdit->setText( (check = fin.suffix() ).isEmpty() ? "-" : check );
    ui->fileSizeEdit->setText( (check = QString("%1 Byte").arg(fin.size()) )
                                .isEmpty() ? "-" : check );

    ui->fileAlbumEdit->setText( state ? ((check = info.getAlbum()).isEmpty() ? "-" : check) : "-" );
    ui->fileArtistEdit->setText( state ? ((check = info.getArtist()).isEmpty() ? "-" : check) : "-" );
    ui->fileGenreEdit->setText( state ? ((check = info.getGenre()).isEmpty() ? "-" : check) : "-" );
    ui->fileTitleEdit->setText( state ? ((check = info.getTitle()).isEmpty() ? "-" : check) : "-" );
    ui->fileYearEdit->setText( state ? ((check = info.getYear()).isEmpty() ? "-" : check) : "-" );
    ui->fileTimeEdit->setText( state ? ((check = info.getLengthString()).isEmpty() ? "-" : check) : "-" );

    ui->BitrateEdit->setText( state ? ((check = QString::number(info.getBitrate()) )
                              .isEmpty() ? "-" : check) : "-" );
    ui->ChannelNumberEdit->setText( state ? ((check = QString::number(info.getChannelNumber()) )
                                    .isEmpty() ? "-" : check) : "-" );
    ui->SamplingRateEdit->setText( state ? ((check = QString::number(info.getSamplingRate()) )
                                   .isEmpty() ? "-" : check) : "-" );
    ui->TrackNumEdit->setText( state ? ((check = info.getTrackNum()).isEmpty() ? "-" : check) : "-" );
    ui->descriptionEdit->setText( state ? ((check = QString("%1 %2").arg(info.getDescription())
                                   .arg(info.getVBRString())).isEmpty() ? "-" : check) : "-" );
}