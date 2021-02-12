#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*top=NULL;

void push(int x)
{
	struct Node *temp;
	temp = (struct Node *)malloc(sizeof(struct Node));
	if(temp==NULL)
	{
		printf("Stack Overflow\n");
	}
	else
	{
		temp->data = x;
		temp->next = top;
		top = temp;
	}	
}

int pop()
{
	int x = -1;
	struct Node *p;
	if(top==NULL)
	{
		printf("Stack Underflow\n");
	}
	else
	{
		p = top;
		top = top->next;
		x = p->data;
		free(p);
	}
	return x;
}

void display()
{
	struct Node *p = top;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n\n");
}

int main()
{
	push(2);
	push(3);
	push(5);
	push(10);
	display();
	printf("%d\n\n",pop());
	display();
	return 0;
}
