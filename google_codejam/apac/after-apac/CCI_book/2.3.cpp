#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node * next;
};
node * insert(node * head, int d)
{
	node * my_node = new node;
	my_node->data = d;
	my_node->next = NULL;
	if(head == NULL)
	{
		return my_node;
	}
	else
	{
		node * curr = head;
		while(curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = my_node;
		return head;
	}
}
void print_list(node * head)
{
	if(head == NULL)
	{
		return;
	}
	node * curr = head;
	while(curr != NULL)
	{
		cout << curr->data << " -> ";
		curr = curr->next;
	}
	cout << "NULL" << endl;
}

void delete_a_node(node * to_delete) //my solution, pretty bad O(n), I didn't even handle if to_delete itself was NULL
{
	node * curr = to_delete;
	node * prev = to_delete;
	while(curr->next != NULL)
	{
		curr->data = curr->next->data;
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
}

bool delete_a_node_2(node * to_delete) //good, O(1) solution
{
	if(to_delete == NULL || to_delete->next == NULL) //if to_delete is NULL or is the last node, we can't do anything.
	{
		return false;
	}
	else
	{
		node * curr = to_delete;
		curr->data = curr->next->data;
		curr->next = curr->next->next;
		return true;
	}
}

int main()
{
	node * head = NULL;
	head = insert(head,1);
	head = insert(head,2);
	head = insert(head,5);
	head = insert(head,8);
	head = insert(head,2);
	head = insert(head,1);
	head = insert(head,7);
	head = insert(head,9);
	print_list(head);
	delete_a_node(head->next->next->next);
	delete_a_node_2(head->next->next->next);
	print_list(head);
	return 0;
}
