#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

extern float* saxpy_c(int n, float a, float* x, float* y);    //C kernel
extern float* saxpy_asm(int, float, float*, float*);

float* generateArr1(int n){ //populate array 1 (starting at 1.0, increments by 1.0)
    float* array = (float*)malloc(n*sizeof(float));
    float arrayVal = 1.0;
    for(int i = 0; i<n; i++){
        array[i] = arrayVal;
        arrayVal++;
    }
    return array;
}

float* generateArr2(int n){ //populate array 2 (starting at 11.0, increments by 1.0)
    float* array = (float*)malloc(n*sizeof(float));
    float arrayVal = 11.0;
    for(int i = 0; i<n; i++){
        array[i] = arrayVal;
        arrayVal++;
    }
    return array;
}

int main() {

    // --- EDIT THESE TWO VARIABLES ONLY ---
    int power = 28; //vector size exponent
    float a = 2.0; //scalar variable
    // -------------------------------------

    int n = pow(2, power);
    float* arr1 = generateArr1(n);
    float* arr2 = generateArr2(n);

    //timing the C kernel
    clock_t startC = clock(), diffC;
    float* arr3 = saxpy_c(n, a, arr1, arr2);
    diffC = clock() - startC;
    int cTimeMs = diffC * 1000 / CLOCKS_PER_SEC;

    for(int i=0; i<10; i++){ //prints first 10 elements
        printf("Element %d = %.2f\n", i, arr3[i]);
    }
    printf("Time taken for C kernel at vector size 2^%d: %d s, %d ms\n\n", power, cTimeMs/1000, cTimeMs%1000);

    //timing the Assembly kernel
    clock_t startA = clock(), diffA;
    float* asmArr3 = saxpy_asm(n, a, arr1, arr2);
    diffA = clock() - startA;
    int aTimeMs = diffA * 1000 / CLOCKS_PER_SEC;

    //insert printing of results here
    printf("Time taken for Assembly kernel at vector size 2^%d: %d s, %d ms\n\n", power, aTimeMs/1000, aTimeMs%1000);
}
