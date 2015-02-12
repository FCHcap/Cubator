#include "Data.h"
#include <iostream>

Data *Data::_data = 0;

Data * Data::getInstance(){
    if(!_data) _data = new Data();
    return _data;
}

void Data::kill(){
    delete _data;
    _data = 0;
}

void Data::addTable(const QString &name, const QDate &date, const QString &comments) throw (CubException){

    // erreur si le nom de la table existe déjà dans la liste
    if(_tables.contains(name)){
        throw CubException(BRIEF02, ERROR10, "Data::addTable");
    }

    Table t;
    t.date = date;
    t.comments = comments;

    _tables.insert(name, t);
}

void Data::removeTable(const QString &name) throw (CubException){

    tableExists(name, "Data::removeTable", BRIEF03);
    _tables.remove(name);
}

void Data::initTable(const QString &table) throw (CubException){

    QStringList files;
    files << vectorFileName(table) << triangleFilename(table);

    // crée les fichiers correspondant à la table s'ils n'existent pas
    foreach(QString file, files){

        if(!QFile::exists(file)){
            QFile ffile(file);
            if(!ffile.open(QIODevice::ReadWrite)){
                throw CubException(BRIEF06, TEXT01 + file, "Data::initTable");
            }
            ffile.close();
        }
    }
}

QStringList Data::tables() const{
    return _tables.keys();
}

QDate Data::date(const QString &name) const throw (CubException){

    tableExists(name);

    Table t = _tables.value(name);
    return t.date;
}

QString Data::comments(const QString &name) const throw (CubException){

    tableExists(name, (QString) "Data::comments");

    Table t = _tables.value(name);
    return t.comments;
}

void Data::save() throw (CubException){

    // Ouvre le fichier contenant la description de tables
    QFile file(TABLE_FILENAME);

    if(!file.open(QIODevice::WriteOnly)){
        throw CubException(BRIEF06, QString(TEXT01) + QString(TABLE_FILENAME), "Data::Data");
    }

    QDataStream stream(&file);

    // Writing tables informations
    QStringList keys = _tables.keys();
    for(int i=0; i<keys.size(); i++){
        stream << keys.at(i).toStdString().c_str();

        Table t = _tables.value(keys.at(i));
        stream << t.date.toString("dd-MM-yyyy").toStdString().c_str();
        stream << t.comments.toStdString().c_str();
    }
}

QString Data::vectorFileName(const QString &table){
    return QString("DATA/" + table + "_VEC.bin");
}

QString Data::triangleFilename(const QString &table){
    return QString("DATA/" + table + "_TRI.bin");
}

QString Data::imageFilename(const QString &table){
    return QString("DATA/" + table + "_IMG.bmp");
}

QString Data::gridFilename(const QString &table){
    return QString("DATA/" + table + "_GRI.bin");
}

void Data::tableExists(const QString &table, const QString method, const QString brief) const throw(CubException){

    if(!_tables.contains(table)){
        CubException e(BRIEF01, ERROR11, "Data::date");
        if(!brief.isEmpty()) e.setBrief(brief);
        if(!method.isEmpty()) e.setMethod(method);
        throw e;
    }
}

Data::Data() throw (CubException){

    QDir dir;
    dir.mkpath("DATA");

    QFile file(TABLE_FILENAME);

    if(!file.exists()){ // crée le fichier s'il n'existe pas
        file.open(QIODevice::WriteOnly);
    }
    else{
        // ouvre le fichier
        if(!file.open(QIODevice::ReadOnly)){
            QString filename(TEXT01);
            filename.append(TABLE_FILENAME);

            throw CubException(BRIEF06, filename, "Data::Data");
        }
        QDataStream stream(&file);

        // lecture des informations de tables
        while(!stream.atEnd()){
            Table t;

            char * name;
            char * date;
            char * comments;
            stream >> name >> date >> comments;
            if(stream.status() == QDataStream::ReadCorruptData){
                throw CubException(BRIEF07, TEXT01 + TABLE_FILENAME, "Data::Data");
            }

            t.date = QDate::fromString(QString(date), "dd-MM-yyyy");
            t.comments = QString(comments);

            _tables.insert(QString(name), t);
        }
    }
}

Data::~Data() throw (CubException){
    save();
}
