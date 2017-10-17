#ifndef MYOMANAGER_H
#define MYOMANAGER_H

#include <myo/myo.hpp>
#include <array>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <qstring.h>
#include <qdebug.h>

#include "managerInterface.h"
#include "constants.h"
#include "registerData.h"
#include "gestureClassifier.h"

#define N 6
#define LASTN 15

//max dimension of buffer containing last values : dimension of array containing sliding windows
#define NWINDOWS 3
#define BUFFER_MAX (WINDOW_DIM + NWINDOWS - 1)

class myoManager : public myo::DeviceListener, public managerInterface
{
public:
	myoManager(registerData *rd1, QString *reqGest)
		: onArm(false), isUnlocked(false), roll_w(0), pitch_w(0), yaw_w(0), currentPose()//emgSamples()
	{
		rd = rd1;
		qRecognizedGesture = reqGest;
		for (int i = 0; i < LASTN; i++){
			lastGestures[i] = 0;
		}
		for (int i = 0; i < NWINDOWS; i++){
			lastGests[i] = -1;
		}
	}
	~myoManager();

	bool onArm;
	myo::Arm whichArm;

	// This is set by onUnlocked() and onLocked() above.
	bool isUnlocked;

	// These values are set by onOrientationData() and onPose() above.
	int roll_w, pitch_w, yaw_w;
	myo::Pose currentPose;
	
	int lastGestures[LASTN];

	/*this object is used to store data, becouse myo lost all the data after execution of onArmSync function*/
	registerData *rd = NULL;
	QString *qRecognizedGesture = NULL;

	//funcions
	void onUnpair(myo::Myo* myo, uint64_t timestamp);
	void onEmgData(myo::Myo* myo, uint64_t timestamp, const int8_t* emg);
	void onOrientationData(myo::Myo *myo, uint64_t timestamp, const myo::Quaternion< float > &rotation);
	void onAccelerometerData(myo::Myo *myo, uint64_t timestamp, const myo::Vector3< float > &accel);
	void onGyroscopeData(myo::Myo *myo, uint64_t timestamp, const myo::Vector3< float > &gyro);
	void onConnect(myo::Myo *myo, uint64_t timestamp, myo::FirmwareVersion firmwareVersion);
	void onPose(myo::Myo* myo, uint64_t timestamp, myo::Pose pose);
	void onArmSync(myo::Myo* myo, uint64_t timestamp, myo::Arm arm, myo::XDirection xDirection, float rotation,
		myo::WarmupState warmupState);
	void onArmUnsync(myo::Myo* myo, uint64_t timestamp);
	void onUnlock(myo::Myo* myo, uint64_t timestamp);
	void onLock(myo::Myo* myo, uint64_t timestamp);

	void print();
	void run();
	void update();
	int getGesture();

	void read() ;
	QString getFrameData(int frame);
	QString getPositionFrameData(int frame);
	void start() ;
	void stop() ;
	QString getRecognisedGesture();

	void startRecording();
	void stopRecording();

private:
	//functions
	int8_t getMean(std::array<int8_t, N> values);
	int8_t getVariance(std::array<int8_t, N> values, int8_t mean);
	int8_t getMax(std::array<int8_t, 8> values, int num);
	std::array<int8_t, N> getColumn(std::array<std::array<int8_t, 8>, N> emgSet, int col);

	// The values of this array is set by onEmgData() above.
	int gest = -1;
	bool recording;
	std::string gesture;
	std::string recognisedGesture = "errore";
	std::array <int8_t, 8> emgSamples;
	std::array<std::array<int8_t, 8>, N> emgSet;
	std::array<int8_t, 8> variances;
	int emgRegCounter = 0;
	myo::Hub *hub;
	myoManager *collector;
	int val;
	std::array<std::array<int8_t, 8>, BUFFER_MAX> lastSamples;
	std::array<std::array<int8_t, 8>, WINDOW_DIM> lastWindow;
	gestureClassifier gestureClass;
	int lastGests[NWINDOWS];

};
#endif
