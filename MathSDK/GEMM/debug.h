#ifndef DEBUG_H
#define DEBUG_H

#include <stdlib.h>
#include <stdio.h>

void printMatrixVectorPointer(float ***M, size_t *size);

void printMatrixVectorValues(float ***M, size_t *size);

void printVectorVectorPointer(float **V, size_t *size);

void printVectorVectorValues(float **V, size_t *size);

#endif
