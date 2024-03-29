#include <stdio.h>
#include <stdlib.h>

// Input:   Scalar variable n (integer) contains the length of the vector; 
//          Scalar variable A is a single-precision float. Vectors X, Y and Z are single-precision float.
//
// Process: Z[i] = A * X[i] + Y[i]
//
// Output:  Store result in vector Z. 
//          Display the result of 1st ten elements of vector Z for all versions of kernel (i.e., C and x86-64).

float* saxpy_c(int n, float a, float* x, float* y, float* z){
    for(int i = 0; i < n; i++){
        x[i] *= a;
        z[i] = x[i] + y[i];
    }

    return z;
}