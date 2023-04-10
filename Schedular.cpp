#include<iostream>
#include"Schedular.h"
#include"Process.h"
#include"Queue.h"
using namespace std;
int Schedular::getQuantumTime()
{
	return timeQuantum;
}
void Schedular:: assignProcessor()
{
	
	Queue<Process> a(4);
	for (int i = 0; i < processArrayLength; i++)
	{
		a.enQueue(processArray[i]);
	}
	int i = 0;
	int unitTime = 0;
	while (!a.isEmpty())
	{
		unitTime = 1;
		while (unitTime <= 10 && unitTime <= timeQuantum)
		{
			unitTime++;
			/*processArray[i].executionTime--;*/
			if (unitTime == timeQuantum)
			{
				if (processArray[i].executionTime > timeQuantum)
				{
					processArray[i].executionTime -= timeQuantum;
					Process temp = a.deQueue();
					a.enQueue(temp);
					break;
				}
				else
				{
					Process temp = a.deQueue();
					cout << "This process has completed its Execution : " << endl;
					temp.display();
					break;
				}
			}
		}
		if (unitTime == 10)
		{
			//processArray[i].executionTime -= timeQuantum;
			if (processArray[i].executionTime > unitTime)
			{
				processArray[i].executionTime -= unitTime;
				Process temp = a.deQueue();
				a.enQueue(temp);
			}
			else
			{
				Process Temp = a.deQueue();
				cout << "This process has completed : " << endl;
				Temp.display();
			}

		}
	}
}