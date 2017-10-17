#ifndef DATAREGISTER_H
#define DATAREGISTER_H

//#include "serialPort.h"
#include "arduinoManager.h"

#include <QtWidgets/QMainWindow>
#include <qtimer.h>
#include <qelapsedtimer.h>
#include <QDebug>
#include <qstring.h>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

#include "ui_dataregister.h"
#include "myoManager.h"
#include "registerData.h"
#include "cameraManager.h"
#include "qCsvFile.h"
#include "csvPreferences.h"



enum DATA{ CAMERA, GESTURES, ROTATION, TOUCH_SENSORS, DATA_DIM };
static QString data_headers[DATA_DIM] = {  "camera", "gesture", "rotation", "sensors" };

class dataRegister : public QMainWindow
{
	Q_OBJECT

public:
	dataRegister(QWidget *parent = 0);
	~dataRegister();	
	QString *gest;
private:
	Ui::dataRegisterClass ui;
	QTimer _timer;

	registerData *rd1;
	myoManager *myo;
	cameraManager *cam;
	arduinoManager *arduino;

	qCsvFile *recordFile;
	csvPreferences *preferences;
	int counter = 0;
	bool recording = false;

	bool Init();
	bool StartDevices();
	void SetupUi();

	bool dataCsv[DATA_DIM] ;

	private slots:
		bool Process();
		void startRecording();
		void stopRecording();
		void saveRecording();
		void openPreferences();
		void closePreferences();
		void resume();

};

#endif // DATAREGISTER_H
