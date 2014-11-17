#include <stdlib.h>
#include "fifo.h"

int main(int argc, char **argv) {

	INT8U n;
	CircularBuffer* q = CircularBufferInit();

	srand((unsigned int)time());

	printf("\nenqueued", n);
	while (!CircularBufferIsFull(q)) {
		n = (INT8U) (rand() % 256);
		CircularBufferEnque( q, n );
		printf(" %d", n);
	}
	printf("\nq is full and contains:\n");

	CircularBufferPrint( q );

	printf("\ndequeued", n);
	while (!CircularBufferIsEmpty(q)) {
		CircularBufferDeque( q, &n );
		printf(" %d", n );
	}
		
	printf("\nq is empty\n");

	CircularBufferDeinit(q);
	return 0;
}
