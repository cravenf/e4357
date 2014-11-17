#ifndef __CIRCULAR_BUFFER
#define __CIRCULAR_BUFFER

#include <stdio.h>
#include <string.h>

/* Implement a circularbuffer library with the following API interface */

/**< Circular Buffer Types */
typedef unsigned char INT8U;
typedef INT8U KeyType ;
typedef struct {  
    INT8U writePointer ; /**< write pointer */  
    INT8U readPointer ;  /**< read pointer */  
    INT8U size;         /**< size of circular buffer */
    INT8U mask;         /**< bit mask of circular buffer size*/   
    KeyType keys[0];    /**< element of circular buffer */
} CircularBuffer ; 

inline CircularBuffer* CircularBufferInit(void) {
	// allocate CircularBuffer structure plus maximum-size buffer (power of 2)
	CircularBuffer *q = malloc(sizeof(CircularBuffer) + 256);
	if (!q)
		return q;

	q->writePointer = q->readPointer = 2;
	q->size = (INT8U)256;
	q->mask = q->size - 1;
	printf("q->writePointer	: %u\n"
		"q->readPointer	: %u\n"
		"q->size		: %u\n"
		"q->mask		: %02x\n",
		q->writePointer,
		q->readPointer,
		q->size,
		q->mask);
	return q;
}

inline void CircularBufferDeinit( CircularBuffer *q ) {
	memset((void *)q, 0, sizeof(CircularBuffer));
	free((void *)q);
}

inline int CircularBufferIsFull( CircularBuffer * q ) {
	return (-1 == ((int)q->writePointer - (int)q->readPointer));
}

inline int CircularBufferIsEmpty(CircularBuffer* q) {
	return (q->writePointer == q->readPointer);
}

inline int CircularBufferEnque(CircularBuffer* q, KeyType k) {

	// lock queue
	if (CircularBufferIsFull(q)) {
		// unlock queue
		return -1;
	}

	q->keys[q->writePointer] = k;
	q->writePointer += 1;
	q->writePointer &= q->mask;
	// unlock queue
	return 0;
}

inline int CircularBufferDeque(CircularBuffer* q, KeyType* pK) {

	// lock queue
	if (CircularBufferIsEmpty(q)) {
		// unlock queue
		return -1;
	}

	*pK = q->keys[q->readPointer];
	q->readPointer += 1;
	q->readPointer &= q->mask;
	// unlock queue
	return 0;
}

inline int CircularBufferPrint(CircularBuffer* q) {

	INT8U i, j=1;
	// lock queue
	for (i=q->readPointer; i!=q->writePointer; i=++i&q->mask) {
		printf(" %*3d ", q->keys[i]); 
		// print up to 10 queue elements per line
		if (j < 10)
			j++;
		else {
			printf("\n");
			j=1;
		}
	}
	// unlock queue
	return 0;
}

#endif


















































































































































































































































