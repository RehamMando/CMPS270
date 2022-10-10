#include <stdio.h>
#include <string.h>

//requires: takes an input two sorted arrays (sorted in alpha-numerical order)and the number of strings in each array.
// effects: It then returns a new array containing all strings in sorted(alpha - numeric) order

//test cases:
//two equal arrays
//2.first empty and second not
//3.two empty arrays
//4.first longest 
//5.second longest
//6.first icnluding non char elements
//7.second icnluding non char elements
//8.having same elements
//9.second empty and first not
//10.given sizes = 0.
//11.size1 =0
//12 size2 = 0



char** merge(char* a1[], char* a2[], int size1, int size2) {
    int n = size1 + size2;
    char** result;
    result = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (strcmp(a1[i], a2[j]) < 0) {
                result[i] = a1[i];
            }
            else if (strcmp(a1[i], a2[i]) > 0) {
                result[i] = a2[i];
            }
        }
    }
    return result;
}

//method to print the result of the merged arrays
void printResult(char** a) {
    printf("Sample output: \n");
    for (int i = 0; i < sizeof(a); i++) {
        printf("%s\n", a[0]);
    }
}

int main() {

    printf("sdhbs");
    char* array1[] = { "ab","ac" };
    char* array2[] = { "za", "zb", "zzzzc" };
    printResult(merge(array1, array2, sizeof(array1), sizeof(array2)));

    return 0;
}