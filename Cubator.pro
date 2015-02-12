#-------------------------------------------------
#
# Project created by QtCreator 2015-02-05T07:47:36
#
#-------------------------------------------------

QT       += core gui sql xml serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Cubator
TEMPLATE = app

INCLUDEPATH += src\
    src/IHM \
    src/IHM/Process \
    src/DEVICES \
    src/DEVICES/qserialdevice \
    src/SETTINGS \
    src/GEO \
    src/GEO/Geo \
    src/DATA/Data \
    src/DATA/Process \
    src/PML \
    src/DXF \
    src/XYZFILES \
    src/TRIANGULATION \
    src/MESH \
    src/VOLUME \
    src/DELAUNAY

SOURCES += src/main.cpp \
    src/IHM/MainWindow.cpp \
    src/IHM/GraphicsView.cpp \
    src/IHM/GraphicsScene.cpp \
    src/IHM/DbTableEditDialog.cpp \
    src/IHM/SettingsDialog.cpp \
    src/IHM/MeshDialog.cpp \
    src/IHM/PmlConverterDialog.cpp \
    src/IHM/GraphicsBoatItem.cpp \
    src/IHM/GraphicsIconItem.cpp \
    src/IHM/GraphicsAutoDepthItem.cpp \
    src/IHM/GpsWidget.cpp \
    src/IHM/SounderWidget.cpp \
    src/IHM/AutoDephWidget.cpp \
    src/IHM/MeshGraphicsView.cpp \
    src/DEVICES/Gps.cpp \
    src/PML/PmlWriter.cpp \
    src/SETTINGS/Settings.cpp \
    src/GEO/Geo/GeoData.cpp \
    src/GEO/Geo/GeoConvers.cpp \
    src/IHM/GraphicsPolylineItem.cpp \
    src/IHM/GraphicsHatchItem.cpp \
    src/IHM/SelectItemDialog.cpp \
    src/IHM/GraphicsItemList.cpp \
    src/IHM/GraphicsTextItem.cpp \
    src/IHM/GraphicsTextDialog.cpp \
    src/IHM/PmlSaveDialog.cpp \
    src/IHM/CheckItemsDialog.cpp \
    src/IHM/FileXyzReaderDialog.cpp \
    src/XYZFILES/XyzFileReader.cpp \
    src/IHM/DbCreateTableDialog.cpp \
    src/DELAUNAY/Delaunay.cpp \
    src/DELAUNAY/DEdge.cpp \
    src/CubException.cpp \
    src/IHM/ErrorDialog.cpp \
    src/DATA/Data/DataWriter.cpp \
    src/DATA/Data/DataReader.cpp \
    src/DATA/Data/Data.cpp \
    src/IHM/ProgressDialog.cpp \
    src/IHM/GraphicsVectorsItem.cpp \
    src/DELAUNAY/DVertexList.cpp \
    src/DELAUNAY/DTriangleList.cpp \
    src/IHM/MeshGraphicsView3D.cpp \
    src/DefaultProcess.cpp \
    src/IHM/DbShowTableDialog.cpp \
    src/MapManager.cpp \
    src/IHM/ConvertMapFileDialog.cpp \
    src/IHM/InfoMap.cpp \
    src/IHM/GraphicsMap.cpp \
    src/DXF/libdxfrw.cpp \
    src/DXF/dxfwriter.cpp \
    src/DXF/dxfreader.cpp \
    src/DXF/drw_textcodec.cpp \
    src/DXF/drw_objects.cpp \
    src/DXF/drw_entities.cpp \
    src/IHM/GraphicsImageItem.cpp \
    src/PML/PmlReader.cpp \
    src/IHM/GraphicsMeshImageItem.cpp \
    src/IHM/CreateIconDialog.cpp \
    src/IHM/CoordinatesDialog.cpp \
    src/GEO/CubGeo.cpp \
    src/IHM/DateDialog.cpp \
    src/IHM/GraphicsMapLayer.cpp \
    src/IHM/GraphicsMapIconDef.cpp \
    src/IHM/GraphicsMapEventManager.cpp \
    src/IHM/InputIntToStringDialog.cpp \
    src/DEVICES/DeviceProcess.cpp \
    src/IHM/GraphicsMapBoatDef.cpp \
    src/IHM/GraphicsMapItemDef.cpp \
    src/BoatManager.cpp \
    src/IHM/GraphicsMeasureItem.cpp \
    src/IHM/VolumeCalculatorDialog.cpp \
    src/IHM/GraphicsVolumeItem.cpp \
    src/VOLUME/VolumeCalculatorProcess.cpp \
    src/IHM/DbTableWidget.cpp \
    src/IHM/ConvertToNgfDialog.cpp \
    src/DELAUNAY/DTGrid.cpp \
    src/DATA/Data/VerticesReader.cpp \
    src/DATA/Data/TrianglesReader.cpp \
    src/DATA/Data/GridReader.cpp \
    src/IHM/GraphicsItem.cpp \
    src/DATA/Process/VerticesReaderProcess.cpp \
    src/DATA/Process/TrianglesReaderProcess.cpp \
    src/DATA/Process/GridWriterProcess.cpp \
    src/DATA/Process/GridReaderProcess.cpp \
    src/DATA/Process/DataWriterProcess.cpp \
    src/DATA/Process/ConvertToNgfProcess.cpp \
    src/IHM/Process/VerticesLoadingProcess.cpp \
    src/IHM/Process/TrianglesItemLoadingProcess.cpp \
    src/DATA/Process/GridCalculatorProcess.cpp \
    src/DXF/CubDxfReader.cpp \
    src/DXF/CubDxfInterface.cpp \
    src/SplashScreen.cpp \
    src/IHM/GraphicsPointXYItem.cpp \
    src/IHM/GraphicsAnchorItem.cpp \
    src/IHM/GraphicsAnchorsItem.cpp \
    src/IHM/GraphicsPictureItem.cpp \
    src/IHM/GraphicsRAnchorItem.cpp

HEADERS  += \
    src/IHM/MainWindow.h \
    src/IHM/GraphicsView.h \
    src/IHM/GraphicsScene.h \
    src/IHM/DbTableEditDialog.h \
    src/IHM/SettingsDialog.h \
    src/IHM/MeshDialog.h \
    src/IHM/PmlConverterDialog.h \
    src/IHM/GraphicsBoatItem.h \
    src/IHM/GraphicsIconItem.h \
    src/IHM/GraphicsAutoDepthItem.h \
    src/IHM/GpsWidget.h \
    src/IHM/SounderWidget.h \
    src/IHM/AutoDephWidget.h \
    src/IHM/MeshGraphicsView.h \
    src/DEVICES/Gps.h \
    src/PML/PmlWriter.h \
    src/SETTINGS/Settings.h \
    src/GEO/Geo/GeoVecteur.h \
    src/GEO/Geo/GeoType.h \
    src/GEO/Geo/GeoProjection.h \
    src/GEO/Geo/GeoException.h \
    src/GEO/Geo/GeoEllipsoid.h \
    src/GEO/Geo/GeoDatum.h \
    src/GEO/Geo/GeoData.h \
    src/GEO/Geo/GeoConvers.h \
    src/GEO/Geo/GeoConstLambert.h \
    src/PML/PmlElements.h \
    src/PML/BasicsElements.h \
    src/IHM/GraphicsPolylineItem.h \
    src/IHM/GraphicsHatchItem.h \
    src/IHM/SelectItemDialog.h \
    src/IHM/GraphicsItemList.h \
    src/IHM/GraphicsTextItem.h \
    src/IHM/GraphicsTextDialog.h \
    src/IHM/PmlSaveDialog.h \
    src/IHM/CheckItemsDialog.h \
    src/IHM/FileXyzReaderDialog.h \
    src/XYZFILES/XyzFileReader.h \
    src/IHM/DbCreateTableDialog.h \
    src/DELAUNAY/Delaunay.h \
    src/DELAUNAY/DEdge.h \
    src/CubException.h \
    src/IHM/ErrorDialog.h \
    src/DATA/Data/DataReader.h \
    src/DATA/Data/DataWriter.h \
    src/DATA/Data/Data.h \
    src/IHM/ProgressDialog.h \
    src/IHM/GraphicsVectorsItem.h \
    src/DELAUNAY/DVertexList.h \
    src/DELAUNAY/DTypes.h \
    src/DELAUNAY/DTriangleList.h \
    src/IHM/MeshGraphicsView3D.h \
    src/DefaultProcess.h \
    src/IHM/DbShowTableDialog.h \
    src/MapManager.h \
    src/IHM/ConvertMapFileDialog.h \
    src/IHM/InfoMap.h \
    src/IHM/GraphicsMap.h \
    src/DXF/libdxfrw.h \
    src/DXF/dxfwriter.h \
    src/DXF/dxfreader.h \
    src/DXF/drw_textcodec.h \
    src/DXF/drw_objects.h \
    src/DXF/drw_interface.h \
    src/DXF/drw_entities.h \
    src/DXF/drw_cptables.h \
    src/DXF/drw_cptable950.h \
    src/DXF/drw_cptable949.h \
    src/DXF/drw_cptable936.h \
    src/DXF/drw_cptable932.h \
    src/DXF/drw_base.h \
    src/IHM/GraphicsTypes.h \
    src/IHM/GraphicsImageItem.h \
    src/PML/PmlReader.h \
    src/IHM/GraphicsMeshImageItem.h \
    src/IHM/CreateIconDialog.h \
    src/IHM/CoordinatesDialog.h \
    src/GEO/CubGeo.h \
    src/IHM/DateDialog.h \
    src/IHM/GraphicsMapLayer.h \
    src/IHM/GraphicsMapIconDef.h \
    src/IHM/GraphicsMapEventManager.h \
    src/IHM/InputIntToStringDialog.h \
    src/DEVICES/DeviceProcess.h \
    src/IHM/GraphicsMapBoatDef.h \
    src/IHM/GraphicsMapItemDef.h \
    src/BoatManager.h \
    src/IHM/Map.h \
    src/IHM/GraphicsMeasureItem.h \
    src/IHM/VolumeCalculatorDialog.h \
    src/IHM/GraphicsVolumeItem.h \
    src/VOLUME/VolumeCalculatorProcess.h \
    src/IHM/DbTableWidget.h \
    src/IHM/ConvertToNgfDialog.h \
    src/Messages.h \
    src/Tools.h \
    src/DELAUNAY/DTGrid.h \
    src/DATA/Data/VerticesReader.h \
    src/DATA/Data/TrianglesReader.h \
    src/DATA/Data/GridReader.h \
    src/IHM/GraphicsItem.h \
    src/DATA/Process/VerticesReaderProcess.h \
    src/DATA/Process/TrianglesReaderProcess.h \
    src/DATA/Process/GridWriterProcess.h \
    src/DATA/Process/GridReaderProcess.h \
    src/DATA/Process/DataWriterProcess.h \
    src/DATA/Process/ConvertToNgfProcess.h \
    src/IHM/Process/VerticesLoadingProcess.h \
    src/IHM/Process/TrianglesItemLoadingProcess.h \
    src/DATA/Process/GridCalculatorProcess.h \
    src/DXF/CubDxfReader.h \
    src/DXF/CubDxfInterface.h \
    src/GEO/Geo/GeoMessages.h \
    src/SplashScreen.h \
    src/Defines.h \
    src/IHM/GraphicsPointXYItem.h \
    src/IHM/GraphicsAnchorItem.h \
    src/IHM/GraphicsAnchorsItem.h \
    src/IHM/GraphicsPictureItem.h \
    src/IHM/GraphicsRAnchorItem.h

FORMS    += \
    src/IHM/ui/MainWindow.ui \
    src/IHM/ui/SettingsDialog.ui \
    src/IHM/ui/SelectItemDialog.ui \
    src/IHM/ui/PmlSaveDialog.ui \
    src/IHM/ui/CheckItemsDialog.ui \
    src/IHM/ui/FileXyzReaderDialog.ui \
    src/IHM/ui/DbTableEditDialog.ui \
    src/IHM/ui/DbCreateTableDialog.ui \
    src/IHM/ui/MeshDialog.ui \
    src/IHM/ui/ErrorDialog.ui \
    src/IHM/ui/ProgressDialog.ui \
    src/IHM/ui/DbShowTableDialog.ui \
    src/IHM/ui/ConvertMapFileDialog.ui \
    src/IHM/ui/CreateIconDialog.ui \
    src/IHM/ui/CoordinatesDialog.ui \
    src/IHM/ui/DateDialog.ui \
    src/IHM/ui/InputIntToStringDialog.ui \
    src/IHM/ui/VolumeCalculatorDialog.ui \
    src/IHM/ui/ConvertToNgfDialog.ui

RESOURCES = resources/Cubator.qrc

TRANSLATIONS = cubator_fr.ts
