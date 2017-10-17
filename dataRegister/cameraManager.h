#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <qpixmap.h>
#include <string.h>
#include <ctime>
#include <qbuffer.h>
#include <qfile.h>
#include <QTime>

#include "managerInterface.h"
#include "constants.h"
#include "Leap.h"

using namespace Leap;
using namespace cv;

class cameraManager : public managerInterface
{
public:
	cameraManager();
	~cameraManager();

	void read();
	QString getFrameData(int frame);
	void start();
	void stop();
	QPixmap getCurrentFrame();
	QPixmap getCurrentFrame2();
	void saveFrames();
	void startRecording();
	void stopRecording();
	void setFrameRate(int fr);

private:
	void saveFrames1();

	cv::VideoCapture *cam;
	enum STATES{CONNECTED, DISCONNECTED};
	STATES state = DISCONNECTED;
	cv::Mat cameraFrame;
	QImage qCameraFrame;
	QImage qCameraFrame2;
	QImage cameraFrames[RECORDING_DIM];
#ifdef USE_LEAPCAM
	QImage camera1Frames[RECORDING_DIM];
	QString frame1Names[RECORDING_DIM];
#endif
	QString frameNames[RECORDING_DIM];
	int counter = 0;
	bool recording = false;
	Controller controller;
	ImageList images;
	int frameRate = 1;
};

#endif //CAMERAMANAGER_H

