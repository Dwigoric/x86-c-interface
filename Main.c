#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern float* saxpy(int n, float a, float* x, float* y);    //C kernel
// extern... for the assembly kernel

int main(){
    int n = 3;
    float a = 2.0;
    float arr1[] = {1.0, 2.0, 3.0};
    float arr2[] = {11.0, 12.0, 13.0};


    //timing the C kernel
    clock_t startC = clock(), diffC;
    float* arr3 = saxpy(n, a, arr1, arr2);
    diffC = clock() - startC;
    int cTimeMs = diffC * 1000 / CLOCKS_PER_SEC;

    for(int i=0; i<3; i++){
        printf("Element %d = %.2f\n", i, arr3[i]);
    }
    printf("Time taken for C kernel: %d s, %d ms\n\n", cTimeMs/1000, cTimeMs%1000);

    //timing the Assembly kernel
    clock_t startA = clock(), diffA;
    //insert function here
    diffA = clock() - startA;
    int aTimeMs = diffA * 1000 / CLOCKS_PER_SEC;

    //insert printing of results here
    printf("Time taken for Assembly kernel: %d s, %d ms\n\n", aTimeMs/1000, aTimeMs%1000);
}