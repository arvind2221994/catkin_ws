#ifndef SBK_TOOLWRAPPER_H
#define SBK_TOOLWRAPPER_H

#define protected public

#include <shiboken.h>

#include <tool.h>

class ToolWrapper : public rviz::Tool
{
public:
    ToolWrapper();
    virtual void activate();
    virtual void childEvent(QChildEvent * arg__1);
    virtual void connectNotify(const char * signal);
    virtual void customEvent(QEvent * arg__1);
    virtual void deactivate();
    virtual void disconnectNotify(const char * signal);
    virtual bool event(QEvent * arg__1);
    virtual bool eventFilter(QObject * arg__1, QEvent * arg__2);
    virtual QString getClassId() const;
    virtual rviz::Property * getPropertyContainer() const;
    virtual void load(const rviz::Config & config);
    virtual void onInitialize();
    virtual void save(rviz::Config config) const;
    virtual void setClassId(const QString & class_id);
    virtual void timerEvent(QTimerEvent * arg__1);
    virtual void update(float wall_dt, float ros_dt);
    virtual ~ToolWrapper();
};

#endif // SBK_TOOLWRAPPER_H

