#include "debug.h"

void printMatrixVectorPointer(float ***M, size_t *size) {
	printf("\nPrinting 2D Matrix pointer:\n");
	for(size_t i = 0; i < *size; ++i) {
		printf("%p\n", (*M+i));
		for(size_t j = 0; j < *size; ++j) {
			printf("\t%p\n", (*(*M+i)+j));
		}
	}
}

void printMatrixVectorValues(float ***M, size_t *size) {
	printf("\nPrinting 2D Matrix values:\n");
	for(size_t i = 0; i < *size; ++i) {
		for(size_t j = 0; j < *size; ++j) {
			printf("\t%f\n", *(*(*M+i)+j));
		}
		printf("\n");
	}
}

void printVectorVectorPointer(float **V, size_t *size) {
	printf("\nPrinting 1D Matrix pointer:\n");
	for(size_t i = 0; i < *size; ++i) {
		printf("%p\n", (*V+i));
	}
}

void printVectorVectorValues(float **V, size_t *size) {
	printf("\nPrinting 1D Matrix values:\n");
	for(size_t i = 0; i < *size; ++i) {
		printf("%f\n", *(*V+i));
	}
}