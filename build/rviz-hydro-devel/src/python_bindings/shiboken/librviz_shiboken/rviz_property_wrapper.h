#ifndef SBK_PROPERTYWRAPPER_H
#define SBK_PROPERTYWRAPPER_H

#define protected public

#include <shiboken.h>

#include <property.h>

class PropertyWrapper : public rviz::Property
{
public:
    PropertyWrapper(const QString & name = QString(), const QVariant default_value = QVariant(), const QString & description = QString(), rviz::Property * parent = 0, const char * changed_slot = 0, QObject * receiver = 0);
    virtual void addChild(rviz::Property * child, int index = -1);
    virtual rviz::Property * childAtUnchecked(int index) const;
    virtual void childEvent(QChildEvent * arg__1);
    virtual void collapse();
    virtual void connectNotify(const char * signal);
    virtual QWidget * createEditor(QWidget * parent, const QStyleOptionViewItem & option);
    virtual void customEvent(QEvent * arg__1);
    virtual void disconnectNotify(const char * signal);
    virtual bool event(QEvent * arg__1);
    virtual bool eventFilter(QObject * arg__1, QEvent * arg__2);
    virtual void expand();
    virtual QString getDescription() const;
    virtual bool getDisableChildren();
    virtual bool getHidden() const;
    virtual QIcon getIcon() const;
    virtual QString getName() const;
    virtual bool getReadOnly();
    virtual QVariant getValue() const;
    virtual QVariant getViewData(int column, int role) const;
    virtual QFlags<Qt::ItemFlag> getViewFlags(int column) const;
    virtual void load(const rviz::Config & config);
    virtual void moveChild(int from_index, int to_index);
    virtual int numChildren() const;
    virtual bool paint(QPainter * painter, const QStyleOptionViewItem & option) const;
    virtual void removeChildren(int start_index = 0, int count = -1);
    virtual void save(rviz::Config config) const;
    virtual void setDescription(const QString & description);
    virtual void setHidden(bool hidden);
    virtual void setIcon(const QIcon & icon);
    virtual void setName(const QString & name);
    virtual void setReadOnly(bool read_only);
    virtual bool setValue(const QVariant & new_value);
    virtual rviz::Property * subProp(const QString & sub_name);
    virtual rviz::Property * takeChildAt(int index);
    virtual void timerEvent(QTimerEvent * arg__1);
    virtual ~PropertyWrapper();
};

#endif // SBK_PROPERTYWRAPPER_H

