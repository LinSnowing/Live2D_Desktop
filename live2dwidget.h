#ifndef LIVE2DWIDGET_H
#define LIVE2DWIDGET_H
#include<QSystemTrayIcon>
#include <QWidget>
#include<QAction>
#include<QMenu>
#include<QPushButton>
#include<QWebEngineView>

class Live2DWidget : public QWidget
{
    Q_OBJECT
public:

    explicit Live2DWidget(QString L2D_PATH,QWidget *parent = nullptr);

    QSystemTrayIcon* mSysTrayIcon;
    QMenu *mMenu;
    QAction *mShowMainAction;
    QAction *mExitAppAction;
    QAction *mHideAppAction;
    QAction *mAboutAppAction;
    QAction *mRefreshAppAction;
    QPushButton *about_btn;
    QWebEngineView *view;
    QString live2d_path;
    void createActions();
    void createMenu();
    void get_keyboard_messege();
    void change_ico(int i);
    void setWebview();
private slots:
    void on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);
    void on_showMainAction();
    void on_exitAppAction();

public slots:
};

#endif // LIVE2DWIDGET_H
