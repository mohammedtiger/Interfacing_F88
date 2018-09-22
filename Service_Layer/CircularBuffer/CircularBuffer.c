#include "../CircularBuffer/CircularBuffer.h"

#include <stdio.h>


static void CircularBuffer_Init(CircularBuffer * const me, bool(*isFullfunction)(CircularBuffer * const me),
	bool(*isEmptyfunction)(CircularBuffer * const me),
	int(*getSizefunction)(CircularBuffer * const me),
	void(*enqueuefunction)(CircularBuffer * const me, uint8_t value),
	void(*dequeuefunction)(CircularBuffer * const me, uint8_t * pvalue)){

	me->head = 0;
	me->size = 0;
	me->tail = 0;

	me->isFull = isFullfunction;
	me->isEmpty = isEmptyfunction;
	me->getSize = getSizefunction;
	me->enqueue = enqueuefunction;
	me->dequeue = dequeuefunction;
}

static bool CircularBuffer_isFull(CircularBuffer * const me){
	return (me->head == me->tail) && (me->size >= CB_BUFFER_SIZE);
}

static bool CircularBuffer_isEmpty(CircularBuffer * const me){
	return (me->head == me->tail) && (me->size == 0);
}

static int CircularBuffer_getSize(CircularBuffer * const me){
	return me->size;
}

static void CircularBuffer_enqueue(CircularBuffer * const me, uint8_t value){
		me->buffer[me->tail] = value;
		me->tail = (me->tail+1) % CB_BUFFER_SIZE;
		++me->size;
}

static void CircularBuffer_dequeue(CircularBuffer * const me, uint8_t * pvalue){
		*pvalue = me->buffer[me->head];
		me->head = (me->head + 1) % CB_BUFFER_SIZE;
		--me->size;
}

void CircularBuffer_ctor(CircularBuffer * const me){

	CircularBuffer_Init(me, CircularBuffer_isFull, CircularBuffer_isEmpty,
		CircularBuffer_getSize, CircularBuffer_enqueue, CircularBuffer_dequeue);

}
