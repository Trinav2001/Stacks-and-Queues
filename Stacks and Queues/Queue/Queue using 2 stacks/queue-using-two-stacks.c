#include<stdio.h>
#include<stdlib.h>

struct Stack
{
	int top;
	int size;
	int *s;
};

struct Queue
{
	Stack s1,s2;
};

void insert(int x)
{
	push(&s1,x);

int Delete()
{
	int x = -1,y;
	if(isEmpty(s2))
	{
		if(isEmpty(s1))
		{
			printf("Queue is empty\n");
			return x;
		}
		else
		{
			while(!isEmpty(s1))
			{	
				y = pop(&s1);
				push(&s2,y);
			}
		}
	}
	x = pop(&s2);
	return x;
}

int isEmpty(struct Stack st)
{
	if(st.top==-1)
		return 1;
	return 0;
}

void push(struct Stack *st, int x)
{
	if(st->top==st->size-1)
	{
		printf("Stack is full\n");
	}
	else
	{
		st->top++;
		st->s[st->top] = x;
	}
}

int pop(struct Stack *st)
{
	int x = -1;
	if(st->top==-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		x = st->s[st->top];
		st->top--;			
	}
	return x;
}

void Display(struct Stack st)
{
	int i;
	if(st.top==-1)
	{
		printf("\nQueue is empty\n");
	}
	for(i=st.top;i>=0;i--)
	{
		printf("%d ",st.s[i]);
	}
	printf("\n");
}

int main()
{
	struct Stack s1,s2;
	s1.top = -1;
	s1.size = 5;
	s1.s = (int *)malloc(s1.size*sizeof(int));
	s2.top = -1;
	s2.size = 5;
	s2.s = (int *)malloc(s2.size*sizeof(int));
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	Display(s1);
	Display(s2);
	printf("\n%d ",Delete());
	return 0;
}
