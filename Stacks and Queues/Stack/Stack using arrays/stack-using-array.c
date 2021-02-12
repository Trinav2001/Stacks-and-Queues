#include<stdio.h>
#include<stdlib.h>

struct Stack
{
	int size;
	int top;
	int *s;
};

void create(struct Stack *st)
{
	printf("Enter size of the stack ");
	scanf("%d", &st->size);
	st->top = -1;
	st->s = (int *)malloc(st->size*sizeof(int));
}

void display(struct Stack st)
{
	int i;
	for(i=st.top;i>=0;i--)
	{
		printf("%d ", st.s[i]);
	}
	printf("\n");
}

void push(struct Stack *st, int x)
{
	if(st->top==st->size-1)
	{
		printf("Stack Overflow");
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
		printf("Stack Underflow");
		return -1;
	}
	else
	{
		x = st->s[st->top];
		st->top--;
	}
	return x;
}

int peek(struct Stack st, int pos)
{
	int x = -1;
	if(st.top-pos+1<0)
	{
		printf("Invalid index\n");
	}
	else
	{
		x = st.s[st.top-pos+1];
	}
	return x;
}

int stackTop(struct Stack st)
{
	if(st.top==-1)
	{
		return -1;
	}
	else
	{
		return st.s[st.top];
	}
}

int isEmpty(struct Stack st)
{
	if(st.top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isFull(struct Stack st)
{
	if(st.top==st.size-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	struct Stack st;
	create(&st);
	
	push(&st,2);
	push(&st,5);
	push(&st,8);
	push(&st,10);
	push(&st,12);
	display(st);
	printf("\n%d\n\n",pop(&st));
	display(st);
	return 0;
}
