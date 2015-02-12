#-------------------------------------------------
#
# Project created by QtCreator 2015-02-05T07:47:36
#
#-------------------------------------------------

QT       += core gui sql xml serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Cubator
TEMPLATE = app

INCLUDEPATH += \
    IHM \
    IHM/Process \
    DEVICES \
    DEVICES/qserialdevice \
    SETTINGS \
    GEO \
    GEO/Geo \
    DATA/Data \
    DATA/Process \
    PML \
    DXF \
    XYZFILES \
    TRIANGULATION \
    MESH \
    VOLUME \
    DELAUNAY

SOURCES += main.cpp \
    IHM/MainWindow.cpp \
    IHM/GraphicsView.cpp \
    IHM/GraphicsScene.cpp \
    IHM/DbTableEditDialog.cpp \
    IHM/SettingsDialog.cpp \
    IHM/MeshDialog.cpp \
    IHM/PmlConverterDialog.cpp \
    IHM/GraphicsBoatItem.cpp \
    IHM/GraphicsIconItem.cpp \
    IHM/GraphicsAutoDepthItem.cpp \
    IHM/GpsWidget.cpp \
    IHM/SounderWidget.cpp \
    IHM/AutoDephWidget.cpp \
    IHM/MeshGraphicsView.cpp \
    DEVICES/Gps.cpp \
    PML/PmlWriter.cpp \
    SETTINGS/Settings.cpp \
    GEO/Geo/GeoData.cpp \
    GEO/Geo/GeoConvers.cpp \
    IHM/GraphicsPolylineItem.cpp \
    IHM/GraphicsHatchItem.cpp \
    IHM/SelectItemDialog.cpp \
    IHM/GraphicsItemList.cpp \
    IHM/GraphicsTextItem.cpp \
    IHM/GraphicsTextDialog.cpp \
    IHM/PmlSaveDialog.cpp \
    IHM/CheckItemsDialog.cpp \
    IHM/FileXyzReaderDialog.cpp \
    XYZFILES/XyzFileReader.cpp \
    IHM/DbCreateTableDialog.cpp \
    DELAUNAY/Delaunay.cpp \
    DELAUNAY/DEdge.cpp \
    CubException.cpp \
    IHM/ErrorDialog.cpp \
    DATA/Data/DataWriter.cpp \
    DATA/Data/DataReader.cpp \
    DATA/Data/Data.cpp \
    IHM/ProgressDialog.cpp \
    IHM/GraphicsVectorsItem.cpp \
    DELAUNAY/DVertexList.cpp \
    DELAUNAY/DTriangleList.cpp \
    IHM/MeshGraphicsView3D.cpp \
    DefaultProcess.cpp \
    IHM/DbShowTableDialog.cpp \
    MapManager.cpp \
    IHM/ConvertMapFileDialog.cpp \
    IHM/InfoMap.cpp \
    IHM/GraphicsMap.cpp \
    DXF/libdxfrw.cpp \
    DXF/dxfwriter.cpp \
    DXF/dxfreader.cpp \
    DXF/drw_textcodec.cpp \
    DXF/drw_objects.cpp \
    DXF/drw_entities.cpp \
    IHM/GraphicsImageItem.cpp \
    PML/PmlReader.cpp \
    IHM/GraphicsMeshImageItem.cpp \
    IHM/CreateIconDialog.cpp \
    IHM/CoordinatesDialog.cpp \
    GEO/CubGeo.cpp \
    IHM/DateDialog.cpp \
    IHM/GraphicsMapLayer.cpp \
    IHM/GraphicsMapIconDef.cpp \
    IHM/GraphicsMapEventManager.cpp \
    IHM/InputIntToStringDialog.cpp \
    DEVICES/DeviceProcess.cpp \
    IHM/GraphicsMapBoatDef.cpp \
    IHM/GraphicsMapItemDef.cpp \
    BoatManager.cpp \
    IHM/GraphicsMeasureItem.cpp \
    IHM/VolumeCalculatorDialog.cpp \
    IHM/GraphicsVolumeItem.cpp \
    VOLUME/VolumeCalculatorProcess.cpp \
    IHM/DbTableWidget.cpp \
    IHM/ConvertToNgfDialog.cpp \
    DELAUNAY/DTGrid.cpp \
    DATA/Data/VerticesReader.cpp \
    DATA/Data/TrianglesReader.cpp \
    DATA/Data/GridReader.cpp \
    IHM/GraphicsItem.cpp \
    DATA/Process/VerticesReaderProcess.cpp \
    DATA/Process/TrianglesReaderProcess.cpp \
    DATA/Process/GridWriterProcess.cpp \
    DATA/Process/GridReaderProcess.cpp \
    DATA/Process/DataWriterProcess.cpp \
    DATA/Process/ConvertToNgfProcess.cpp \
    IHM/Process/VerticesLoadingProcess.cpp \
    IHM/Process/TrianglesItemLoadingProcess.cpp \
    DATA/Process/GridCalculatorProcess.cpp \
    DXF/CubDxfReader.cpp \
    DXF/CubDxfInterface.cpp \
    SplashScreen.cpp \
    IHM/GraphicsPointXYItem.cpp \
    IHM/GraphicsAnchorItem.cpp \
    IHM/GraphicsAnchorsItem.cpp \
    IHM/GraphicsPictureItem.cpp \
    IHM/GraphicsRAnchorItem.cpp

HEADERS  += \
    IHM/MainWindow.h \
    IHM/GraphicsView.h \
    IHM/GraphicsScene.h \
    IHM/DbTableEditDialog.h \
    IHM/SettingsDialog.h \
    IHM/MeshDialog.h \
    IHM/PmlConverterDialog.h \
    IHM/GraphicsBoatItem.h \
    IHM/GraphicsIconItem.h \
    IHM/GraphicsAutoDepthItem.h \
    IHM/GpsWidget.h \
    IHM/SounderWidget.h \
    IHM/AutoDephWidget.h \
    IHM/MeshGraphicsView.h \
    DEVICES/Gps.h \
    PML/PmlWriter.h \
    SETTINGS/Settings.h \
    GEO/Geo/GeoVecteur.h \
    GEO/Geo/GeoType.h \
    GEO/Geo/GeoProjection.h \
    GEO/Geo/GeoException.h \
    GEO/Geo/GeoEllipsoid.h \
    GEO/Geo/GeoDatum.h \
    GEO/Geo/GeoData.h \
    GEO/Geo/GeoConvers.h \
    GEO/Geo/GeoConstLambert.h \
    PML/PmlElements.h \
    PML/BasicsElements.h \
    IHM/GraphicsPolylineItem.h \
    IHM/GraphicsHatchItem.h \
    IHM/SelectItemDialog.h \
    IHM/GraphicsItemList.h \
    IHM/GraphicsTextItem.h \
    IHM/GraphicsTextDialog.h \
    IHM/PmlSaveDialog.h \
    IHM/CheckItemsDialog.h \
    IHM/FileXyzReaderDialog.h \
    XYZFILES/XyzFileReader.h \
    IHM/DbCreateTableDialog.h \
    DELAUNAY/Delaunay.h \
    DELAUNAY/DEdge.h \
    CubException.h \
    IHM/ErrorDialog.h \
    DATA/Data/DataReader.h \
    DATA/Data/DataWriter.h \
    DATA/Data/Data.h \
    IHM/ProgressDialog.h \
    IHM/GraphicsVectorsItem.h \
    DELAUNAY/DVertexList.h \
    DELAUNAY/DTypes.h \
    DELAUNAY/DTriangleList.h \
    IHM/MeshGraphicsView3D.h \
    DefaultProcess.h \
    IHM/DbShowTableDialog.h \
    MapManager.h \
    IHM/ConvertMapFileDialog.h \
    IHM/InfoMap.h \
    IHM/GraphicsMap.h \
    DXF/libdxfrw.h \
    DXF/dxfwriter.h \
    DXF/dxfreader.h \
    DXF/drw_textcodec.h \
    DXF/drw_objects.h \
    DXF/drw_interface.h \
    DXF/drw_entities.h \
    DXF/drw_cptables.h \
    DXF/drw_cptable950.h \
    DXF/drw_cptable949.h \
    DXF/drw_cptable936.h \
    DXF/drw_cptable932.h \
    DXF/drw_base.h \
    IHM/GraphicsTypes.h \
    IHM/GraphicsImageItem.h \
    PML/PmlReader.h \
    IHM/GraphicsMeshImageItem.h \
    IHM/CreateIconDialog.h \
    IHM/CoordinatesDialog.h \
    GEO/CubGeo.h \
    IHM/DateDialog.h \
    IHM/GraphicsMapLayer.h \
    IHM/GraphicsMapIconDef.h \
    IHM/GraphicsMapEventManager.h \
    IHM/InputIntToStringDialog.h \
    DEVICES/DeviceProcess.h \
    IHM/GraphicsMapBoatDef.h \
    IHM/GraphicsMapItemDef.h \
    BoatManager.h \
    IHM/Map.h \
    IHM/GraphicsMeasureItem.h \
    IHM/VolumeCalculatorDialog.h \
    IHM/GraphicsVolumeItem.h \
    VOLUME/VolumeCalculatorProcess.h \
    IHM/DbTableWidget.h \
    IHM/ConvertToNgfDialog.h \
    Messages.h \
    Tools.h \
    DELAUNAY/DTGrid.h \
    DATA/Data/VerticesReader.h \
    DATA/Data/TrianglesReader.h \
    DATA/Data/GridReader.h \
    IHM/GraphicsItem.h \
    DATA/Process/VerticesReaderProcess.h \
    DATA/Process/TrianglesReaderProcess.h \
    DATA/Process/GridWriterProcess.h \
    DATA/Process/GridReaderProcess.h \
    DATA/Process/DataWriterProcess.h \
    DATA/Process/ConvertToNgfProcess.h \
    IHM/Process/VerticesLoadingProcess.h \
    IHM/Process/TrianglesItemLoadingProcess.h \
    DATA/Process/GridCalculatorProcess.h \
    DXF/CubDxfReader.h \
    DXF/CubDxfInterface.h \
    GEO/Geo/GeoMessages.h \
    SplashScreen.h \
    Defines.h \
    IHM/GraphicsPointXYItem.h \
    IHM/GraphicsAnchorItem.h \
    IHM/GraphicsAnchorsItem.h \
    IHM/GraphicsPictureItem.h \
    IHM/GraphicsRAnchorItem.h

FORMS    += \
    IHM/MainWindow.ui \
    IHM/SettingsDialog.ui \
    IHM/SelectItemDialog.ui \
    IHM/PmlSaveDialog.ui \
    IHM/CheckItemsDialog.ui \
    IHM/FileXyzReaderDialog.ui \
    IHM/DbTableEditDialog.ui \
    IHM/DbCreateTableDialog.ui \
    IHM/MeshDialog.ui \
    IHM/ErrorDialog.ui \
    IHM/ProgressDialog.ui \
    IHM/DbShowTableDialog.ui \
    IHM/ConvertMapFileDialog.ui \
    IHM/CreateIconDialog.ui \
    IHM/CoordinatesDialog.ui \
    IHM/DateDialog.ui \
    IHM/InputIntToStringDialog.ui \
    IHM/VolumeCalculatorDialog.ui \
    IHM/ConvertToNgfDialog.ui

RESOURCES += \
    IHM/Cubator.qrc

DISTFILES += \
    .gitignore
