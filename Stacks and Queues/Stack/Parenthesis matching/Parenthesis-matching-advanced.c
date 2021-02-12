#include<stdio.h>
#include<stdlib.h>

struct Stack
{
	int size;
	int top;
	char *s;
};

void push(struct Stack *st, char x)
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

void pop(struct Stack *st)
{
	if(st->top==-1)
	{
		printf("Stack Underflow\n");
	}
	else
	{
		--st->top;
	}
}

int stackTop(struct Stack *st)
{
	if(st->top!=-1)
	{
		return st->s[st->top];
	}
	return -1;
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

int isBalanced(char *exp)
{
	int i;
	struct Stack st;
	st.top = -1;
	st.s = (char *)malloc(20*sizeof(char));
	for(i=0;exp[i]!='\0';i++)
	{
		if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
		{
			push(&st,exp[i]);
		}
		else if(!(exp[i]==')' || exp[i]=='}' || exp[i] == ']'))
		{
			continue;
		}
		else if(exp[i]==')' || exp[i]=='}' || exp[i] == ']')
		{
			if((exp[i]-stackTop(&st)==1 || exp[i]-stackTop(&st)==2))
			{
				pop(&st);
			}
			else
			{
				return 0;
			}
		}
		
	}
	if(isEmpty(st))
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
	char *exp = "[(a+b)]({})()";
	printf("%d",isBalanced(exp));
	return 0;
}
