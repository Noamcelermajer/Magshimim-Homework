#pragma once
typedef struct node
{
	int _data;
	struct node* _next;
}node;
int isItEmpty(struct node* head);
void init(node* head);
node* push(struct node* head, int data);
node* pop(struct node *s, int *data);
