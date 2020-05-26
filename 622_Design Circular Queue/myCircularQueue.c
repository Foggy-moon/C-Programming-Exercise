#include <stdio.h>
#include <stdlib.h>
#define bool int
#define true 1
#define false 0
typedef struct {
	int* queue;
	int head;
	int tail;
	int size;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	obj->head = -1;
	obj->tail = -1;
	obj->size = k;
	obj->queue = (int*)malloc(sizeof(int) * k);
	while (k)(obj->queue)[--k] = -1;
	return obj;
}

/** Checks whether the circular queue is empty or not. */
bool  myCircularQueueIsEmpty(MyCircularQueue* obj) {
	if (obj->head == -1)
		return true;
	else
		return false;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	if ((obj->tail + 1) % obj->size == obj->head)
		return true;
	else
		return false;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (myCircularQueueIsFull(obj))
		return false;
	if (myCircularQueueIsEmpty(obj)) {
		obj->head = 0;
	}
	obj->tail = (obj->tail + 1) % obj->size;
	(obj->queue)[obj->tail] = value;
	return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return false;
	if (obj->head == obj->tail)
	{
		(obj->queue)[obj->head] = -1;
		obj->head = -1;
		obj->tail = -1;
	}
	else
		obj->head = (obj->head + 1);
	return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return -1;
	else
		return (obj->queue)[obj->head];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return -1;
	else
		return (obj->queue)[obj->tail];
}


void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->queue);
	free(obj);
}