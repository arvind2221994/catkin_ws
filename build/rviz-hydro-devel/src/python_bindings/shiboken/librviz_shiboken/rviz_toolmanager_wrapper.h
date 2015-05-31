#ifndef SBK_TOOLMANAGERWRAPPER_H
#define SBK_TOOLMANAGERWRAPPER_H

#define protected public

#include <shiboken.h>

#include <tool_manager.h>

class ToolManagerWrapper : public rviz::ToolManager
{
public:
    virtual void childEvent(QChildEvent * arg__1);
    virtual void connectNotify(const char * signal);
    virtual void customEvent(QEvent * arg__1);
    virtual void disconnectNotify(const char * signal);
    virtual bool event(QEvent * arg__1);
    virtual bool eventFilter(QObject * arg__1, QEvent * arg__2);
    virtual void timerEvent(QTimerEvent * arg__1);
    virtual ~ToolManagerWrapper();
};

#endif // SBK_TOOLMANAGERWRAPPER_H

