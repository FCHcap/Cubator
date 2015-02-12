#ifndef CUBEXCEPTION_H
#define CUBEXCEPTION_H

// QT
#include <QMetaType>
#include <QString>
#include <QCoreApplication>

// STL
#include <iostream>
#include <exception>

// CUBATOR
#include <Messages.h>

class CubException
{
    Q_DECLARE_TR_FUNCTIONS(CubException)

public:
    CubException() throw();
    CubException(const char *brief, const char *error, const char *method) throw();
    CubException(const QString &brief, const QString &error, const QString &method) throw();
    CubException(const CubException &e);
    CubException & operator = (const CubException &exception);
    ~CubException() throw();

    QString brief() const throw();
    QString error() const throw();
    QString method() const throw();

    void setBrief(QString text) throw();
    void setError(QString text) throw();
    void setMethod(QString text) throw();

    QString what() const;


protected:
    QString _brief;
    QString _error;
    QString _method;
};

#endif // CUBEXCEPTION_H
