#include "utils.h"
#include "stack.h"
#include <stdio.h>

void reverse(int* nums, int size)
{
	stack* s = new stack;
	for (int i = 0; i < size; i++)
	{
		push(s, nums[i]);
	}
	for (int i = 0; i < size; i++)
	{
		nums[i]=pop(s);
		printf("%d\n", nums[i]);
	}
}

