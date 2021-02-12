#include<stdio.h>
#include<stdlib.h>

struct Stack
{
	int size;
	int top;
	int *s;
};

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
	if(st->top==-1)
	{
		printf("Stack Underflow");
	}
	else
	{
		return st->s[st->top--];
	}
}

int isEmpty(struct Stack st)
{
	if(st.top==-1)
		return 1;
	return 0;
}

int isOperand(char x)
{
	if(x=='+' || x=='-' || x=='*' || x=='/')
		return 0;
	return 1;
}

int precedence(char x)
{
	if(x=='+' || x=='-')
		return 1;
	else if(x=='*' || x=='/')
		return 2;
	return 0;
}

int stackTop(struct Stack st)
{
	if(st.top!=-1)
	{
		return st.s[st.top];
	}
}

char *postfix(char *infix)
{
	char *postfix;
	int i=0,j=0;
	struct Stack st;
	st.size = 20;
	st.top = -1;
	st.s = (int *)malloc(st.size*sizeof(int));
	postfix = (char *)malloc(st.size*sizeof(char)+1);
	while(infix[i]!='\0')
	{
		if(isOperand(infix[i]))
		{
			postfix[j++] = infix[i++];
		}
		else
		{
			if(precedence(infix[i])>precedence(stackTop(st)))
			{
				push(&st, infix[i++]);
			}
			else
			{
				postfix[j++] = pop(&st);
			}
		}
	}
	while(!isEmpty(st))
	{
		postfix[j++] = pop(&st);
	}
	postfix[j] = '\0';
	return postfix;
}

int main()
{
	char *infix = "a+b*c+d";
	printf("postfix expression = %s",postfix(infix));
	return 0;
}
