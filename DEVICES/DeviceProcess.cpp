#include "DeviceProcess.h"

DeviceProcess::DeviceProcess(QObject *parent) :
    QObject(parent)
{
    _settings = 0;
    _device = 0;
    _timerTimeout = 0;
    _timerInconsistent = 0;
}

DeviceProcess::~DeviceProcess(){
    _settings = 0;
}

QStringList DeviceProcess::listBaudrate(){
    QStringList baudrate;
    baudrate << "1200" << "2400" << "4800" << "9600" << "19200" << "38400" << "57600" << "115200";
    return baudrate;
}

QStringList DeviceProcess::listDataBits(){
    QStringList databits;
    databits << "5" << "6" << "7" << "8";
    return databits;
}

QStringList DeviceProcess::listStopBit(){
    QStringList stopbit;
    stopbit << "OneStop" << "OneAndHalfStop" << "TwoStop";
    return stopbit;
}

QStringList DeviceProcess::listParity(){
    QStringList parity;
    parity << "NoParity" << "EventParity" << "OddParity" << "SpaceParity" << "MarkParity";
    return parity;
}

QStringList DeviceProcess::listFlowControl(){
    QStringList flowcontrol;
    flowcontrol << "NoFlowControl" << "HardwareControl" << "SoftwareControl";
    return flowcontrol;
}

void DeviceProcess::applyParameters(QSerialPort &device){

    try{
        bool ok = 1;

        if(_settings->rate().contains("1200")) ok = device.setBaudRate(QSerialPort::Baud1200);
        else if(_settings->rate().contains("2400")) ok = device.setBaudRate(QSerialPort::Baud2400);
        else if(_settings->rate().contains("4800")) ok = device.setBaudRate(QSerialPort::Baud4800);
        else if(_settings->rate().contains("9600")) ok = device.setBaudRate(QSerialPort::Baud9600);
        else if(_settings->rate().contains("19200")) ok = device.setBaudRate(QSerialPort::Baud19200);
        else if(_settings->rate().contains("38400")) ok = device.setBaudRate(QSerialPort::Baud38400);
        else if(_settings->rate().contains("57600")) ok = device.setBaudRate(QSerialPort::Baud57600);
        else if(_settings->rate().contains("115200")) ok = device.setBaudRate(QSerialPort::Baud115200);
        else{ ok = 0;}

        if(!ok) throw CubException(BRIEF11, TEXT04 + _settings->rate(), "DeviceProcess::start");

        if(_settings->dataBits().contains("5")) ok = device.setDataBits(QSerialPort::Data5);
        else if(_settings->dataBits().contains("6")) ok = device.setDataBits(QSerialPort::Data6);
        else if(_settings->dataBits().contains("7")) ok = device.setDataBits(QSerialPort::Data7);
        else if(_settings->dataBits().contains("8")) ok = device.setDataBits(QSerialPort::Data8);
        else{ ok = 0;}

        if(!ok) throw CubException(BRIEF11, TEXT05 + _settings->dataBits(), "DeviceProcess::start");

        if(_settings->stopBit().contains("OneStop")) ok = device.setStopBits(QSerialPort::OneStop);
        else if(_settings->stopBit().contains("OneAndHalfStop")) ok = device.setStopBits(QSerialPort::OneAndHalfStop);
        else if(_settings->stopBit().contains("TwoStop")) ok = device.setStopBits(QSerialPort::TwoStop);
        else{ ok = 0;}

        if(!ok) throw CubException(BRIEF11, TEXT06 + _settings->stopBit(), "DeviceProcess::start");

        if(_settings->parity().contains("NoParity")) ok = device.setParity(QSerialPort::NoParity);
        else if(_settings->parity().contains("EventParity")) ok = device.setParity(QSerialPort::EvenParity);
        else if(_settings->parity().contains("OddParity")) ok = device.setParity(QSerialPort::OddParity);
        else if(_settings->parity().contains("SpaceParity")) ok = device.setParity(QSerialPort::SpaceParity);
        else if(_settings->parity().contains("MarkParity")) ok = device.setParity(QSerialPort::MarkParity);
        else {ok = 0;}

        if(!ok) throw CubException(BRIEF11, TEXT07 + _settings->parity(), "DeviceProcess::start");

        if(_settings->flowControl().contains("NoFlowControl")) ok = device.setFlowControl(QSerialPort::NoFlowControl);
        else if(_settings->flowControl().contains("HardwareControl")) ok = device.setFlowControl(QSerialPort::HardwareControl);
        else if(_settings->flowControl().contains("SoftwareControl")) ok = device.setFlowControl(QSerialPort::SoftwareControl);
        else{ok = 0;}

        if(!ok) throw CubException(BRIEF11, TEXT08 + _settings->flowControl(), "DeviceProcess::start");
    }

    catch(CubException e){
        emit exceptionLaunched(e);
    }
}

void DeviceProcess::open(){

    begin:

    if(!_timerTimeout){
        _timerTimeout = new QTimer;
        _timerTimeout->setInterval(2000);
        connect(_timerTimeout, SIGNAL(timeout()), this, SLOT(processTimerTimeout()));
        _timerTimeout->start();
    }

    if(!_timerInconsistent){
        _timerInconsistent = new QTimer;
        _timerInconsistent->setInterval(2000);
        connect(_timerInconsistent, SIGNAL(timeout()), this, SIGNAL(inconsistentData()));
        _timerInconsistent->start();
    }

    if(!_device){
        _device = new QSerialPort;
        connect(_device, SIGNAL(readyRead()), this, SLOT(read()));
    }

    if(_device->isOpen()){
        _device->close();
        goto begin;
    }
    loadSettings();
    _device->setPortName(_settings->name());

    // Checks if the _device is open
    if(_settings && !_device->isOpen()){
        if(_settings->enabled()){
            if(!_device->open(QIODevice::ReadOnly)){
                emit exceptionLaunched(CubException(BRIEF12, _device->errorString(), "DeviceProcess::start"));
                emit connected(0);
            }
            else{
                applyParameters(*_device);
                emit connected(1);
            }
        }
    }
}

void DeviceProcess::run(){

    connect(this, SIGNAL(finished()), this, SLOT(deleteLater()));

    open();
    emit started();
}

void DeviceProcess::read(){
    // Reads data
    if(_device->isOpen()){
        _data.append(_device->readAll());
        _timerTimeout->start();

        while(_data.contains('\n')){
            int index = _data.indexOf('\n');
            QByteArray frame = _data.left(index+1);
            _data.remove(0, index+1);
            processFrame(frame);
        }
    }

}

void DeviceProcess::processTimerTimeout(){
    _timerInconsistent->stop();
    emit timeout();
}

void DeviceProcess::quit(){
    if(_device->isOpen()) _device->close();
    emit finished();
    delete _device;
    delete _timerTimeout;
    delete _timerInconsistent;
    _device = 0;
    _timerTimeout = 0;
    _timerInconsistent = 0;
}

void DeviceProcess::reloadSettings(){
    open();
}

void DeviceProcess::setEnabled(bool enabled){

    if(enabled)
        connect(_device, SIGNAL(readyRead()), this, SLOT(read()));
    else
        disconnect(_device, SIGNAL(readyRead()), this, SLOT(read()));
}
