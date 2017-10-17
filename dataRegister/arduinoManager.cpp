#include "arduinoManager.h"


arduinoManager::arduinoManager()
{
	arduino = new serialPort(port_name);
	if (arduino->isConnected()) {
		qDebug ()<< "Connection Established \n";
	}
	else qDebug() <<"ERROR, check port name\n";
}

arduinoManager::~arduinoManager()
{
}

void arduinoManager::read(){
	if (arduino->isConnected()){
		int read_result = arduino->readSerialPort(incomingData, MAX_DATA_LENGTH);
		//prints out data
		if (read_result!=0){
				state = "";
				sensors[incomingData[0]] = incomingData[1];
				std::string temp(1, incomingData[0]);
				state = "sensor ";
				state += incomingData[0];
				state += " ";
				if (incomingData[1] == '1') {
					sensorStates |= sensorsValues[incomingData[0] - '0'];
					state += "touched";
				}
				else if (incomingData[1] == '0'){
					sensorStates &= ~(sensorsValues[incomingData[0] - '0']);
					state += "released"; 
				}
		}
		if (recording){
			if (counter < RECORDING_DIM){
				//recordStates[counter] = QString::fromUtf8(state.c_str());
				recordSensorStates[counter] = sensorStates;
				counter++;
			}
		}

	}
	else {
		for (int i = 0; i < NSENSORS; i++){
			sensors[i] = -1;
		}
	}
}

QString arduinoManager::getFrameData(int frame){
	if (frame < counter){
		return QString::number(recordSensorStates[frame]);
	}
	return "";
}
void  arduinoManager::start(){

}
void  arduinoManager::stop(){}

QString arduinoManager::getState(){
	return QString::fromUtf8(state.c_str());
}

void arduinoManager::startRecording(){
	counter = 0;
	recording = true;
}

void arduinoManager::stopRecording(){
	recording = false;
}