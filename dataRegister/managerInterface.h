#ifndef MANAGERINTERFACE_H
#define MANAGERINTERFACE_H

#include <string>
#include <iostream>
#include <qstring.h>

class managerInterface
{
public:
	managerInterface(){}
	virtual ~managerInterface(){}
	virtual void read() = 0;
	virtual QString getFrameData(int frame) = 0;
	virtual void start() = 0;
	virtual void stop() = 0;
};

#endif //MANAGERINTERFACE_H