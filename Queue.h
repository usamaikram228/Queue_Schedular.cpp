#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
using namespace std;
template <class T>
class Queue
{
private:
	T* queue;
	int size;
	int front;
	int rear;
	int noOfelements;
	void reSize();
public:
	Queue(int);
	~Queue();
	void enQueue(T);
	T deQueue();
	bool isFull();
	void display();
	bool isEmpty();
	Queue operator =(const Queue&);
};
template<class T>
Queue<T>::Queue(int s)
{
	size = s;
	queue = new T[size];
	front = -1;
	rear = -1;
	noOfelements = 0;
}
template<class T>
Queue<T>::~Queue()
{
	if (queue != nullptr)
	{
		delete[] queue;
		queue = nullptr;
	}
}
template<class T>
void Queue<T>::enQueue(T val)
{
	if (isFull())
	{
		reSize();
		rear = (rear + 1) % size;
		queue[rear] = val;
		noOfelements++;
	}
	else
	{
		rear = (rear + 1) % size;
		cout << rear << " ";
		queue[rear] = val;
		noOfelements++;
	}
}
template<class T>
void Queue<T>:: display()
{
	for (int i = front+1; i <= rear; i++)
	{
		cout << queue[i] << " ";
	}
}
template<class T>
bool Queue<T>::isFull()
{
	if (rear == size - 1 && noOfelements == size)
		return true;
	else
		return false;
}
template<class T>
void Queue<T>::reSize()
{
	//cout << "Resize Called";
	int newSize = size * 2;
	T* temp = new T[newSize];
	for (int i = front+1; i <=rear ; i++)
	{
		temp[i] = queue[i];
	}
	delete[] queue;
	queue = temp;
	size = size * 2;
}
template<class T>
bool Queue<T>::isEmpty()
{
	if (front == rear && noOfelements == 0)
	{
		return true;
	}
	else
		return false;
}
template<class T>
T Queue<T>::deQueue()
{
	if (isEmpty())
	{
		cout << "Queue is empty" << endl;
		exit(0);
	}
	else
	{
		front = (front + 1) % size;
		noOfelements--;
		return queue[front];
	}
}
template<class T>
Queue<T> Queue<T>::operator = (const Queue<T>& q)
{
	if (!q.queue)
		return *this;
	queue = new T[q.size];
	int j = q.front;
	for (int i = 0; i < q.noOfelements; i++)
	{
		queue[j] = q.queue[j];
		j = (j + 1) % q.queue;
	}
	noOfelements = q.noOfelements;
	size = q.size;
	front = q.front;
	rear = q.rear;


	return *this;
}
#endif