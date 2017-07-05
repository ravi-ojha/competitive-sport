#include <bits/stdc++.h>
using namespace std;

//We implement stack using a linked list
struct node
{
	int data;
	node * next;
};

//top of the stack
node * top = NULL;

node * new_node(int d)
{
	node * my_node = new node;
	my_node->data = d;
	my_node->next = NULL;
	return my_node;
}

//In stack we always push and pop from one end
//Pushing and Deleting (pop) is easy from the front in linked list
void push(int d)
{
	node * tmp = new_node(d);
	tmp->next = top;
	top = tmp;
}

int pop()
{
	if(top != NULL)
	{
		int tmp = top->data;
		top = top->next;
		return tmp;
	}
	return NULL;
}

int top()
{
	return top->data;
}

int main()
{
	return 0;
}
