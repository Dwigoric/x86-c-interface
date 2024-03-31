#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

extern void saxpy_c(int n, float a, float* x, float* y, float* z);    //C kernel
extern void saxpy_asm(int, float, float*, float*, float*);

float* generateArr1(int n){ //populate array 1 (starting at 1.0, increments by 1.0)
    float* array = (float*)malloc(n*sizeof(float));
    float arrayVal = 1.0f;
    for(int i = 0; i<n; i++){
        array[i] = arrayVal;
        arrayVal += 1.0f;
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

float* generateEmptyArr(int n){ //generate empty array
	float* array = (float*)malloc(n*sizeof(float));
	return array;
}

void execute(int power, float a) {
    int n = pow(2, power);
    float* xC = generateArr1(n);
    float* xAsm = generateArr1(n);
    float* y = generateArr2(n);
    float* zC = generateEmptyArr(n);
    float* zAsm = generateEmptyArr(n);

    int cRuntimesSecond[30],
        asmRuntimesSecond[30],
        cRuntimesMillisecond[30],
        asmRuntimesMillisecond[30];

    printf("===============\n");
    printf("n = 2^%d\n", power);
    printf("A = %.2f\n", a);
    printf("===============\n");

    // ------ C Kernel ------
    printf("[C Kernel]\n");
    clock_t startC = clock(), diffC;
    saxpy_c(n, a, xC, y, zC);
    diffC = clock() - startC;
    int cTimeMs = diffC * 1000 / CLOCKS_PER_SEC;

    for (int i = 0; i < 10; i++) { //prints first 10 elements
        printf("Element %d = %.2f\n", i, zC[i]);
    }
    cRuntimesSecond[0] = cTimeMs / 1000;
    cRuntimesMillisecond[0] = cTimeMs % 1000;

    // Run for another 29 times
    for (int i = 1; i < 30; i++) {
		startC = clock();
		saxpy_c(n, a, xC, y, zC);
		diffC = clock() - startC;
		cTimeMs = diffC * 1000 / CLOCKS_PER_SEC;
		cRuntimesSecond[i] = cTimeMs / 1000;
		cRuntimesMillisecond[i] = cTimeMs % 1000;
	}

    // ------ Assembly Kernel ------
    printf("[x86-64 Kernel]\n");
    clock_t startA = clock(), diffA;
    saxpy_asm(n, a, xAsm, y, zAsm);
    diffA = clock() - startA;
    int aTimeMs = diffA * 1000 / CLOCKS_PER_SEC;

    for (int i = 0; i < 10; i++) { //prints first 10 elements
        printf("Element %d = %.2f\n", i, zAsm[i]);
    }
    asmRuntimesSecond[0] = aTimeMs / 1000;
    asmRuntimesMillisecond[0] = aTimeMs % 1000;

    // Run for another 29 times
    for (int i = 1; i < 30; i++) {
        startA = clock();
        saxpy_asm(n, a, xAsm, y, zAsm);
        diffA = clock() - startA;
        aTimeMs = diffA * 1000 / CLOCKS_PER_SEC;
        asmRuntimesSecond[i] = aTimeMs / 1000;
        asmRuntimesMillisecond[i] = aTimeMs % 1000;
    }

    // Print runtimes
    int cTotalTimeMs = 0;
    printf("\n\n");
    printf(" --- C Kernel Runtimes ---\n");
    for (int i = 0; i < 30; i++) {
        cTotalTimeMs += cRuntimesSecond[i] * 1000 + cRuntimesMillisecond[i];
		printf("Run %d: %d.%d seconds\n", i + 1, cRuntimesSecond[i], cRuntimesMillisecond[i]);
	}
    printf("Average: %d.%d seconds\n", cTotalTimeMs / 30000, (cTotalTimeMs % 30000) / 30);

    int aTotalTimeMs = 0;
    printf("\n");
    printf(" --- x86-64 Kernel Runtimes ---\n");
    for (int i = 0; i < 30; i++) {
        aTotalTimeMs += asmRuntimesSecond[i] * 1000 + asmRuntimesMillisecond[i];
        printf("Run %d: %d.%d seconds\n", i + 1, asmRuntimesSecond[i], asmRuntimesMillisecond[i]);
    }
    printf("Average: %d.%d seconds\n", aTotalTimeMs / 30000, (aTotalTimeMs % 30000) / 30);

    // Free allocated memory
    free(xC);
    free(xAsm);
    free(y);
    free(zC);
    free(zAsm);
}

int main() {
    int powers[3] = { 20, 24, 30 };
    float scalars[3] = { 2.0f, 3.0f, 4.0f };

    for (int i = 0; i < 3; i++) {
		execute(powers[i], scalars[i]);
	}

    return 0;
}
