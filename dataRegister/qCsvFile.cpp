#include "qCsvFile.h"

qCsvFile::qCsvFile(QObject *parent)
	: QObject(parent)
{

}

qCsvFile::~qCsvFile()
{

}

void qCsvFile::setFileName(QString name){
	this->fileName = name;
}

bool qCsvFile::newCsv(){
	file = new QFile(fileName);
	ts = new QTextStream(file);
	row = new QStringList();
	return file->open(QIODevice::WriteOnly);
}

void qCsvFile::close(){
	file->close();
}

void qCsvFile::addRow(QStringList r){
	*ts << r.join(",") + "\n";
}

void qCsvFile::newRow(){
	*ts << "\n";
}
void qCsvFile::addElement(QString el){
	*ts << el << ",";
}