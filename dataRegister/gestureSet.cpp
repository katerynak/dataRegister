#include "gestureSet.h"
#include <iostream>

gestureSet::gestureSet()
{
}


gestureSet::~gestureSet()
{
}

void gestureSet::load(){
	std::string currentDataFileName = name + ".csv";
	std::fstream currentDataFile;
	std::string buffer = "vanAnto";
	std::string bufferNum = "";
	int count = 0;
	currentDataFile.open(currentDataFileName);
	if (currentDataFile.is_open()){
		getline(currentDataFile, buffer, '\n');
		getline(currentDataFile, buffer, '\n');
		for (int i = 0;; i++){

			if (currentDataFile.eof()) break;
			if (samplesNumber >= TRAIN_GESTURES_NUM) break;
			if (i == MAX_FRAMES){
				//SALTO DUE RIGHE
				getline(currentDataFile, buffer, '\n');
				getline(currentDataFile, buffer, '\n');
				i = 0;
			}
			//	getline(currentDataFile, buffer, '\n');
			//	std::istringstream csvStream(buffer);
			for (int j = 0; j < 7; j++){
				getline(currentDataFile, bufferNum, ',');
				//bufferNum = "13";
				gestureData.at(samplesNumber).at(j) = std::stoi(bufferNum);
				//std::cout << static_cast<int>(gestureData.at(samplesNumber).at(j)) << " ";
			}
			getline(currentDataFile, bufferNum, '\n');
			//bufferNum = "13";
			gestureData.at(samplesNumber).at(7) = std::stoi(bufferNum);
		//	std::cout << static_cast<int>(gestureData.at(samplesNumber).at(7)) << " ";
		//	std::cout << " line "<<samplesNumber<<"\n ";
			samplesNumber++;
		}
		currentDataFile.close();
	}
}

//this function returns the max match of the sample with this function
int64_t gestureSet::checkMatch(std::array<emgSet, WINDOW_DIM> sample)
{
	int64_t ret = 0;
	int64_t conv = 0;
	int64_t sum_conv = 0;
	int32_t prod = 1;
	for (int i = 0; i < samplesNumber - 8; i++){ //index of first element
		sum_conv = 0;
		for (int j = 0; j < 8; j++){ //searching matches for all sensor sequences
			conv = 0;
			for (int s = 0; s < WINDOW_DIM; s++){
				//sample.at(s).at(j)*gestureData.at(i + s).at(j);
				prod = sample.at(WINDOW_DIM-s-1).at(j)*gestureData.at(i + s).at(j);
				conv += prod;
			}
			sum_conv += conv;
		}
		if (ret < sum_conv) ret = sum_conv;
	}
	return sum_conv;
}