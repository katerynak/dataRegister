#ifndef CONSTANTS_H
#define CONSTANTS_H

#define MAX_FRAMES 200
#define MYO_PER_FRAME 1
#define ARDUINO_PER_FRAME 1
#define MYO_FRAMES MYO_PER_FRAME*MAX_FRAMES
#define TRAIN_GESTURES_NUM 400 //max 400 emg recording are evaluated for each gesture 
//buffer dimension = sequence of values to evaluate as recognized gesture
#define WINDOW_DIM 8 
#define MAX_GEST 10
#define GESTURES_FILE_NAME "gestures.txt"

//comment this line if using normal webcam
//#define USE_LEAPCAM

#define RECORDING_DIM 200 //number of frames per recording

enum MSTATES{ON, OFF, REGISTER, WAIT};

#endif //CONSTANTS_H