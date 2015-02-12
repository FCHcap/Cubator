#ifndef GEOEXCEPTION_H
#define GEOEXCEPTION_H

// QT
#include <QString>

class GeoException
{
public:
    GeoException(){}

    GeoException(QString error, QString method){
        _error = error;
        _method = method;
    }

    void setError(QString error){_error = error;}

    void setMethod(QString method){_method = method;}

    QString error(){return _error;}

    QString method(){return _method;}

    QString concatenate(){
        return QObject::tr("In method : ") + _method + "\n" + _error;
    }

protected:
    QString _error;
    QString _method;

};

#endif // GEOEXCEPTION_H
