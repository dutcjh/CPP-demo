#include "musicwidget.h"
#include<QVBoxLayout>
#include<QGridLayout>
#include<QPixmap>
#include<QPalette>
#include<QPainter>
#include<QColor>
#include<QHeaderView>
#include<QToolBar>
musicWidget::musicWidget(QWidget *parent)

{
    this->setWindowFlags(Qt::FramelessWindowHint);
    //this->setAttribute(Qt::WA_TranslucentBackground);//背景透明
    this->setWindowIcon(QIcon(":images/icon.png"));
    this->setMaximumSize(600,350);
    this->setMinimumSize(600,350);
    QPixmap pix1(":images/4.png");
    pix1=pix1.scaled(this->width(),this->height());
    this->setAutoFillBackground(true);
    QPalette palette;
    //palette.setColor(QPalette::Window,QColor(Qt::white));
    palette.setBrush(QPalette::Background, QBrush(QPixmap(pix1)));
    this->setPalette(palette);

    namelabel=new QLabel;

    slider=new QSlider(Qt::Horizontal);
    slider->setValue(0);
    slider->setMaximum(100);

    playBtn=new QPushButton(QIcon(":/images/play.png"),tr(" "));
    playBtn->setMaximumSize(50,30);
    playBtn->setFlat(true);
    playBtn->setStatusTip(tr("播放"));


    tablewidget=new QTableWidget;
    tablewidget->setColumnCount(3);
    tablewidget->setFrameShape(QFrame::NoFrame);

    QPalette pale;
    pale.setBrush(QPalette::Base,QColor(255,255,255,0));
    tablewidget->setPalette(pale);


    tablewidget->setSelectionMode(QAbstractItemView::SingleSelection); //  设置选择的模式为单选择

    tablewidget->setSelectionBehavior(QAbstractItemView::SelectRows); //设置每次选一行

    QStringList stringlist;
    stringlist<<tr("歌手")<<tr("歌名")<<tr("格式");

    tablewidget->setHorizontalHeaderLabels(stringlist);
    tablewidget->verticalHeader()->setVisible(false);
    tablewidget->horizontalHeader()->resizeSection(0,150);
    tablewidget->horizontalHeader()->setStretchLastSection(true);
    tablewidget->horizontalHeader()->setStyleSheet("QHeaderView {background-color:255,255,255,0 } "
                                                  "QHeaderView::section {background-color:255,255,255,0;"
                                                  "color: 255,255,255,0;padding-left: 4px;border: 0px solid 255,255,255,0;}");

    playstylecombox=new QComboBox;

    playstylecombox->addItem(tr("循环播放"));
    playstylecombox->addItem(tr("列表播放"));
    playstylecombox->addItem(tr("随机播放"));
    playstylecombox->addItem(tr("单曲循环"));
    playstylecombox->setMaximumSize(70,30);

    trayicon=new QSystemTrayIcon(QIcon(":images/icon.png"));
    playlist=new QMediaPlaylist;
   closeBtn=new QPushButton(QIcon(":images/close.png"),tr(" "));
   closeBtn->setMaximumSize(50,30);
   closeBtn->setFlat(true);

    addmusicBtn=new QPushButton(QIcon(":images/open.png"),tr(" "));
    addmusicBtn->setMaximumSize(70,30);
    addmusicBtn->setFlat(true);
    stopBtn=new QPushButton(QIcon(":images/stop.png"),tr(" "));
    stopBtn->setMaximumSize(50,30);
    stopBtn->setFlat(true);
    nextBtn=new QPushButton(QIcon(":images/skipForward.png"),tr(" "));
    nextBtn->setMaximumSize(50,30);
    nextBtn->setFlat(true);
    lastBtn=new QPushButton(QIcon(":images/skipBackward.png"),tr(" "));
    lastBtn->setMaximumSize(50,30);
    lastBtn->setFlat(true);


    imageBtn=new QPushButton(QIcon(":images/image.png"),tr(" "));
    imageBtn->setMaximumSize(50,30);
    imageBtn->setFlat(true);

    windowminBtn=new QPushButton(QIcon(":images/min.png"),tr(" "));
    windowminBtn->setMaximumSize(50,30);
    windowminBtn->setFlat(true);
    //windowminBtn->setWindowFlags(Qt::WindowMinimizeButtonHint);

    QHBoxLayout* layout=new QHBoxLayout;
    layout->addWidget(lastBtn);
    layout->addWidget(playBtn);
    layout->addWidget(stopBtn);
    layout->addWidget(nextBtn);
    layout->addWidget(addmusicBtn);

    layout->addWidget(imageBtn);
    layout->addWidget(windowminBtn);
    layout->addWidget(closeBtn);
    layout->addWidget(playstylecombox);

    QVBoxLayout* v=new QVBoxLayout(this);

    v->addWidget(tablewidget);
    v->addWidget(namelabel);
    v->addWidget(slider);
    v->addLayout(layout);

    playlist->setPlaybackMode(QMediaPlaylist::Random);
    player = new QMediaPlayer;


    player->setPlaylist(playlist);
    player->setVolume(50);

    timer=new QTimer(this);


    connect(timer,SIGNAL(timeout()),this,SLOT(changslider()));
    connect(playstylecombox,SIGNAL(currentIndexChanged(int)),this,SLOT(changplaystyle(int)));
    connect(windowminBtn,SIGNAL(clicked()),this,SLOT(showMinimized()));
    connect(imageBtn,SIGNAL(clicked()),this,SLOT(changimage()));
    connect(addmusicBtn,SIGNAL(clicked(bool)),this,SLOT(readfile()));
    connect(stopBtn,SIGNAL(clicked(bool)),this,SLOT(playstop()));
    connect(playBtn,SIGNAL(clicked(bool)),this,SLOT(playstate()));
    connect(nextBtn,SIGNAL(clicked(bool)),this,SLOT(nextplay()));
    connect(lastBtn,SIGNAL(clicked(bool)),this,SLOT(lastplay()));
    connect(closeBtn,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(tablewidget,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(changplay(int,int)));
    connect(playlist,SIGNAL(currentIndexChanged(int)),this,SLOT(updatenamelabel(int)));
    connect(playlist,SIGNAL(currentIndexChanged(int)),this,SLOT(updateslider()));
    timer->setInterval(5000);

}

musicWidget::~musicWidget()
{

}




QString musicWidget::changfilename(QString filepath)
{
    QString tmp;
    tmp.clear();
       if(!filepath.isEmpty()){
           for(int i=0;i<filepath.count();i++){
               if(filepath[i]=='/'){
                   for(int j=0;j<=i;j++){
                       filepath[j]=' ';
                   }
               }
               tmp=filepath;
           }

          return tmp;
       }
}


void musicWidget::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() - this->dpos);
}

void musicWidget::mousePressEvent(QMouseEvent *event)
{
    this->windowPos= this->pos();                // 获得部件当前位置
    this->mousePos = event->globalPos();     // 获得鼠标位置
    this->dpos = mousePos - windowPos;       // 移动后部件所在的位置
}

void musicWidget::changslider()
{
    int v=slider->value();
    slider->setValue(++v);

}


void musicWidget::changplaystyle(int)
{
    int v=playstylecombox->currentIndex();
    switch (v) {
    case 1:
        playlist->setPlaybackMode(QMediaPlaylist::Loop);

        break;
    case 2:
        playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    case 3:
        playlist->setPlaybackMode(QMediaPlaylist::Random);
    case 4:
        playlist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
    default:
        break;
    }


}

void musicWidget::playstate()
{
    player->play();

    timer->start();

}

void musicWidget::playstop()
{
    player->stop();
    timer->stop();
}

void musicWidget::nextplay()
{
int v=playlist->currentIndex();
//QString name=playlist->currentMedia();
if(++v==playlist->mediaCount())
{
    v=0;
}
    playlist->setCurrentIndex(v);
    //playstate();
    player->play();
  //  namelabel->setText(name);

    timer->start();

}


void musicWidget::lastplay()
{
    int v=playlist->currentIndex();
    if(--v<0)
        v=0;
    playlist->setCurrentIndex(v);
    //playstate();
    player->play();
    timer->start();
}

QStringList musicWidget::readfile()
{
    QStringList musiclist=QFileDialog::getOpenFileNames(this,tr("选择文件"),tr("/"),tr("music file(*.mp3)"));



    for(int i=0;i<musiclist.count();i++){
       QString path=musiclist.at(i);

    if(!path.isEmpty()){
           playlist->addMedia(QUrl::fromLocalFile(path));
        QString filename=changfilename(path);
        int rownum=tablewidget->rowCount();
        QString str=filename.section("-",1,2);
        QString str1=str.split("[").front();
        tablewidget->insertRow(rownum);
        tablewidget->setItem(rownum,0,new QTableWidgetItem(filename.split("-").front()));
        tablewidget->setItem(rownum,1,new QTableWidgetItem(str1));
        tablewidget->setItem(rownum,2,new QTableWidgetItem(filename.split(".").last()));
        tablewidget->setItem(rownum,3,new QTableWidgetItem(path));

        tablewidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }
    }
    return musiclist;
}

void musicWidget::changplay(int index, int )
{
    playlist->setCurrentIndex(index);
    player->play();
}

void musicWidget::changimage()
{
    QString imagepath=QFileDialog::getOpenFileName(this,tr("选择图片"),tr("/"),tr("image file(*.png)"));
    QPixmap pix2(imagepath);
    pix2=pix2.scaled(this->width(),this->height());
    this->setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(pix2)));
    this->setPalette(palette);

}

void musicWidget::updatenamelabel(int index)
{
    namelabel->setText(tablewidget->item(index,1)->text());

}

void musicWidget::updateslider()
{
    slider->setValue(0);
}
