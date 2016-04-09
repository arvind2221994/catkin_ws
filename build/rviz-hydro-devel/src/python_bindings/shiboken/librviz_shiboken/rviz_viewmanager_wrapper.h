#ifndef SBK_VIEWMANAGERWRAPPER_H
#define SBK_VIEWMANAGERWRAPPER_H

#define protected public

#include <shiboken.h>

#include <view_manager.h>

class ViewManagerWrapper : public rviz::ViewManager
{
public:
    virtual void childEvent(QChildEvent * arg__1);
    virtual void connectNotify(const char * signal);
    virtual void customEvent(QEvent * arg__1);
    virtual void disconnectNotify(const char * signal);
    virtual bool event(QEvent * arg__1);
    virtual bool eventFilter(QObject * arg__1, QEvent * arg__2);
    virtual void timerEvent(QTimerEvent * arg__1);
    virtual ~ViewManagerWrapper();
};

#endif // SBK_VIEWMANAGERWRAPPER_H

