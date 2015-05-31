#ifndef SBK_VISUALIZATIONFRAMEWRAPPER_H
#define SBK_VISUALIZATIONFRAMEWRAPPER_H

#define protected public

#include <shiboken.h>

#include <visualization_frame.h>

class VisualizationFrameWrapper : public rviz::VisualizationFrame
{
public:
    VisualizationFrameWrapper(QWidget * parent = 0);
    virtual void actionEvent(QActionEvent * event);
    virtual rviz::PanelDockWidget * addPane(const QString & name, QWidget * panel, Qt::DockWidgetArea area = Qt::LeftDockWidgetArea, bool floating = true);
    virtual void changeEvent(QEvent * event);
    virtual void childEvent(QChildEvent * arg__1);
    virtual void closeEvent(QCloseEvent * event);
    virtual void connectNotify(const char * signal);
    virtual void contextMenuEvent(QContextMenuEvent * event);
    virtual QMenu * createPopupMenu();
    virtual void customEvent(QEvent * arg__1);
    virtual int devType() const;
    virtual void disconnectNotify(const char * signal);
    virtual void dragEnterEvent(QDragEnterEvent * event);
    virtual void dragLeaveEvent(QDragLeaveEvent * event);
    virtual void dragMoveEvent(QDragMoveEvent * event);
    virtual void dropEvent(QDropEvent * event);
    virtual void enterEvent(QEvent * event);
    virtual bool event(QEvent * event);
    virtual bool eventFilter(QObject * arg__1, QEvent * arg__2);
    virtual void focusInEvent(QFocusEvent * event);
    virtual bool focusNextPrevChild(bool next);
    virtual void focusOutEvent(QFocusEvent * event);
    virtual QWidget * getParentWindow();
    virtual int heightForWidth(int arg__1) const;
    virtual void hideEvent(QHideEvent * event);
    virtual void inputMethodEvent(QInputMethodEvent * event);
    virtual QVariant inputMethodQuery(Qt::InputMethodQuery arg__1) const;
    virtual void keyPressEvent(QKeyEvent * event);
    virtual void keyReleaseEvent(QKeyEvent * event);
    virtual void languageChange();
    virtual void leaveEvent(QEvent * event);
    virtual void load(const rviz::Config & config);
    virtual int metric(QPaintDevice::PaintDeviceMetric arg__1) const;
    virtual QSize minimumSizeHint() const;
    virtual void mouseDoubleClickEvent(QMouseEvent * event);
    virtual void mouseMoveEvent(QMouseEvent * event);
    virtual void mousePressEvent(QMouseEvent * event);
    virtual void mouseReleaseEvent(QMouseEvent * event);
    virtual void moveEvent(QMoveEvent * event);
    virtual void onDockPanelVisibilityChange(bool visible);
    virtual QPaintEngine * paintEngine() const;
    virtual void paintEvent(QPaintEvent * event);
    virtual void resizeEvent(QResizeEvent * event);
    virtual void save(rviz::Config config);
    virtual void setStatus(const QString & message);
    virtual void setVisible(bool visible);
    virtual void showEvent(QShowEvent * event);
    virtual QSize sizeHint() const;
    virtual void tabletEvent(QTabletEvent * event);
    virtual void timerEvent(QTimerEvent * arg__1);
    virtual void wheelEvent(QWheelEvent * event);
    virtual ~VisualizationFrameWrapper();
};

#endif // SBK_VISUALIZATIONFRAMEWRAPPER_H

