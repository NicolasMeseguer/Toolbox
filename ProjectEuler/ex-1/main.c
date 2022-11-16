#include <stdio.h>

int main(int argc, char* argv[]) {
	int res = 0;
	int startingNumber = 1000;

	for(int i=startingNumber-1; i>0; --i) {
		if(i%3==0 || i%5==0)
			res+=i;
	}

	printf("Result is: %d\n", res);

	return 0;
}
