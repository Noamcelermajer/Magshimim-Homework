#ifndef STACK_H
#define STACK_H

/* a positive-integer value stack, with no size limit */
typedef struct stack
{
	int data;
	struct stack *next;
} stack;

bool isempty();
void push(stack* s, unsigned int element);
int pop(stack* s); // Return -1 if stack is empty// Return -1 if stack is empty

void initStack(stack* s);
void cleanStack(stack* s);

#endif // STACK_Hs