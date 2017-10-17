#include "dataregister.h"

#include <QDebug>


dataRegister::dataRegister(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	SetupUi();
	StartDevices();
	Init();
}

dataRegister::~dataRegister()
{

}
 
void dataRegister::SetupUi(){
	preferences = new csvPreferences();
	preferences->setDisabled(true);
	preferences->setVisible(false);
	connect(ui.recordButton, SIGNAL(clicked()), this, SLOT(startRecording()));
	connect(ui.stopButton, SIGNAL(clicked()), this, SLOT(stopRecording()));
	connect(ui.saveButton, SIGNAL(clicked()), this, SLOT(openPreferences()));
	connect(ui.pauseButton, SIGNAL(clicked()), &_timer, SLOT(stop()));
	connect(ui.resumeButton, SIGNAL(clicked()), this, SLOT(resume()));
	connect(preferences->ui.saveButton, SIGNAL(clicked()), this, SLOT(saveRecording()));
	connect(preferences->ui.cancelButton, SIGNAL(clicked()), this, SLOT(closePreferences()));

}


bool dataRegister::Init()
{
	_timer.setInterval(10);
	_timer.start();
	connect(&_timer, SIGNAL(timeout()), this, SLOT(Process()));
	return true;
}

bool dataRegister::Process()
{
	cam->read();
	ui.webcamLabel->setPixmap(cam->getCurrentFrame());
#ifdef USE_LEAPCAM
	ui.webcam2Label->setPixmap(cam->getCurrentFrame2());
#endif
	arduino->read();
	myo->read();
	ui.gestureLabel->setText(gest->append(""));
	ui.touchStateLabel->setText(arduino->getState());
	ui.gyroxLabel->setText(rd1->getGyroxData());
	ui.gyroyLabel->setText(rd1->getGyroyData());
	ui.gyrozLabel->setText(rd1->getGyrozData());
	ui.positionLabel->setText(rd1->getPosition());

	ui.yawLabel->setText(rd1->getYaw());
	ui.rollLabel->setText(rd1->getRoll());
	ui.pitchLabel->setText(rd1->getPitch());

	if (recording) {
		if (counter < RECORDING_DIM){
			counter++;
		}
	}
	return true;
}

bool dataRegister::StartDevices()
{
	
	gest = new QString("Fist");
	rd1 = new registerData();
	int numGest = rd1->getGesturesNumber();

	for (int i = 0; i < numGest; i++){
		qDebug() << i << ". " << QString::fromUtf8(rd1->gestures.at(i).data(), rd1->gestures.at(i).size()) << "\n";
	}
	myo = new myoManager(rd1, gest);
	cam = new cameraManager();
	arduino = new arduinoManager();
	arduino->start();
	cam->start();
	myo->start();
	return true;
}

void dataRegister::startRecording(){
	//start recording in all devices, except myo, we have registerData class to record myo data
	cam->startRecording();
	arduino->startRecording();
	myo->startRecording();
	ui.recordButton->setDisabled(true);
	ui.saveButton->setDisabled(false);
	recording = true;
	counter = 0;
}
void dataRegister::stopRecording(){
	//start recording in all devices, except myo, we have registerData class to record myo data
	cam->stopRecording();
	arduino->stopRecording();
	myo->stopRecording();
	ui.recordButton->setDisabled(false);
	recording = false;
}

void dataRegister::saveRecording(){
	preferences->ui.saveButton->setDisabled(true);

	dataCsv[GESTURES] = preferences->ui.gesturesCheckBox->isChecked();
	dataCsv[CAMERA] = preferences->ui.cameraCheckBox->isChecked();
	dataCsv[TOUCH_SENSORS] = preferences->ui.touchCheckBox->isChecked();
	dataCsv[ROTATION] = preferences->ui.rotationCheckBox->isChecked();

	QStringList headers;
	QStringList row;

	if (dataCsv[CAMERA]){
		cam->setFrameRate(preferences->ui.ratioComboBox->currentIndex() + 1);
		cam->saveFrames();
	}

	recordFile = new qCsvFile(this);
	const QDateTime now = QDateTime::currentDateTime();
	const QString timestamp = now.toString(QLatin1String("yyyyMMdd-hhmmsszzz"));
	QString filename = QString::fromLatin1(".\\savedData\\Recording-%1.csv").arg(timestamp);
	recordFile->setFileName(filename);
	recordFile->newCsv();
	
	for (int i = 0; i < DATA_DIM; i++){
		if (dataCsv[i]) headers << data_headers[i];
	}

	recordFile->addRow(headers);
	
	//order of strings in row must respect order of enum headers	
	for (int i = 0; i < counter; i++){
		row.clear();
		if (dataCsv[CAMERA]){
			row << cam->getFrameData(i);
		}
		if (dataCsv[GESTURES]){
			row << myo->getFrameData(i); 
		}
		if (dataCsv[ROTATION]){
			row << myo->getPositionFrameData(i);
		}

		if (dataCsv[TOUCH_SENSORS]){
			row << arduino->getFrameData(i);
		}
		recordFile->addRow(row);
	}

	recordFile->close();
	ui.saveButton->setDisabled(true);

	closePreferences();
	preferences->ui.saveButton->setDisabled(false);
}

void dataRegister::openPreferences(){
	preferences->setDisabled(false);
	preferences->setVisible(true);
}

void dataRegister::closePreferences(){
	preferences->setDisabled(true);
	preferences->setVisible(false);
}

void dataRegister::resume(){
	StartDevices();
	_timer.start();
}