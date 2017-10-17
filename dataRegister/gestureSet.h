#ifndef GESTURESET_H
#define GESTURESET_H

#include <string>
#include <array>
#include <cstdint>
#include <fstream>
#include <sstream>
#include "constants.h"

typedef std::array <int8_t, 8> emgSet;
typedef std::array <emgSet, TRAIN_GESTURES_NUM> gestSet;

class gestureSet
{
public:
	gestureSet();
	~gestureSet();
	void load();

	void setSamplesNumber(int samplesNumber) { this->samplesNumber = samplesNumber; }
	int getSamplesNumber() { return this->samplesNumber; }
	void setName(std::string name) { this->name = name; }
	std::string getName() { return this->name; }
	int64_t checkMatch(std::array<emgSet, WINDOW_DIM> sample);

private:
	std::string name;
	gestSet gestureData;
	int samplesNumber=0; //counter of loaded gestures
};

#endif //GESTURESET_H

