#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x)
{
	struct Node *temp;
	temp = (struct Node *)malloc(sizeof(struct Node));
	if(temp==NULL)
	{
		printf("Queue is full!\n");
	}
	else
	{
	
		temp->data = x;
		temp->next = NULL;
		if(front==NULL)
		{
			front = rear = temp;
		}
		else
		{
			rear->next = temp;
			rear = temp;
		}
	}
}

int dequeue()
{
	int x = -1;
	struct Node *p;
	p = front;
	if(front==NULL)
	{
		printf("Queue is empty!\n");
	}
	else
	{
		front = front->next;
		x = p->data;
		free(p);
	}
	return x;
}

void display()
{
	struct Node *p = front;
	while(p!=rear->next)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	enqueue(60);
	
	display();
	
	dequeue();
	dequeue();
	
	display();
	return 0;
}
