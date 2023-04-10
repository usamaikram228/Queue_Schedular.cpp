#ifndef SCHEDULAR_H
#define SCHEDULAR_H
#include"Process.h"
class Schedular
{
	Process* processArray;
	int processArrayLength;
	int timeQuantum;
public:
	Schedular(Process* p, int length, int quantum)
	{
		processArray = p;
		processArrayLength = length;
		timeQuantum = quantum;
	}
	int getQuantumTime();
	void assignProcessor();

};
#endif
