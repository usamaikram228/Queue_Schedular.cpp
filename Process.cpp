#include<iostream>
#include"Process.h"
using namespace std;
Process::Process(int a ,string b, int e)
{
	processId = a;
	processName = b;
	executionTime = e;
}
void Process:: display()
{
	cout << "ProcessID : " << processId << endl;
	cout << "ProcessName : " << processName << endl;
	cout << "ExecutionTime : " << executionTime << endl;
}
Process Process:: operator=(const Process& p)
{
	processId = p.processId;
	processName = p.processName;
	executionTime = p.executionTime;
}
//void Process::setProcessId(int a)
//{
//	processId = a;
//}
//void Process::setProcessName(const char* s)
//{
//	strcpy(processName, s);
//}
//void Process::setExecutionTime(int a)
//{
//	executionTime = a;
//}
//int Process::getProcessId()
//{
//	return processId;
//}
//const char* Process:: getProcessName()
//{
//	return processName;
//}
//int Process::getExecutionTime()
//{
//	return executionTime;
//}