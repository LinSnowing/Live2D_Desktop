#include <QApplication>
#include<QWebEngineView>
#include<QScreen>
#include<iostream>
#include"live2dwidget.h"
#include<QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QScreen *screen=QGuiApplication::primaryScreen ();
    QRect mm=screen->availableGeometry();
    Live2DWidget w(a.applicationDirPath()+"./Live2D/demo.html");
    w.setGeometry(mm.width()-300,mm.height()-300,300,300);
    w.setAttribute(Qt::WA_TranslucentBackground);
    w.setWindowFlags(Qt::Tool|Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);
    w.show();
    return a.exec();
}
