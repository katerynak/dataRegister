#ifndef REGISTERDATA_H
#define REGISTERDATA_H

#include <array>
#include <string>
#include <myo/myo.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <sys/stat.h>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <qstring.h>

#include "constants.h"

//number of emgSets per registration of a single gesture
#define C 200

class registerData
{
public:
	registerData();
	~registerData();

	enum FORMATS{ CSV, BIN };
	std::array<std::string, MAX_GEST> gestures;

	int addRecord(std::array<int8_t, 8> emgSet); //returns 0 if set was added , -1 if the memory is full
	void setFormat(FORMATS format);
	void setGesture();
	int addNewGesture(std::string gestName);
	int saveData();
	int loadGestures();
	void setCurrentGesture(std::string g);
	std::string getFrameData(int frame);
	std::string getHeaders();
	std::array<std::array<int, 8>, MYO_FRAMES> emgRegSet;
	int getGesturesNumber();
	bool checkGesture(std::string gest); //returns true if gesture is already present
	myo::Vector3< float > gyro;
	float roll, pitch, yaw;
	QString getRoll();
	QString getPitch();
	QString getYaw();
	QString getGyroxData();
	QString getGyroyData();
	QString getGyrozData();
	QString getPosition();

	bool recording = false;
	int counter = 0;
	QString recordGestures[RECORDING_DIM];
	/*we will distinct for simplicity two angles : "up" and "down", or maybe some other positions*/
	int currentAngle;
	int angles[RECORDING_DIM];

private:
	//registering data
	bool registering = false; // da sostituire con registeringNewGesture
	int gesture;
	std::string gestureString;
	int pointer = 0;
	FORMATS format;
	std::string gesturesFileName = GESTURES_FILE_NAME;
	std::fstream gesturesFile;
	std::string currentDataFileName;
	//std::fstream currentDataFile; // see if csv files are also supported by this class
	std::string currentGesture = "unknown";
	void gesturesInit();
};

#endif //REGISTERDATA_H