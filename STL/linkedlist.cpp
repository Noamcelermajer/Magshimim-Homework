#include "linkedlist.h"
void init(node* head)
{
	head = nullptr;
}
node* pop(node* head,int *num)//put the value in element without need to return the element the fucntion return the new head with the next element instead of the poped one
{
	*num = head->_data;
	head = head->_next;
	return head;
}
node* push(node* head, int num)
{
	node* tmp = new node;
	tmp->_data = num;
	tmp->_next = head;
	head = tmp;
	return head;
}
int empty(struct node* head)
{
	return head == nullptr ? 1 : 0;
}
