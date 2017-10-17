#ifndef ARDUINOMANAGER_H
#define ARDUINOMANAGER_H

#include "serialPort.h"
#include <stdio.h>
#include "managerInterface.h"
#include "constants.h"
#include <qdebug.h>
#include <qstring.h>
//number of touch adafruit sensors
#define NSENSORS 12

const int sensorsValues[12] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x100, 0x200, 0x400, 0x800 };

class arduinoManager : public managerInterface
{
public:
	arduinoManager();
	~arduinoManager();

	void read();
	QString getFrameData(int frame);
	void start();
	void stop();
	QString getState();

	void startRecording();
	void stopRecording();
private:
	//String for incoming data from arduino
	char incomingData[MAX_DATA_LENGTH];
	char *port_name = "\\\\.\\COM4";
	serialPort *arduino;
	std::string buff;
	int sensors[NSENSORS]; // per ogni sensore salvo un valore intero di stato, a partire da 1
	std::string state = "start";
	int sensorStates = 0;
	int recordSensorStates[RECORDING_DIM];
	QString recordStates[RECORDING_DIM];
	int counter = 0;
	bool recording = false;
	//da mettere lo stato in esadecimale
	/*
		convenzione stati:
			-1: arduino disconnected
			0: released
			1: touched

			
	*/
	
};
#endif //ARDUINOMANAGER_H