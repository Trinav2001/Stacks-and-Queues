#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
};

class Stack 
{
	private:
		Node *top;
	public:
		Stack()
		{
			top = NULL;
		}
		void push(int x);
		int pop();
		void display();
};

void Stack :: push(int x)
{
	Node *temp;
	temp = new Node;
	if(temp==NULL)
	{
		cout<<("Stack Overflow\n");
	}
	else
	{
		temp->data = x;
		temp->next = top;
		top = temp;
	}
}

int Stack :: pop()
{
	Node *p;
	int x = -1;
	if(top==NULL)
	{
		cout<<("Stack Underflow\n");
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

void Stack :: display()
{
	Node *p = top;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
}

int main()
{
	Stack st;
	st.push(2);
	st.push(4);
	st.push(5);
	st.push(10);
	st.display();
	cout<<st.pop()<<" "<<st.pop()<<endl;
	st.display();
	return 0;
}
