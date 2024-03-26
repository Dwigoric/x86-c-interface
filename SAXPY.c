#include <stdio.h>
#include <stdlib.h>

// Input:   Scalar variable n (integer) contains the length of the vector; 
//          Scalar variable A is a single-precision float. Vectors X, Y and Z are single-precision float.
//
// Process: Z[i] = A * X[i] + Y[i]
//
// Output:  Store result in vector Z. 
//          Display the result of 1st ten elements of vector Z for all versions of kernel (i.e., C and x86-64).

float* saxpy(int n, float a, float* x, float* y){
    int i;
    float* z = (float*)malloc(n*sizeof(float));
    if (z == NULL){
        return NULL;
    }

    for(i = 0; i < n; i++){
        x[i] *= a;
        z[i] = x[i] + y[i];
    }

    return z;
}

// for testing ----------------------------------------
// int main(){
//     int n = 3;
//     float a = 2.0;
//     float arr1[] = {1.0, 2.0, 3.0};
//     float arr2[] = {11.0, 12.0, 13.0};

//     float* arr3 = saxpy(n, a, arr1, arr2);

//     for(int i=0; i<3; i++){
//         printf("Element %d = %.2f\n", i, arr3[i]);
//     }
// }