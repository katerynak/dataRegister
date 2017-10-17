#include "registerData.h"


registerData::registerData()
{
	gesturesInit();
	loadGestures();
}

registerData::~registerData()
{
}

int registerData::addRecord(std::array<int8_t, 8> emgSet){
	if (pointer < C){
		//		emgRegSet[pointer] = emgSet;
		pointer++;
		return 0;
	}
	return -1;
}

void registerData::setFormat(FORMATS format){
	this->format = format;
}

int registerData::addNewGesture(std::string gestName){
	if (!checkGesture(gestName)){
		gesturesFile.open(gesturesFileName, std::ios::app);
		if (gesturesFile.is_open())
		{
			gesturesFile << gestName /*<< " " << gestNumber*/ << "\n";
			gesturesFile.close();
			//reload gestures from file
			loadGestures();
			return 0;
		}
	}
	else return 1;
}

int registerData::saveData(){
	currentDataFileName = currentGesture + ".csv";
	std::fstream currentDataFile;
	time_t t = time(0);   // get time now
	currentDataFile.open(currentDataFileName, std::fstream::app);
	if (currentDataFile.is_open()){
		char buff[20];
		strftime(buff, 20, "%Y-%m-%d %H:%M:%S", localtime(&t));
		currentDataFile << buff << "\n";
		currentDataFile << getHeaders() << "\n";
		for (int raw = 0; raw < MYO_FRAMES; raw++){
			std::string str = getFrameData(raw);
			currentDataFile << str;
			currentDataFile << "\n";
		}
		currentDataFile.close();
		return 0;
	}
	else return 1;
}

int registerData::loadGestures(){
	//loading gesture types from file
	std::string gestLine;
	int gestNumber = 0;
	gesturesFile.open(gesturesFileName);
	if (gesturesFile.is_open()){
		while (getline(gesturesFile, gestLine))
		{
			if (gestNumber < MAX_GEST){
				std::istringstream some_stream(gestLine);
				gestures.at(gestNumber) = gestLine;
				gestNumber++;
			}
		}
		gesturesFile.close();
		return 0;
	}
	else return 1;
}

void registerData::setCurrentGesture(std::string g){
	if (checkGesture(g))
		currentGesture = g;
	else
		currentGesture = "not_found";
	std::cout << currentGesture;
}


std::string registerData::getFrameData(int frame){
	std::string result;
	std::ostringstream convert;
	for (int i = 0; i < 8; i++){
		convert << std::to_string(emgRegSet[frame][i]);
		/*if (i != 7)*/ convert << ",";
	}
	convert << std::to_string(angles[frame]);
	result = convert.str();
	return result;
}

std::string registerData::getHeaders(){
	std::string result;
	std::ostringstream convert;
	convert << "emg0,emg1,emg2,emg3,emg4,emg5,emg6,emg7,position";
	result = convert.str();
	return result;
}

void registerData::gesturesInit(){
	for (int i = 0; i < MAX_GEST; i++){
		gestures.at(i) = "";
	}
}

int registerData::getGesturesNumber(){
	int ret = 0;
	for (int i = 0; i < MAX_GEST; i++){
		if (gestures.at(i).compare("") != 0) ret++;
	}
	return ret;
}

bool registerData::checkGesture(std::string gest)
{
	if (std::find(gestures.begin(), gestures.end(), gest) != gestures.end())
		return true;
	else
		return false;
}

QString registerData::getGyroxData(){
	QString ret = "";
	ret += QString::number(gyro.x());
	return ret;
}

QString registerData::getGyroyData(){
	QString ret = "";
	ret += QString::number(gyro.y());
	return ret;
}

QString registerData::getGyrozData(){
	QString ret = "";
	ret += QString::number(gyro.z());
	return ret;
}

QString registerData::getRoll(){
	QString ret = "";
	ret += QString::number(roll);
	return ret;
}
QString registerData::getPitch(){
	QString ret = "";
	ret += QString::number(pitch);
	return ret;
}
QString registerData::getYaw(){
	QString ret = "";
	ret += QString::number(yaw);
	return ret;
}

QString registerData::getPosition(){
	QString ret = "";
	if (currentAngle == 0) ret += "Down";
	else if (currentAngle == 1) ret += "Up";
	else ret += "Error";
	return ret;
}