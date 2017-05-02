#include "DefaultProcess.h"

DefaultProcess::DefaultProcess(QObject *parent) : QThread(parent){
    _lastException = 0;

    connect(this, SIGNAL(exceptionLaunched(CubException)), this, SLOT(saveException(CubException)));
}

DefaultProcess::~DefaultProcess(){
    if(_lastException) delete _lastException;
}

void DefaultProcess::connectToProgressDialog(const ProgressDialog * dialog){
    connect(this, SIGNAL(started()), dialog, SLOT(show()));
    connect(this, SIGNAL(levelUpdated(int)), dialog, SLOT(updateLevel(int)));
    connect(this, SIGNAL(processNameUpdated(QString)), dialog, SLOT(updateProcessName(QString)));
    connect(this, SIGNAL(finished()), dialog, SLOT(close()));
    connect(this, SIGNAL(finished()), dialog, SLOT(deleteLater()));
}

void DefaultProcess::connectToProgressBar(const QProgressBar *bar) {
    connect(this, SIGNAL(started()), bar, SLOT(show()));
    connect(this, SIGNAL(levelUpdated(int)), bar, SLOT(setValue(int)));
}

CubException * DefaultProcess::lastException(){
    return _lastException;
}

void DefaultProcess::saveException(CubException e){
    if(_lastException){
        delete _lastException;
        _lastException = 0;
    }
    _lastException = new CubException(e);
}
