#include <stdio.h>
#include <stdlib.h>

int* decToBin(int);
int hammingDistance(int, int);
int main() {
	printf("The Hamming distance between 0 and 1 is: %d", hammingDistance(0,1));

	return 0;
}

int* decToBin(int x){  // this function convert an integer to binary number
	int* myNumber = (int*)malloc(sizeof(int)*32);   // use malloc function to stores the bits of the binary number in an array 
	//and to avoid losing this array at the end of this function
	for (int i = 31; i >= 0;) {
		//printf("%d", x % 2);      //take the remainder of the division by to to get the bits in binary
		myNumber[i--] = x % 2;  //stores the bits in the reverse order to get the binary represntation
		x = x / 2;				// divide the in by 2 to get the next bit
	}
	printf("\n");
	return myNumber;          // return the binary represntation by the inverse order
}

int hammingDistance(int x1, int x2) {
	int* n1 = decToBin(x1);
	int* n2 = decToBin(x2);
	int counter = 0; 
	for (int i = 0; i < 32; i++) {
		if (n1[i] == n2[i]) {

		}
		else {
			counter++;
		}
	}
	return counter;
}