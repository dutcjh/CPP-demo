#ifndef MUSICWIDGET_H
#define MUSICWIDGET_H

//#include <QWidget>
#include<QMediaPlaylist>
#include<QMediaPlayer>
#include<QVideoWidget>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QHBoxLayout>
#include<QFileDialog>
#include<QMenuBar>
#include<QMenu>
#include<QAction>
#include<QFrame>
#include<QTableWidget>
#include<QTableView>
#include<QByteArray>
#include<QMouseEvent>
#include<QPoint>
#include<QTreeWidgetItem>
#include<QSystemTrayIcon>
#include<QComboBox>
#include<QTimer>
#include<QSlider>
class musicWidget : public QWidget
{
    Q_OBJECT

public:
    musicWidget(QWidget *parent = 0);
    ~musicWidget();

    QString changfilename(QString);
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
protected:
//    void closeEvent(QCloseEvent *);
public slots:
    void changslider();
    void changplaystyle(int );
    void playstate();
    void playstop();
    void nextplay();
    void lastplay();
    QStringList readfile();
    void changplay(int,int);
    void changimage();
    void updatenamelabel(int);
    void updateslider();
private:
    QTimer* timer;
    QSlider* slider;
    QComboBox* playstylecombox;

    QSystemTrayIcon* trayicon;
    QPoint dpos;
    QPoint windowPos;
    QPoint  mousePos;

    QPushButton* imageBtn;
    QPushButton* windowminBtn;
    QPushButton* playBtn;
    QPushButton* closeBtn;
    QByteArray actionlist;
    QTableWidget* tablewidget;

    QMediaPlayer* player;
    QMediaPlaylist* playlist;
    QVideoWidget* videoWidget;
    QLabel* namelabel;
    QPushButton* stopBtn;
    QPushButton* nextBtn;
    QPushButton* lastBtn;
    QPushButton* addmusicBtn;
};

#endif // MUSICWIDGET_H
