

#ifndef SBK_LIBRVIZ_SHIBOKEN_PYTHON_H
#define SBK_LIBRVIZ_SHIBOKEN_PYTHON_H

//workaround to access protected functions
#define protected public

#include <sbkpython.h>
#include <conversions.h>
#include <sbkenum.h>
#include <basewrapper.h>
#include <bindingmanager.h>
#include <memory>

// Module Includes
#include <pyside_qtcore_python.h>
#include <pyside_qtgui_python.h>

// Binded library includes
#include <visualization_manager.h>
#include <display.h>
#include <view_controller.h>
#include <view_manager.h>
#include <panel_dock_widget.h>
#include <yaml_config_reader.h>
#include <property.h>
#include <visualization_frame.h>
#include <tool_manager.h>
#include <ogre_logging.h>
#include <display_group.h>
#include <config.h>
#include <yaml_config_writer.h>
#include <bool_property.h>
#include <tool.h>
// Conversion Includes - Primitive Types
#include <QStringList>
#include <qabstractitemmodel.h>
#include <QString>
#include <signalmanager.h>
#include <typeresolver.h>
#include <QTextDocument>
#include <QtConcurrentFilter>

// Conversion Includes - Container Types
#include <QMap>
#include <QStack>
#include <QLinkedList>
#include <QVector>
#include <QSet>
#include <QPair>
#include <pysideconversions.h>
#include <QQueue>
#include <QList>
#include <QMultiMap>

// Type indices
#define SBK_RVIZ_IDX                                                 0
#define SBK_RVIZ_YAMLCONFIGWRITER_IDX                                17
#define SBK_RVIZ_YAMLCONFIGREADER_IDX                                16
#define SBK_RVIZ_OGRELOGGING_IDX                                     7
#define SBK_RVIZ_VISUALIZATIONMANAGER_IDX                            15
#define SBK_RVIZ_CONFIG_IDX                                          2
#define SBK_RVIZ_CONFIG_TYPE_IDX                                     4
#define SBK_RVIZ_CONFIG_MAPITERATOR_IDX                              3
#define SBK_RVIZ_VISUALIZATIONFRAME_IDX                              14
#define SBK_RVIZ_PANELDOCKWIDGET_IDX                                 8
#define SBK_RVIZ_PROPERTY_IDX                                        9
#define SBK_RVIZ_BOOLPROPERTY_IDX                                    1
#define SBK_RVIZ_DISPLAY_IDX                                         5
#define SBK_RVIZ_DISPLAYGROUP_IDX                                    6
#define SBK_RVIZ_VIEWCONTROLLER_IDX                                  12
#define SBK_RVIZ_TOOLMANAGER_IDX                                     11
#define SBK_RVIZ_TOOL_IDX                                            10
#define SBK_RVIZ_VIEWMANAGER_IDX                                     13
#define SBK_librviz_shiboken_IDX_COUNT                               18

// This variable stores all Python types exported by this module.
extern PyTypeObject** Sbklibrviz_shibokenTypes;

// This variable stores all type converters exported by this module.
extern SbkConverter** Sbklibrviz_shibokenTypeConverters;

// Converter indices
#define SBK_LIBRVIZ_SHIBOKEN_QLIST_QOBJECTPTR_IDX                    0 // const QList<QObject * > &
#define SBK_LIBRVIZ_SHIBOKEN_QLIST_QBYTEARRAY_IDX                    1 // QList<QByteArray >
#define SBK_LIBRVIZ_SHIBOKEN_QLIST_QACTIONPTR_IDX                    2 // QList<QAction * >
#define SBK_LIBRVIZ_SHIBOKEN_QLIST_QDOCKWIDGETPTR_IDX                3 // QList<QDockWidget * >
#define SBK_LIBRVIZ_SHIBOKEN_QLIST_QVARIANT_IDX                      4 // QList<QVariant >
#define SBK_LIBRVIZ_SHIBOKEN_QLIST_QSTRING_IDX                       5 // QList<QString >
#define SBK_LIBRVIZ_SHIBOKEN_QMAP_QSTRING_QVARIANT_IDX               6 // QMap<QString, QVariant >
#define SBK_librviz_shiboken_CONVERTERS_IDX_COUNT                    7

// Macros for type check

namespace Shiboken
{

// PyType functions, to get the PyObjectType for a type T
template<> inline PyTypeObject* SbkType< ::rviz::YamlConfigWriter >() { return reinterpret_cast<PyTypeObject*>(Sbklibrviz_shibokenTypes[SBK_RVIZ_YAMLCONFIGWRITER_IDX]); }
template<> inline PyTypeObject* SbkType< ::rviz::YamlConfigReader >() { return reinterpret_cast<PyTypeObject*>(Sbklibrviz_shibokenTypes[SBK_RVIZ_YAMLCONFIGREADER_IDX]); }
template<> inline PyTypeObject* SbkType< ::rviz::OgreLogging >() { return reinterpret_cast<PyTypeObject*>(Sbklibrviz_shibokenTypes[SBK_RVIZ_OGRELOGGING_IDX]); }
template<> inline PyTypeObject* SbkType< ::rviz::VisualizationManager >() { return reinterpret_cast<PyTypeObject*>(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONMANAGER_IDX]); }
template<> inline PyTypeObject* SbkType< ::rviz::Config::Type >() { return Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_TYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::rviz::Config >() { return reinterpret_cast<PyTypeObject*>(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_IDX]); }
template<> inline PyTypeObject* SbkType< ::rviz::Config::MapIterator >() { return reinterpret_cast<PyTypeObject*>(Sbklibrviz_shibokenTypes[SBK_RVIZ_CONFIG_MAPITERATOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::rviz::VisualizationFrame >() { return reinterpret_cast<PyTypeObject*>(Sbklibrviz_shibokenTypes[SBK_RVIZ_VISUALIZATIONFRAME_IDX]); }
template<> inline PyTypeObject* SbkType< ::rviz::PanelDockWidget >() { return reinterpret_cast<PyTypeObject*>(Sbklibrviz_shibokenTypes[SBK_RVIZ_PANELDOCKWIDGET_IDX]); }
template<> inline PyTypeObject* SbkType< ::rviz::Property >() { return reinterpret_cast<PyTypeObject*>(Sbklibrviz_shibokenTypes[SBK_RVIZ_PROPERTY_IDX]); }
template<> inline PyTypeObject* SbkType< ::rviz::BoolProperty >() { return reinterpret_cast<PyTypeObject*>(Sbklibrviz_shibokenTypes[SBK_RVIZ_BOOLPROPERTY_IDX]); }
template<> inline PyTypeObject* SbkType< ::rviz::Display >() { return reinterpret_cast<PyTypeObject*>(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAY_IDX]); }
template<> inline PyTypeObject* SbkType< ::rviz::DisplayGroup >() { return reinterpret_cast<PyTypeObject*>(Sbklibrviz_shibokenTypes[SBK_RVIZ_DISPLAYGROUP_IDX]); }
template<> inline PyTypeObject* SbkType< ::rviz::ViewController >() { return reinterpret_cast<PyTypeObject*>(Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWCONTROLLER_IDX]); }
template<> inline PyTypeObject* SbkType< ::rviz::ToolManager >() { return reinterpret_cast<PyTypeObject*>(Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOLMANAGER_IDX]); }
template<> inline PyTypeObject* SbkType< ::rviz::Tool >() { return reinterpret_cast<PyTypeObject*>(Sbklibrviz_shibokenTypes[SBK_RVIZ_TOOL_IDX]); }
template<> inline PyTypeObject* SbkType< ::rviz::ViewManager >() { return reinterpret_cast<PyTypeObject*>(Sbklibrviz_shibokenTypes[SBK_RVIZ_VIEWMANAGER_IDX]); }

} // namespace Shiboken

#endif // SBK_LIBRVIZ_SHIBOKEN_PYTHON_H

