#ifndef PMLELEMENTS_H
#define PMLELEMENTS_H

#include <Qt>
#include <QtGui>

#include <BasicsElements.h>

typedef QString PmlFormat;
typedef QRectF PmlBounds;
typedef QPointF PmlCenter;
typedef QPointF PmlPoint;
typedef QPolygonF PmlPolygon;
typedef QString PmlName;
typedef QColor PmlSelection;
typedef QColor PmlOverview;

struct PmlLayer{
    QString name;
    qreal elevation;
};

struct PmlLine{
    QPointF p1;
    QPointF p2;
    QColor color;
    QString style;
    int weight;
};

class PmlBasicsProperties{
public:
    PmlBasicsProperties(){ _elevation = 0; _lineWidth = 0;}

    PmlBasicsProperties(const PmlBasicsProperties &properties){
        _lineType = properties._lineType;
        _color = properties._color;
        _elevation = properties._elevation;
        _lineWidth = properties._lineWidth;
    }

    PmlBasicsProperties & operator = (PmlBasicsProperties &properties){
        _lineType = properties._lineType;
        _color = properties._color;
        _elevation = properties._elevation;
        _lineWidth = properties._lineWidth;

        return *this;
    }

    void setLineType(QString lineType){
        _lineType = lineType;
    }
    void setColor(QColor color){
        _color = color;
    }

    void setElevation(qreal elevation){
        _elevation = elevation;
    }

    void setLineWidth(int lineWidth){
        _lineWidth = lineWidth;
    }

    QString lineType(){
        return _lineType;
    }

    QColor color(){
        return _color;
    }

    qreal elevation(){
        return _elevation;
    }

    int lineWidth(){
        return _lineWidth;
    }

protected:
    QString _lineType;
    QColor _color;
    qreal _elevation;
    int _lineWidth;
};

class PmlEllipse : public PmlBasicsProperties{

public:

    PmlEllipse(){}

    PmlEllipse(const PmlEllipse &ellipse) : PmlBasicsProperties(ellipse){
        _position = ellipse._position;
        _size = ellipse._size;
    }

    PmlEllipse & operator = (PmlEllipse& ellipse){

        PmlBasicsProperties *bp1, *bp2;
        bp1 = this;
        bp2 = &ellipse;
        *bp1 = *bp2;

        _position = ellipse._position;
        _size = ellipse._size;

        return *this;
    }

    void setPosition(QPointF position){_position = position;}
    void setX(qreal x){_position.setX(x);}
    void setY(qreal y){_position.setY(y);}
    void setSize(QSizeF size){_size = size;}

    QPointF position(){return _position;}
    QSizeF size(){return _size;}

protected:
    QPointF _position;
    QSizeF _size;
};

class PmlHatch : public PmlBasicsProperties{

public:

    PmlHatch(){}

    PmlHatch(const PmlHatch& hatch) : PmlBasicsProperties(hatch){
        foreach(PmlPolygon polygon, hatch._polygons){
            _polygons.append(polygon);
        }
    }

    PmlHatch & operator = (PmlHatch& hatch){
        foreach(PmlPolygon polygon, hatch._polygons){
            _polygons.append(polygon);
        }

        PmlBasicsProperties *pp1, *pp2;
        pp1 = this;
        pp2 = &hatch;
        *pp1 = *pp2;

        return *this;
    }

    void addPolygon(PmlPolygon polygon){
        _polygons.append(polygon);
    }

    void clearPolygons(){
        _polygons.clear();
    }

    bool isPolygonsEmpty(){
        if(_polygons.isEmpty()) return 1;
        return 0;
    }

    QList<PmlPolygon> polygons(){
        return _polygons;
    }

protected:
    QList<PmlPolygon> _polygons;
};

class PmlPolyline : public QPolygonF, public PmlBasicsProperties{

public:

    PmlPolyline(){_closed = 0;}

    PmlPolyline(const PmlPolyline &polyline) : QPolygonF(polyline), PmlBasicsProperties(polyline){_closed = polyline._closed;}

    PmlPolyline & operator = (PmlPolyline &polyline){

        _closed = polyline._closed;

        QPolygonF *pf1, *pf2;
        pf1 = this;
        pf2 = &polyline;
        *pf1 = *pf2;

        PmlBasicsProperties *bp1, *bp2;
        bp1 = this;
        bp2 = &polyline;
        *bp1 = *bp2;

        return *this;
    }

    void setClosed(bool closed){
        _closed = closed;
    }

    bool isClosed(){
        return _closed;
    }

protected:
    bool _closed;
};

class PmlIcon{};

class PmlText{

public:
    PmlText(){_rotation = 0; _elevation = 0;}

    PmlText(const PmlText &text){
        _text = text._text;
        _position = text._position;
        _rotation = text._rotation;
        _font = text._font;
        _color = text._color;
        _elevation = text._elevation;
    }

    PmlText & operator = (PmlText& text){
        _text = text._text;
        _position = text._position;
        _rotation = text._rotation;
        _font = text._font;
        _color = text._color;
        _elevation = text._elevation;

        return *this;
    }

    void setText(QString text){_text = text;}
    void setPosition(QPointF position){_position = position;}
    void setRotation(qreal rotation){_rotation = rotation;}
    void setFont(QFont font){_font = font;}
    void setColor(QColor color){_color = color;}
    void setElevation(qreal elevation){_elevation = elevation;}

    QString text(){return _text;}
    QPointF position(){return _position;}
    qreal rotation(){return _rotation;}
    QFont font(){return _font;}
    QColor color(){return _color;}
    qreal elevation(){return _elevation;}

protected:
    QString _text;
    int _rotation;
    QFont _font;
    QColor _color;
    qreal _elevation;
    QPointF _position;
};

#endif // PMLELEMENTS_H
