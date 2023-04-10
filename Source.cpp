#include<iostream>
#include"Process.h"
#include"Queue.h"
#include"Schedular.h"
using namespace std;

int main()
{
	Process arr[3] = { {1,"notepad",20 }, {13, "mp3", 5}, {4, "bes", 32} };
	Schedular s(arr, 3, 5);
	s.assignProcessor();
	return 0;
}