#include<iostream>
using namespace std;

class Stack
{
	private :
		int size;
		int top;
		int *s;
	public:
		Stack(int size)
		{
			this->size = size;
			top = -1;
			s = new int[this->size];
		}
		void push(int x);
		int pop();
		int peek(int pos);
		int stackTop();
		int isEmpty();
		int isFull();
		void display();
};

void Stack :: push(int x)
{
	if(top==size-1)
	{
		cout<<"Stack Overflow";
	}
	else
	{
		s[++top] = x;
	}
}

int Stack :: pop()
{
	int x = -1;
	if(top==-1)
	{
		cout<<"Stack Underflow";
		return x;
	}
	else
	{
		x = s[top--];
		return x;
	}
}

int Stack :: peek(int pos)
{
	int x = -1;
	if(top-pos+1<0)
	{
		cout<<("Invalid position");
		return x;
	}
	else
	{
		x = s[top-pos+1];
		return x;
	}
}

int Stack :: stackTop()
{
	if(top==-1)
	{
		cout<<"Stack Underflow";
		return -1;
	}
	else
	{
		return s[top];
	}
}

int Stack :: isEmpty()
{
	if(top==-1)
	{
		return 1;
	}
	return 0;
}

int Stack :: isFull()
{
	if(top==size-1)
	{
		return 1;
	}
	return 0;
}

void Stack :: display()
{
	int i;
	for(i=top;i>=0;i--)
	{
		cout<<s[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	Stack st(5);
	st.push(2);
	st.push(4);
	st.push(6);
	st.push(8);
	st.push(12);
	st.display();
	printf("\n%d\n\n", st.pop());
	st.display();
	return 0;
}
