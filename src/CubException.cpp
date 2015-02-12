#include "CubException.h"

CubException::CubException() throw(){
    _brief = BRIEF00;
    _error = ERROR00;
}

CubException::CubException(const QString &brief, const QString &error, const QString &method) throw(): _brief(brief), _error(error), _method(method) {
}

CubException::CubException(const char *brief, const char *error, const char *method) throw() : _brief(brief), _error(error), _method(method){
}

CubException::CubException(const CubException &e){
    _brief = e._brief;
    _error = e._error;
    _method = e._method;
}

CubException & CubException::operator = (const CubException &e){
    _brief = e._brief;
    _error = e._error;
    _method = e._method;

    return *this;
}

CubException::~CubException() throw() {

}

QString CubException::brief() const throw(){
    return _brief;
}

QString CubException::error() const throw(){
    return _error;
}

QString CubException::method() const throw(){
    return _method;
}

void CubException::setBrief(QString text) throw(){
    _brief = text;
}

void CubException::setError(QString text) throw(){
    _error = text;
}

void CubException::setMethod(QString text) throw(){
    _method = text;
}

QString CubException::what() const{
    return _brief + '\n' + _error + '\n' + TEXT15 + _method;
}
