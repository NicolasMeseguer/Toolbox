#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOP 3

void initVector(int storeCals[], int size) {
	
	for (int i = 0; i < size; ++i) {
		storeCals[i] = 0;
	}

}

void printStoreCals(int storeCals[], int size) {
	
	for (int i = 0; i < size; ++i) {
		printf("%i\n", storeCals[i]);
	}

}

int printAccum(int storeCals[], int size) {
	int maxTOPAccum = 0;
	for (int i = 0; i < size; ++i) {
		maxTOPAccum += storeCals[i];
	}

	return maxTOPAccum;

}

int main( int argc, char *argv[] ) {
	
	// File pointers
    FILE* ptr;
	char buffer[255];
    ptr = fopen("input.txt", "r");

	// AoC Variables
	int storeCals[TOP];

	initVector(storeCals, TOP);
	//printStoreCals(storeCals, TOP);
	
	for(int i = 0; i < TOP; ++i) {
		int cals = 0;
		int maxCals = 0;
		while(fgets(buffer, 255, ptr)) {
			if(strcmp(buffer, "\n") == 0) {
				int storeFlag = 1;

				for(int j = 0; j < TOP; ++j)
					if (cals == storeCals[j])
						storeFlag = 0;

				if (storeFlag)
					maxCals = (cals>maxCals)?cals:maxCals;

				cals = 0;
			}
			else
				cals += atoi(buffer);
		}

		storeCals[i] = maxCals;


		rewind(ptr);
	}

	fclose(ptr);

	printStoreCals(storeCals, TOP);
	printf("La suma de los %i elfos con mayor numero de calorias es: %i\n", TOP, printAccum(storeCals, TOP));

	return 0;
}

