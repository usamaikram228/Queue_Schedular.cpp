#ifndef PROCESS_H
#define PROCESS_H
#include<iostream>
class Process
{
public:
	int processId;
	string processName;
	int executionTime;
	Process(int = 0, string = "", int = 0);
	void display();
	Process operator=(const Process&);

};
#endif