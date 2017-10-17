#ifndef QCSVFILE_H
#define QCSVFILE_H

#include <QObject>
#include <qstring.h>
#include <QTextStream>
#include <QFile>
#include <QStandardItemModel>
#include <qdebug.h>

class qCsvFile : public QObject
{
	Q_OBJECT

public:
	qCsvFile(QObject *parent);
	~qCsvFile();

	void setFileName(QString name);
	bool newCsv();
	void close();
	void addRow(QStringList r);
	void newRow();
	void addElement(QString el);

private:

	QString fileName;
	QFile *file;
	QStringList *row;
	QTextStream *ts;
};

#endif // QCSVFILE_H
