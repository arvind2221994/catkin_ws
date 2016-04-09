#ifndef SBK_VISUALIZATIONMANAGERWRAPPER_H
#define SBK_VISUALIZATIONMANAGERWRAPPER_H

#define protected public

#include <shiboken.h>

#include <visualization_manager.h>

class VisualizationManagerWrapper : public rviz::VisualizationManager
{
public:
    virtual unsigned int getDefaultVisibilityBit() const;
    virtual QString getHelpPath() const;
    virtual rviz::DisplayGroup * getRootDisplayGroup() const;
    virtual rviz::ToolManager * getToolManager() const;
    virtual rviz::ViewManager * getViewManager() const;
    virtual void setHelpPath(const QString & help_path);
    virtual void setStatus(const QString & message);
    virtual ~VisualizationManagerWrapper();
};

#endif // SBK_VISUALIZATIONMANAGERWRAPPER_H

