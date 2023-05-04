#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void initQueue(queue* q, unsigned int size)
{
	q->_maxsize = size;
	q->_elements = new int[q->_maxsize];
	q->_size = 1;//current size cuz size[0] is a checker to know if the tor is empty
	q->_elements[0] = -1;
	q->_c = 1;
}

void cleanQueue(queue* q)
{
	delete q->_elements;
}		


void enqueue(queue* q, unsigned int newValue)
{
	q->_elements[q->_size] = newValue;
	q->_size += 1;

}

int dequeue(queue* q)
{
	int temp = q->_elements[q->_c];
	q->_c += 1; 
	return temp;
}
