#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "debug.h"

#define DEFAULT_SIZE 1024
#define DEBUG 0
#define VALUES 0
#define VERIFY 0

void fillVectorSize(float **V, size_t *size) {
	for (size_t i = 0; i < *size; ++i) {
		*((*V)+i) = rand() % 100;
	}
}

void fillVector(float **V, size_t *size) {
	for (size_t i = 0; i < *size; ++i) {
		*((*V)+i) = rand() % 100;
	}
}

void fillMatrix(float ***M, size_t *size) {
	for (size_t i = 0; i < *size; ++i) {
		fillVector((*M+i), size);
	}
}

void mallocVector(float **V, size_t *size_bytes) {
	*V = (float*)malloc(*size_bytes);
}

void mallocMatrix(float ***M, size_t *size, size_t *size_bytes) {

	*M = malloc(*size_bytes);

	for(size_t i = 0; i < *size; ++i) {
		mallocVector((*M+i), size_bytes);
	}
}

int main( int argc, char *argv[] ) {
	srand(time(NULL));

	size_t size = DEFAULT_SIZE;
	if(argc > 1) {
		size = (size_t)(atoi(argv[1]));
	}

	size_t size_bytes = sizeof(float*) * size;
	size_t oned_vector_size = size * size;
	size_t oned_vector_size_bytes = sizeof(float*) * oned_vector_size;

	float **A, **B, **C, **vC;
	float *A1D, *B1D, *C1D, *vC1D;

	// ===================
	// 1st - MALLOC MEMORY
	// ===================

	// 2D Matrices
	mallocMatrix(&A, &size, &size_bytes);
	if (DEBUG)
		printMatrixVectorPointer(&A, &size);

	mallocMatrix(&B, &size, &size_bytes);
	if (DEBUG)
		printMatrixVectorPointer(&B, &size);

	mallocMatrix(&C, &size, &size_bytes);
	if (DEBUG)
		printMatrixVectorPointer(&C, &size);

	if(VERIFY) {
		mallocMatrix(&vC, &size, &size_bytes);
		if (DEBUG)
			printMatrixVectorPointer(&vC, &size);
	}

	// 1D Matrices
	mallocVector(&A1D, &oned_vector_size_bytes);
	if(DEBUG)
		printVectorVectorPointer(&A1D, &oned_vector_size);

	mallocVector(&B1D, &oned_vector_size_bytes);
	if(DEBUG)
		printVectorVectorPointer(&B1D, &oned_vector_size);

	mallocVector(&C1D, &oned_vector_size_bytes);
	if(DEBUG)
		printVectorVectorPointer(&C1D, &oned_vector_size);

	if(VERIFY) {
		mallocVector(&vC1D, &oned_vector_size_bytes);
		if(DEBUG)
			printVectorVectorPointer(&vC1D, &oned_vector_size);
	}

	// ===================
	// 2nd - FILL VEC/MATs
	// ===================

	// Fill 2D Matrices
	fillMatrix(&A, &size);
	if (VALUES)
		printMatrixVectorValues(&A, &size);

	fillMatrix(&B, &size);
	if(VALUES)
		printMatrixVectorValues(&B, &size);

	// Fill 1D Matrices
	fillVectorSize(&A1D, &oned_vector_size);
	if (VALUES)
		printVectorVectorValues(&A1D, &oned_vector_size);

	fillVectorSize(&B1D, &oned_vector_size);
	if (VALUES)
		printVectorVectorValues(&B1D, &oned_vector_size);

	// ===================
	// 3rd - MUL VEC/MATs
	// ===================
	
	if(VERIFY) {
		// multiplyMatrixVerify(&A, &B, &vC, &size);
		// compareMatrix(&vC, &C, &size);
	}
	
	if(VERIFY) {
		// multiplyMatrixVectorVerify(&A, &B, &vC, &size);
		// compareMatrixVector(&vC1D, &C1D, &size);
	}

	

	return 0;
}

