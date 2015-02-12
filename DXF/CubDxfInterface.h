#ifndef CUBDXFINTERFACE_H
#define CUBDXFINTERFACE_H

// QT
#include <QMap>
#include <QVector>

// STL
#include <cmath>

// LIBDXF
#include <drw_interface.h>
#include <drw_entities.h>

// CUBATOR
#include <GraphicsMap.h>

#define THOU 0.0254 // THOU -> TH

class CubDxfInterface : public DRW_Interface
{
public:
    CubDxfInterface(GraphicsMap * map = 0);

    void setMap(GraphicsMap * map);
    GraphicsMap * map();

    /** Called when header is parsed.  */
    void addHeader(const DRW_Header* data);

    /** Called for every line Type.  */
    void addLType(const DRW_LType& data);
    /** Called for every layer. */
    void addLayer(const DRW_Layer& data);
    /** Called for every dim style. */
    void addDimStyle(const DRW_Dimstyle& data);

    /**
     * Called for every block. Note: all entities added after this
     * command go into this block until endBlock() is called.
    *
     * @see endBlock()
     */
    void addBlock(const DRW_Block& data);

    /** Called to end the current block */
    void endBlock();

    /** Called for every point */
    void addPoint(const DRW_Point& data);

    /** Called for every line */
    void addLine(const DRW_Line& data);

    /** Called for every ray */
    void addRay(const DRW_Ray& data);

    /** Called for every xline */
    void addXline(const DRW_Xline& data);

    /** Called for every arc */
    void addArc(const DRW_Arc& data);

    /** Called for every circle */
    void addCircle(const DRW_Circle& data);

    /** Called for every ellipse */
    void addEllipse(const DRW_Ellipse& data);

    /** Called for every lwpolyline */
    void addLWPolyline(const DRW_LWPolyline& data);

    /** Called for every polyline start */
    void addPolyline(const DRW_Polyline& data);

    /** Called for every spline */
    void addSpline(const DRW_Spline* data);

        /** Called for every spline knot value */
    void addKnot(const DRW_Entity& data);

    /** Called for every insert. */
    void addInsert(const DRW_Insert& data);

    /** Called for every trace start */
    void addTrace(const DRW_Trace& data);

    /** Called for every 3dface start */
    void add3dFace(const DRW_3Dface& data);

    /** Called for every solid start */
    void addSolid(const DRW_Solid& data);


    /** Called for every Multi Text entity. */
    void addMText(const DRW_MText& data);

    /** Called for every Text entity. */
    void addText(const DRW_Text& data);

    /**
     * Called for every aligned dimension entity.
     */
    void addDimAlign(const DRW_DimAligned *data);
    /**
     * Called for every linear or rotated dimension entity.
     */
    void addDimLinear(const DRW_DimLinear *data);

        /**
     * Called for every radial dimension entity.
     */
    void addDimRadial(const DRW_DimRadial *data);

        /**
     * Called for every diametric dimension entity.
     */
    void addDimDiametric(const DRW_DimDiametric *data);

        /**
     * Called for every angular dimension (2 lines version) entity.
     */
    void addDimAngular(const DRW_DimAngular *data);

        /**
     * Called for every angular dimension (3 points version) entity.
     */
    void addDimAngular3P(const DRW_DimAngular3p *data);

    /**
     * Called for every ordinate dimension entity.
     */
    void addDimOrdinate(const DRW_DimOrdinate *data);

    /**
         * Called for every leader start.
         */
    void addLeader(const DRW_Leader *data);

        /**
         * Called for every hatch entity.
         */
    void addHatch(const DRW_Hatch *data);

        /**
         * Called for every image entity.
         */
    void addImage(const DRW_Image *data);

        /**
         * Called for every image definition.
         */
    void linkImage(const DRW_ImageDef *data);

    /**
     * Called for every comment in the DXF file (code 999).
     */
    void addComment(const char* comment);

    /** Sets the current attributes for entities. */
/*    void setExtrusion(double dx, double dy, double dz, double elevation) {
        extrusion->setDirection(dx, dy, dz);
                extrusion->setElevation(elevation);
    }*/

    /** @return the current attributes used for new entities. */
//    DL_Extrusion* getExtrusion() {
//        return extrusion;
//    }

    void writeHeader(DRW_Header& data);
    void writeBlocks();
    void writeBlockRecords();
    void writeEntities();
    void writeLTypes();
    void writeLayers();
    void writeDimstyles();

protected:
    GraphicsMap * _map;
    QPen _pen;
    QBrush _brush;
    QMap<QString, QPen> _hLayers;
    QMap<QString, QVector<qreal> > _hDashPattern;
};

#endif // CUBDXFINTERFACE_H
