#include "Delaunay.h"

// QT
#include <QThread>

Delaunay::Delaunay(QObject *parent) : DefaultProcess(parent){
    _vertices = 0;
}

void Delaunay::setVertices(DVertexList &vertices){
    _vertices = &vertices;
}

void Delaunay::run(){

    try{
        if(!_vertices){
            throw CubException(BRIEF00, ERROR08, "Delaunay::start");
        }

        emit processNameUpdated(PROCESS08);
        emit levelUpdated(0);

        DVertexList & vertices = (DVertexList &) *_vertices;
        DTriangleList & triangles = (DTriangleList&) *vertices.triangles();

        QMutexLocker tlocker(vertices.mutex());

        //those will be used quite everywhere so I am storing them here not to declare them x times.
        int i = 0;
        int j = 0;
        int nv = vertices.size();

        if(nv < 3) return;

        int trimax = nv * 4;

        // Find the maximum and minimum vertex bounds.
        // This is to allow calculation of the bounding supertriangle.
        double xmin = vertices.at(0).x();
        double ymin = vertices.at(0).y();
        double xmax = xmin;
        double ymax = ymin;

        for(i=0 ; i<nv ; i++){
            if(vertices.at(i).x() < xmin) xmin = vertices.at(i).x();
            if(vertices.at(i).x() > xmax) xmax = vertices.at(i).x();
            if(vertices.at(i).y() < ymin) ymin = vertices.at(i).y();
            if(vertices.at(i).y() > ymax) ymax = vertices.at(i).y();
        }

        double dx = xmax - xmin;
        double dy = ymax - ymin;
        double dmax = (dx > dy) ? dx : dy;
        double xmid = (xmax + xmin) * 0.5;
        double ymid = (ymax + ymin) * 0.5;

        // Set up the supertriangle
        // This is a triangle which encompasses all the sample points.
        // The supertirangle coordinates are added to the end of the vertex list.
        // The supertriangle is the first triangle in the triangle list.

        vertices.append(DVertex(xmid - 2 * dmax, ymid - dmax, 0));
        vertices.append(DVertex(xmid, ymid + 2 * dmax, 0));
        vertices.append(DVertex(xmid + 2 * dmax, ymid - dmax, 0));

        triangles.clear();
        triangles.append(DTriangle(nv, nv+1, nv+2)); // SuperTriangle placed at index 0

        for(i=0 ; i<nv ; i++){

            DEdges edges; //[trimax * 3];

            // Set up the edge buffer.
            // If the point (Vertex(i).x, Vertex(i).y) lies inside the circumcircle then the
            // three edges of that triangle are added to the edge buffer and the triangle is removed from list.
            for(j = 0; j < triangles.length(); j++){

                //if(inCircle(triangles[j], vertices.at(i))){
                if(vertices.inCircle(triangles[j], vertices.at(i).toPointF())){
                    edges.append(DEdge(triangles[j].v1(), triangles[j].v2()));
                    edges.append(DEdge(triangles[j].v2(), triangles[j].v3()));
                    edges.append(DEdge(triangles[j].v3(), triangles[j].v1()));
                    triangles.removeAt(j);
                    j--;

                }
            }

            if(i >= nv) continue; // In case we the last duplicate point we removed was the last in the array.

            // Remove duplicate edges
            // Note : if all triangles are specified anticlockwise the all interior edges are opposite pointing in direction.
            for(j = edges.size() -2 ; j >= 0 ; j--){
                for(int k = edges.size()-1 ; k >= j+1 ; k--){
                    if(edges[j].equals(edges[k])){
                        edges.removeAt(k);
                        edges.removeAt(j);
                        k--;
                        continue;
                    }
                }
            }

            // Form new triangles for the current point
            // Skipping over any tagged edges.
            // All edges are arranged in clockwise order.
            for(j = 0; j< edges.length(); j++){

                if(triangles.length() > trimax){
                    throw CubException(BRIEF00, ERROR03, "Delaunay::triangulate");
                }
                DTriangle t(edges[j].v1(), edges[j].v2(), i);
                vertices.updateCircumCenter(t);
                triangles.append(t);
            }

            edges.clear();

            int level = i*100/vertices.size();
            tlocker.unlock();
            emit levelUpdated(level);
            tlocker.relock();
        }

        // Remove triangles with supertriangle vertices
        // These are triangles which have a vertex number greater than nv
        for(i = triangles.size()-1 ; i >= 0 ; i--){

            if(triangles[i].v1() >= nv || triangles[i].v2() >= nv || triangles[i].v3() >= nv){
                triangles.removeAt(i);
            }
        }

        // Remove SuperTriangle vertices
        vertices.removeLast();
        vertices.removeLast();
        vertices.removeLast();
    }
    catch(const CubException &e){
        emit exceptionLaunched(e);
    }
}

/** <summary>
  * Return true if the point (p) lies inside the circumcircle made up by points (p1, p2, p3)
  * </summary>

  NOTE : A point on the edge is inside the circumcircle
  */

bool Delaunay::inCircle(const DTriangle &t, const DVertex &v) const{

    DVertexList & vertices = *_vertices;

    const DVertex &v1 = vertices.at(t.v1());
    const DVertex &v2 = vertices.at(t.v2());
    const DVertex &v3 = vertices.at(t.v3());

    double epsilon = DBL_MIN;

    if(fabs(v1.y() - v2.y()) < epsilon && fabs(v2.y() - v3.y()) < epsilon){
        //Points are coincident !!
        return false;
    }

    double m1 = 0;
    double m2 = 0;

    double mx1 = 0;
    double mx2 = 0;

    double my1 = 0;
    double my2 = 0;

    double xc = 0;
    double yc = 0;

    if(fabs(v2.y() - v1.y()) < epsilon){
        m2 = -(v3.x() - v2.x()) / (v3.y() - v2.y());
        mx2 = (v2.x() + v3.x()) * 0.5;
        my2 = (v2.y() + v3.y()) * 0.5;

        // Calculate CircumCircle center (xc, yc)
        xc = (v2.x() + v1.x()) * 0.5;
        yc = m2 * (xc - mx2) + my2;
    }
    else if(fabs(v3.y() - v2.y()) < epsilon){
        m1 = -(v2.x() - v1.x()) / (v2.y() - v1.y());
        mx1 = (v1.x() + v2.x()) * 0.5;
        my1 = (v1.y() + v2.y()) * 0.5;

        // Calculate CircumCircle center (xc, yc)
        xc = (v3.x() + v2.x()) * 0.5;
        yc = m1 * (xc - mx1) + my1;
    }
    else{
        m1 = -(v2.x() - v1.x()) / (v2.y() - v1.y());
        m2 = -(v3.x() - v2.x()) / (v3.y() - v2.y());
        mx1 = (v1.x() + v2.x()) * 0.5;
        mx2 = (v2.x() + v3.x()) * 0.5;
        my1 = (v1.y() + v2.y()) * 0.5;
        my2 = (v2.y() + v3.y()) * 0.5;

        // Calculate CircumCircle center (xc, yc)
        xc = (m1 * mx1 - m2 * mx2 + my2 - my1) / (m1 - m2);
        yc = m1 * (xc - mx1) + my1;
    }

    double dx = v2.x() - xc;
    double dy = v2.y() - yc;
    double rsqr = dx * dx + dy * dy;

    dx = v.x() - xc;
    dy = v.y() - yc;
    double drsqr = dx * dx + dy * dy;

    return (drsqr <= rsqr);
}
