#include <stdio.h>
const int SIZE = 10;

//requires: an array of integers
// effects: method to print the indeces and values of the array
//Test cases:
//1.empty array
//2.array of all the elemnts are the same
//4.array of zeros
//5.array of non integers
//6.array of all elements the same
void printArray(int a[]) {
    printf("Index   Value\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%3d  %5d\n", i, a[i]);
    }
}


//requires: an array of integers
//effects:method to print a histogram according to the frequency of the elements of the array
//Test cases:
//1.empty array
//2.array of all the elemnts are the same
//4.array of zeros
//5.array of non integers
//6.array of all elements the same

void arrayHistogram(int a[]) {
    printf("Value Frequency Histogram\n");
    int ocur[3] = { 0 };        //array to store the occurrences of the elemets of the array
    int counter = 0;
    for (int i = 0; i < SIZE; i++) {
        ocur[a[i] - 1]++;      
    }
    for (int j = 0; j < 3; j++) {
        printf("%5d %5d\t", j + 1, ocur[j]);
        for (int k = 0; k < ocur[j]; k++) {
            printf("*");
        }
        printf("\n");
    }
}

//requires: an array of integers, two positive integers
//effects: method to swap the elements at index i1 and i2 of an array 
//test cases:
//1.empty array
//2.two negative ints
//3.1st negative 
//4. 2nd negative
//5.two equal integers
//6.array of zeros
//7.

void swapValues(int a[], int i1, int i2) {
    int temp = a[i2];
    a[i2] = a[i1];
    a[i1] = temp;
}

//requires: an integer array
//Effects: method to sort the array using the buble sort concept
//test cases: 
//1.empty array
//2.array of all the elemnts are the same
//3. array in the descending order
//4.array of zeros
//5.array on non integers
//
void bubbleSort(int a[]) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - 1; j++) {
            if (a[j] >= a[j + 1]) {
                swapValues(a, j, j + 1);
            }
        }
    }
}

// method to find the median(element in the middle of the sorted array) of an array
// requires: an array of integers.
// finds the median of the array
// effects:
//test cases:
//1.size even 
//2. size odd
//3.empty array
//4.{3,3,3,3,3}
//5. array of not integers
//6.array of zeros
//7.
double median(int a[]) {
    bubbleSort(a);
    if ((SIZE % 2) != 0) {
        return (double) a[(SIZE - 1) / 2];
    }
    else {
        return ((float) a[SIZE/2] +  a[(SIZE/2) - 1]) / 2; 
    }
}


// requires: ana array of integers
//effects:method to find the mod (the element with highest frequency) of an array
//test cases: 
//1. all have same frequencies
//2. non int array
//3.empty array
//4.array of all elements the same
//5.
int mode(int a[]) {
    int max = 0;
    int maximum = 1;
    int ocur[3] = { 0 };        
    for (int i = 0; i < SIZE; i++) {
        ocur[a[i] - 1]++;
    }
    for (int j = 0; j < 3; j++) {
        if (max < ocur[j]) {
            max = ocur[j];
            maximum = j + 1;
        }
    }
    return maximum;
}

//requires; an array of integers and its positive integer size
//effects: method that return 1 if the array is sorted in an ascending order and 0 otherwise

//test cases:
//1.non integer array
//2.0 as asize
//3.-ve size
//4.empty array
//5.non integer size
//6.
int isSorted(int a[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (a[i] > a[i + 1]) {
            return 0;
        }
    }
    return 1;
}




int main() {
    int array[10] = { 1,1,1,1,1,2,2,2,3,3 };
    printf("Initial array\n");
    printArray(array);
    printf("\n");
    printf("Histogrm represntation\n");
    arrayHistogram(array);
    printf("\n");
    printf("swap array[0] with arra[8]\n");
    swapValues(array, 0, 8);
    printArray(array);
    printf("sorted array\n");
    bubbleSort(array);
    printArray(array);
    printf("median of the array: ");
    printf("%f\n", median(array));
    printf("mode of the array: ");
    printf("%d\n", mode(array));
    printf("check if the array sorted? ");
    printf("%d\n", isSorted(array, SIZE));


}



