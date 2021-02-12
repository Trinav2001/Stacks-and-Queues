#include<iostream>
using namespace std;
class Queue
{
	private:
		int front;
		int rear;
		int size;
		int *q;
	public:
		Queue(int size)
		{
			front=rear=-1;
			this->size = size;
			q = new int[this->size];
		}
		void enqueue(int x);
		int dequeue();
		void display();
};

void Queue :: enqueue(int x)
{
	if(rear==size-1)
	{
		cout<<"Queue is Full!\n";
	}
	else
	{
		rear++;
		q[rear] = x;
	}
}

int Queue :: dequeue()
{
	int x = -1;
	if(front==rear)
	{
		cout<<"Queue is empty\n";
	}
	else
	{
		front++;
		x = q[front];
	}
	return x;
}

void Queue :: display()
{
	int i;
	for(i=front+1;i<=rear;i++)
	{
		cout<<q[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	Queue Q(5);
	Q.enqueue(10);
	Q.enqueue(20);
	Q.enqueue(30);
	Q.enqueue(40);
	Q.display();
	cout<<Q.dequeue()<<"\n";
	cout<<Q.dequeue()<<"\n";
	cout<<Q.dequeue()<<"\n";
	cout<<Q.dequeue()<<"\n";
	cout<<Q.dequeue()<<"\n";
	Q.display();
	return 0;
}
