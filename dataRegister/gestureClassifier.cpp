#include "gestureClassifier.h"


gestureClassifier::gestureClassifier()
{
	loadTrainData();
}


gestureClassifier::~gestureClassifier()
{

}

void gestureClassifier::loadTrainData(){
	rd.loadGestures();
	//for each gesture we have to insert in a verctor gestures it's object, set it's name and load data
	it = gestures.begin();
	for (int i = 0; i < rd.getGesturesNumber(); i++){
		gestureSet newGesture;
		newGesture.setName(rd.gestures.at(i));
		newGesture.load();
		it = gestures.insert(it, newGesture);
	}
}

std::string gestureClassifier::classifyGesture(std::array <emgSet, WINDOW_DIM> sample){
	int64_t bestMatch = 0;
	int64_t currentMatch = 0;
	int g = 0; //index of best gesture match
	for (int i = 0; i < rd.getGesturesNumber(); i++){
		currentMatch = gestures.at(i).checkMatch(sample);
		if (bestMatch < currentMatch){
			bestMatch = currentMatch;
			g = i;
		}
	}
	return rd.gestures.at(g);
}

int gestureClassifier::classifyGestureNum(std::array <emgSet, WINDOW_DIM> sample)
{
	int64_t bestMatch = 0;
	int64_t currentMatch = 0;
	int g = 0; //index of best gesture match
	for (int i = 0; i < rd.getGesturesNumber(); i++){
		currentMatch = gestures.at(i).checkMatch(sample);
		if (bestMatch < currentMatch){
			bestMatch = currentMatch;
			g = i;
		}
	}
	return g;
}

std::string gestureClassifier::getGestureString(int gest)
{
	return rd.gestures.at(gest);
}


