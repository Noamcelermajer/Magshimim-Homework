#include "stack.h"
#include "utils.h"
stack *top = nullptr;

bool isempty()
{
	return(top == nullptr);
}

void initStack(stack* s)
{
	s = nullptr;
}
void cleanStack(stack* s)
{
	delete[] s;
}

void push(stack* s, unsigned int element)
{
	s = new stack;
	s->data = element;
	s->next = top;
	top = s;
}
int pop(stack* s)
{
	if (isempty())
		return -1;
	else
	{
		s = top;
		top = top->next;
		return s->data;
	}
}