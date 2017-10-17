#include "cameraManager.h"
#include <qdebug.h>


cameraManager::cameraManager()
{
}


cameraManager::~cameraManager()
{
}

void cameraManager::read()			
{
#ifdef USE_LEAPCAM
		Frame frm = controller.frame();
		Image imgsx = frm.images()[0];
		Image imgdx = frm.images()[1];
		if (imgsx.isValid())
		{
			qCameraFrame = QImage((unsigned char*)imgsx.data(), imgsx.width(), imgsx.height(), QImage::Format_Indexed8);
			qCameraFrame2 = QImage((unsigned char*)imgdx.data(), imgdx.width(), imgdx.height(), QImage::Format_Indexed8);
		}
		else{
			qDebug() << "frame invalido";
		}
#else

		if (state != CONNECTED) return;
		cam->read(cameraFrame);

		qCameraFrame = QImage((unsigned char*)cameraFrame.data, cameraFrame.cols, cameraFrame.rows, QImage::Format_RGB888);
#endif
		if (recording){
			if (counter < RECORDING_DIM)
			{
				cameraFrames[counter] = qCameraFrame.copy();
				const QDateTime now = QDateTime::currentDateTime();
				const QString timestamp = now.toString(QLatin1String("yyyyMMdd-hhmmsszzz"));
#ifdef USE_LEAPCAM
				camera1Frames[counter] = qCameraFrame2.copy();
				frameNames[counter] = QString::fromLatin1(".\\savedData\\frameSx-%1.png").arg(timestamp);
				frame1Names[counter] = QString::fromLatin1(".\\savedData\\frameDx-%1.png").arg(timestamp);
#else
				frameNames[counter] = QString::fromLatin1(".\\savedData\\frame-%1.png").arg(timestamp);
#endif
				counter++;
			}
		}
	
}

QPixmap cameraManager::getCurrentFrame()
{
	return QPixmap::fromImage(qCameraFrame);
}

QPixmap cameraManager::getCurrentFrame2()
{
#ifdef USE_LEAPCAM
	return QPixmap::fromImage(qCameraFrame2);
#else
	return NULL;
#endif
}

QString cameraManager::getFrameData(int frame)
{
	if (counter > frame) return frameNames[(frame / frameRate)*frameRate];
	return "";
}
void cameraManager::start()			
{
	controller = Controller();
	controller.setPolicy(Leap::Controller::POLICY_IMAGES);
	images = controller.images();


	cam = new cv::VideoCapture(0);
	if (!cam->isOpened()) { //check if video device has been initialised
		std::cout << "cam error";
		state = DISCONNECTED;
	}
	else {
		state = CONNECTED;
		//cv::namedWindow("Display window", cv::WINDOW_AUTOSIZE);	
	}
	
}
void cameraManager::stop()			
{
	
}

void cameraManager::startRecording(){
	counter = 0;
	recording = true;
}

void cameraManager::stopRecording(){
	recording = false;
}

void cameraManager::saveFrames(){
	for (int i = 0; i < counter; i+=frameRate){
		cameraFrames[i].save(frameNames[i], "PNG");
	}
#ifdef USE_LEAPCAM
	saveFrames1();
#endif
}

void cameraManager::saveFrames1(){
#ifdef USE_LEAPCAM
	for (int i = 0; i < counter; i++){
		camera1Frames[i].save(frame1Names[i], "PNG");
	}
#endif
}

void cameraManager::setFrameRate(int fr){
	frameRate = fr;
}