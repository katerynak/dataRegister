#include "myoManager.h"

void myoManager::print(){
	// Clear the current line
	std::cout << '\r';

	// Print out the EMG data.
	// for (size_t i = 0; i < emgSamples.size(); i++) {
	std::ostringstream oss;
	//  oss << static_cast<int>(emgSamples[i]);
	std::string emgString = oss.str();
	//   std::cout << '[' << emgString << std::string(4 - emgString.size(), ' ') << ']';
	std::cout << gesture << " " << recognisedGesture;
	std::cout << std::flush;
}

void myoManager::run(){
	// We catch any exceptions that might occur below -- see the catch statement for more details.
	/*Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	dataRegister::mainWindow form;
	Application::Run(%form);*/
	try {

		// First, we create a Hub with our application identifier. Be sure not to use the com.example namespace when
		// publishing your application. The Hub provides access to one or more Myos.
		hub = new myo::Hub("com.example.emg-data-sample");

		std::cout << "Attempting to find a Myo..." << std::endl;

		// Next, we attempt to find a Myo to use. If a Myo is already paired in Myo Connect, this will return that Myo
		// immediately.
		// waitForMyo() takes a timeout value in milliseconds. In this case we will try to find a Myo for 10 seconds, and
		// if that fails, the function will return a null pointer.
		myo::Myo* myo = hub->waitForMyo(10000);

		// If waitForMyo() returned a null pointer, we failed to find a Myo, so exit with an error message.
		if (!myo) {
			throw std::runtime_error("Unable to find a Myo!");
		}

		// We've found a Myo.
		std::cout << "Connected to a Myo armband!" << std::endl << std::endl;

		// Next we enable EMG streaming on the found Myo.
		myo->setStreamEmg(myo::Myo::streamEmgEnabled);

		// Next we construct an instance of our DeviceListener, so that we can register it with the Hub.
		collector = new myoManager(rd, qRecognizedGesture);
		
		// Hub::addListener() takes the address of any object whose class inherits from DeviceListener, and will cause
		// Hub::run() to send events to all registered device listeners.
		hub->addListener(collector);
		while (1) {
			hub->run(1000 / 20);
			// After processing events, we call the print() member function we defined above to print out the values we've
			// obtained from any events that have occurred.
			collector->print();
		}

		// If a standard exception occurred, we print out its message and exit.
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		std::cerr << "Press enter to continue.";
		std::cin.ignore();
		return;
	}
}

void myoManager::update(){
	try {
		hub->run(1000 / 20);
		// After processing events, we call the print() member function we defined above to print out the values we've
		// obtained from any events that have occurred.
		collector->print();
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		std::cerr << "Press enter to continue.";
		std::cin.ignore();
		return;
	}

}

int8_t myoManager::getMean(std::array<int8_t, N> values){
	int8_t sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += values[i];
	}
	return sum / N;
}

int8_t myoManager::getVariance(std::array<int8_t, N> values, int8_t mean)
{
	int8_t sum = 0;
	int8_t variance;
	for (int i = 0; i < N; i++)
	{
		sum += pow(values[i] - mean, 2);
	}
	variance = sum / N;
	return variance;
}

//assuming values are positive
int8_t myoManager::getMax(std::array<int8_t, 8> values, int num){
	int8_t max = 0;
	for (int i = 0; i < num; i++)
	{
		if (values[i]>max) max = values[i];
	}
	return max;
}

std::array<int8_t, N> myoManager::getColumn(std::array<std::array<int8_t, 8>, N> emgSet, int col){
	std::array<int8_t, N> ret;
	for (int i = 0; i < N; i++){
		ret[i] = emgSet[i][col];
	}
	return ret;
}
int lastGestures[LASTN];

int gest = 0;
int counter = 0;


// onUnpair() is called whenever the Myo is disconnected from Myo Connect by the user.
void myoManager::onUnpair(myo::Myo* myo, uint64_t timestamp)
{
	// We've lost a Myo.
	// Let's clean up some leftover state.
	emgSamples.fill(0);
	roll_w = 0;
	pitch_w = 0;
	yaw_w = 0;
	onArm = false;
	isUnlocked = false;
}

// onEmgData() is called whenever a paired Myo has provided new EMG data, and EMG streaming is enabled.
void myoManager::onEmgData(myo::Myo* myo, uint64_t timestamp, const int8_t* emg)
{
		for (int i = 0; i < 8; i++) {
			emgSamples[i] = emg[i];
			emgSet[counter][i] = emg[i];
			// da aggiungere in questo punto se sto effettivamente facendo una registrazione
			if (emgRegCounter < MYO_FRAMES){
				rd->emgRegSet[emgRegCounter][i] = static_cast<int>(emg[i]);
			}
		}

		//sposto i dati della finestra scorrevole e aggiungo la new entry dopo
		for (int i = BUFFER_MAX - 1; i>0; i--){
			lastSamples.at(i) = lastSamples.at(i - 1);
		}
		lastSamples.at(0) = emgSamples;
		for (int i = 0; i < WINDOW_DIM; i++){
			lastWindow.at(WINDOW_DIM-i-1) = lastSamples.at(i); //like the registered data is memorized
		}
		for (int i = NWINDOWS-1; i >0; i--){
			lastGests[i] = lastGests[i - 1];
		}
		lastGests[0] = gestureClass.classifyGestureNum(lastWindow);
		int gestCount[MAX_GEST];
		for (int i = 0; i < MAX_GEST; i++){
			gestCount[i] = 0;
		}
		for (int i = 0; i < NWINDOWS; i++){
			if (lastGests[i]>0)
				gestCount[lastGests[i]]++;
		}
		int g=0;
		int max = 0;
		for (int i = 0; i < MAX_GEST; i++){
			if (max < gestCount[i]){ max = gestCount[i]; 
			g = i;
			}
		}
		//recognisedGesture = gestureClass.getGestureString(g);
		/*if (qRecognizedGesture != NULL){
			qRecognizedGesture->clear();
			qRecognizedGesture->append(QString::fromUtf8(recognisedGesture.c_str()));
		}*/

		if (emgRegCounter < MYO_FRAMES)
			emgRegCounter++;
		counter++;
		if (counter == N){
			counter = 0;
			//per ogni sensore seleziono ultimi N campioni
			for (int i = 0; i < 8; i++){
				std::array<int8_t, N> semg = getColumn(emgSet, i);
				variances[i] = getVariance(semg, getMean(semg));
			}
			if (getMax(variances, 8)>18){
				gest = 1;
			}
			else
			{
				gest = 0;
			}
			/*salvo in memoria gli ultimi lastn risultati*/
			for (int i = LASTN - 1; i > 0; i--){
				lastGestures[i] = lastGestures[i - 1];
			}
			lastGestures[0] = gest;
			gesture = "open";
			gest = 0;
			for (int i = 0; i < LASTN; i++){
				if (lastGestures[i] == 1) {
					gesture = "close";
					gest = 1;
				}
			}
		}
}

void myoManager::onOrientationData(myo::Myo *myo, uint64_t timestamp, const myo::Quaternion< float > &rotation)
{

	using std::atan2;
	using std::asin;
	using std::sqrt;
	using std::max;
	using std::min;

	// Calculate Euler angles (roll, pitch, and yaw) from the unit quaternion.
	rd->roll = atan2(2.0f * (rotation.w() * rotation.x() + rotation.y() * rotation.z()),
	1.0f - 2.0f * (rotation.x() * rotation.x() + rotation.y() * rotation.y()));
	rd->pitch = asin(max(-1.0f, min(	1.0f, 2.0f * (rotation.w() * rotation.y() - rotation.z() * rotation.x()))));
	rd->yaw = atan2(2.0f * (rotation.w() * rotation.z() + rotation.x() * rotation.y()),
	1.0f - 2.0f * (rotation.y() * rotation.y() + rotation.z() * rotation.z()));

	//we'll use a treshold value 2 to detect the position of the hand
	if (rd->pitch > 0)
		rd->currentAngle = 1;
	else rd->currentAngle = 0;

}


void myoManager::onAccelerometerData(myo::Myo *myo, uint64_t timestamp, const myo::Vector3< float > &accel)
{
	/*
	printVector(accelerometerFile, timestamp, accel);
	*/
}
void myoManager::onGyroscopeData(myo::Myo *myo, uint64_t timestamp, const myo::Vector3< float > &gyro)
{
	/*
	printVector(gyroFile, timestamp, gyro);
	*/
	/*rd->gyrodata.clear();
	rd->gyrodata.append(gyro.normalized);*/
	rd->gyro = gyro;
//	float ics = gyro.x();
//	 qDebug() << ics;
}
void myoManager::onConnect(myo::Myo *myo, uint64_t timestamp, myo::FirmwareVersion firmwareVersion)
{
	/*
	//Reneable streaming
	myo->setStreamEmg(myo::Myo::streamEmgEnabled);
	openFiles();
	*/
}

int myoManager::getGesture(){
	return gest;
}

myoManager::~myoManager()
{
}

void myoManager::read()
{
	//if (recording){
		hub->run(1000 / 20);
		// After processing events, we call the print() member function we defined above to print out the values we've
		// obtained from any events that have occurred.
		//collector->print();
	//}
		if (rd->recording){
			if (rd->counter < RECORDING_DIM){
				rd->recordGestures[rd->counter] = QString::fromUtf8(recognisedGesture.c_str());
				rd->angles[rd->counter] = rd->currentAngle;
				rd->counter++;
			}
		}
}

//quasi quasi non da usare perchè non ha senso in questo contesto 
QString myoManager::getFrameData(int frame){
	if (frame < rd->counter)
		return rd->recordGestures[frame];
	return "";
}

QString myoManager::getPositionFrameData(int frame){
	QString ret = "";
	if (frame < rd->counter){
		if (rd->angles[frame] == 0) ret += "Down";
		else if (rd->angles[frame] == 1) ret += "Up";
	}
	return ret;
}


void myoManager::start()
{
		try {
			emgRegCounter = 0;
			// First, we create a Hub with our application identifier. Be sure not to use the com.example namespace when
			// publishing your application. The Hub provides access to one or more Myos.
			hub = new myo::Hub("com.example.emg-data-sample");

			std::cout << "Attempting to find a Myo..." << std::endl;

			// Next, we attempt to find a Myo to use. If a Myo is already paired in Myo Connect, this will return that Myo
			// immediately.
			// waitForMyo() takes a timeout value in milliseconds. In this case we will try to find a Myo for 10 seconds, and
			// if that fails, the function will return a null pointer.
			myo::Myo* myo = hub->waitForMyo(10000);

			// If waitForMyo() returned a null pointer, we failed to find a Myo, so exit with an error message.
			if (!myo) {
				throw std::runtime_error("Unable to find a Myo!");
			}

			// We've found a Myo.
			std::cout << "Connected to a Myo armband!" << std::endl << std::endl;

			// Next we enable EMG streaming on the found Myo.
			myo->setStreamEmg(myo::Myo::streamEmgEnabled);

			// Next we construct an instance of our DeviceListener, so that we can register it with the Hub.
			collector = new myoManager(rd, qRecognizedGesture);

			// Hub::addListener() takes the address of any object whose class inherits from DeviceListener, and will cause
			// Hub::run() to send events to all registered device listeners.
			hub->addListener(collector);
			recording = true;

			// If a standard exception occurred, we print out its message and exit.
		}
		catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
			std::cerr << "Press enter to continue.";
			std::cin.ignore();
			return;
		}
}

void myoManager::stop()
{
	recording = false;
}

QString myoManager::getRecognisedGesture(){
	return QString::fromUtf8(recognisedGesture.c_str());
}

void  myoManager::startRecording(){
	rd->recording = true;
	rd->counter = 0;
}
void  myoManager::stopRecording(){
	rd->recording = false;
}

void myoManager::onPose(myo::Myo* myo, uint64_t timestamp, myo::Pose pose)
{
//	currentPose = pose;
	if (pose != myo::Pose::unknown)
	{
		//std::cout << "gesto riconosciuto" << std::endl;
		qDebug() << QString::fromUtf8(pose.toString().c_str());
	}

	if (pose != myo::Pose::unknown && pose != myo::Pose::rest) {
		// Tell the Myo to stay unlocked until told otherwise. We do that here so you can hold the poses without the
		// Myo becoming locked.
		myo->unlock(myo::Myo::unlockHold);

		// Notify the Myo that the pose has resulted in an action, in this case changing
		// the text on the screen. The Myo will vibrate.
		myo->notifyUserAction();
	}
	else {
		// Tell the Myo to stay unlocked only for a short period. This allows the Myo to stay unlocked while poses
		// are being performed, but lock after inactivity.
		myo->unlock(myo::Myo::unlockTimed);
	}

	recognisedGesture = pose.toString();
	if (qRecognizedGesture != NULL){
		qRecognizedGesture->clear();
		qRecognizedGesture->append(QString::fromUtf8(recognisedGesture.c_str()));
	}
}

// onArmSync() is called whenever Myo has recognized a Sync Gesture after someone has put it on their
// arm. This lets Myo know which arm it's on and which way it's facing.
void myoManager::onArmSync(myo::Myo* myo, uint64_t timestamp, myo::Arm arm, myo::XDirection xDirection, float rotation,
	myo::WarmupState warmupState)
{
	onArm = true;
	whichArm = arm;
}

// onArmUnsync() is called whenever Myo has detected that it was moved from a stable position on a person's arm after
// it recognized the arm. Typically this happens when someone takes Myo off of their arm, but it can also happen
// when Myo is moved around on the arm.
void myoManager::onArmUnsync(myo::Myo* myo, uint64_t timestamp)
{
	onArm = false;
}

void myoManager::onUnlock(myo::Myo* myo, uint64_t timestamp)
{
	isUnlocked = true;
}

// onLock() is called whenever Myo has become locked. No pose events will be sent until the Myo is unlocked again.
void myoManager::onLock(myo::Myo* myo, uint64_t timestamp)
{
	isUnlocked = false;
}