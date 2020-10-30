#include "live2dwidget.h"
#pragma execution_character_set("utf-8")
Live2DWidget::Live2DWidget(QString L2D_PATH,QWidget *parent) : QWidget(parent)
{
    live2d_path=L2D_PATH;
    setWindowTitle("雪风Live2D桌面");
    mSysTrayIcon = new QSystemTrayIcon(this);
    mSysTrayIcon->setIcon(QIcon(":/new/ico/snowing"));
    mSysTrayIcon->setToolTip(QObject::trUtf8("雪风Live2D桌面"));
    connect(mSysTrayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason)));
    connect(mSysTrayIcon,&QSystemTrayIcon::messageClicked,[&](){
        this->show();
    });
    //建立托盘操作的菜单
    createActions();
    createMenu();
    //在系统托盘显示此对象
    mSysTrayIcon->show();
    view=new QWebEngineView(this);
    view->resize(800,300);
    view->page()->setBackgroundColor(Qt::transparent);
    view->setAttribute(Qt::WA_TranslucentBackground);
    view->setStyleSheet("background:transparent");
    view->page()->setBackgroundColor(Qt::transparent);
    setWebview();


}
void Live2DWidget::setWebview(){
    view->page()->load(QUrl(live2d_path));
    view->show();

}

void Live2DWidget::on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason){
    case QSystemTrayIcon::Trigger:
        mSysTrayIcon->showMessage(QObject::trUtf8("Snowing Live2D"),QObject::trUtf8("welcome use me"),QSystemTrayIcon::Information,1000);
        break;
    case QSystemTrayIcon::DoubleClick:
        this->show();
        break;
    default:
        break;
    }
}

void Live2DWidget::createActions()
{
    mShowMainAction = new QAction(QObject::trUtf8("显示"),this);
    connect(mShowMainAction,SIGNAL(triggered()),this,SLOT(on_showMainAction()));

    mExitAppAction = new QAction(QObject::trUtf8("关闭"),this);
    connect(mExitAppAction,SIGNAL(triggered()),this,SLOT(on_exitAppAction()));

    mHideAppAction = new QAction(QObject::trUtf8("隐藏"),this);
    connect(mHideAppAction,&QAction::triggered,[&](){this->hide();});

    mAboutAppAction = new QAction(QObject::trUtf8("关于"),this);
    about_btn=new QPushButton();
    about_btn->setText(" 雪风Live2D桌面 \n 作者 林雪飞 \n qq 1017006174 \n b站ID 林雪飞 \n c语言学习群 255320966");
    about_btn->resize(412,550);

    about_btn->setFlat(true);
    about_btn->setStyleSheet("QPushButton{border-image:url(:/new/ico/logo);font-size:32px;color:rgb(255,0,0,200);background-color: rgba(0, 0, 0, 0)}");
    about_btn->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    about_btn->setAttribute(Qt::WA_TranslucentBackground);
    connect(about_btn,&QPushButton::clicked,[&](){about_btn->hide();});
    connect(mAboutAppAction,&QAction::triggered,[&](){about_btn->show();});
    mRefreshAppAction = new QAction(QObject::trUtf8("刷新"),this);
    connect(mRefreshAppAction,&QAction::triggered,[&](){
        this->setWebview();
    });

}

void Live2DWidget::createMenu()
{
    mMenu = new QMenu(this);
    mMenu->addAction(mShowMainAction);

//    mMenu->addSeparator();
    mMenu->addAction(mRefreshAppAction);
    mMenu->addAction(mExitAppAction);
    mMenu->addAction(mHideAppAction);
    mMenu->addAction(mAboutAppAction);
    mSysTrayIcon->setContextMenu(mMenu);
}

void Live2DWidget::on_showMainAction()
{
    this->show();
}

void Live2DWidget::on_exitAppAction()
{
    exit(0);
}

