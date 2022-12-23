#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOP 5

void initVector(int storeCals[], int size) {
	
	for (int i = 0; i < size; ++i) {
		storeCals[i] = 0;
	}

}

void printStoredCals(int storeCals[], int size) {
	
	for (int i = 0; i < size; ++i) {
		printf("%i\n", storeCals[i]);
	}

}

void printAccum(int storeCals[], int size) {
	int maxTOPAccum = 0;
	for (int i = 0; i < size; ++i) {
		maxTOPAccum += storeCals[i];
	}

	printf("La suma de los %i elfos con mayor numero de calorias es: %i\n", size, maxTOPAccum);

}

int main( int argc, char *argv[] ) {
	
	ushort lead_elves = TOP;

	if(argc > 1) {
		lead_elves = atoi(*(argv+1));
	} else {
		printf("You can specify how many TOP elves' calories you want to count.\nThe default number of elves is 5.\n\n");
	}

	// File pointers
    FILE* ptr;
	char buffer[255];
    ptr = fopen("input.txt", "r");

	// AoC Variables
	int storeCals[lead_elves];
	initVector(storeCals, lead_elves);
	
	// Do it as many times as elves'calories you want to retrieve
	for(int i = 0; i < lead_elves; ++i) {
		int cals = 0;
		int maxCals = 0;

		while(fgets(buffer, 255, ptr)) {
			if(strcmp(buffer, "\n") == 0) {
				int storeFlag = 1;

				// Compare if the cals (accumulated) are already stored in the vector
				// in case this is the max, amount.
				for(int j = 0; j < lead_elves; ++j)
					if (cals == storeCals[j])
						storeFlag = 0;	

				// If not, then simply compare and swap the value if greater than.
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

	printStoredCals(storeCals, lead_elves);
	printAccum(storeCals, lead_elves);

	return 0;
}

