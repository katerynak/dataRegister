#ifndef GESTURECLASSIFIER_H
#define GESTURECLASSIFIER_H

#include <array>
#include <vector>

#include "constants.h"
#include "registerData.h"
#include "gestureSet.h"
/*
typedef std::array <int8_t, 8> emgSet;
typedef std::array <emgSet, TRAIN_GESTURES_NUM> gestureSet;*/

class gestureClassifier
{
public:
	gestureClassifier();
	~gestureClassifier();

	std::string classifyGesture(std::array <emgSet, WINDOW_DIM> sample);
	int classifyGestureNum(std::array <emgSet, WINDOW_DIM> sample);
	std::string getGestureString(int gest);
	void loadTrainData();

private:
	//load your class files here 
	std::vector<gestureSet> gestures;
	std::vector<gestureSet>::iterator it;
	registerData rd; //we need this object to obtain a list of gestures
	
};

#endif //GESTURECLASSIFIER_H