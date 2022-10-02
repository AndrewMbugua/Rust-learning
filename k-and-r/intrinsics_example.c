#include<immintrin.h>
#include<avxintrin.h>
//AVX intrinsics - 64bit floating point operations
//compile avx code - gcc -mavx intrinsics.c -o avx
int main(){

double arr[8] = {1.0,2.0,3.0,2.0,6.0,4.0,4.0,3.0};

//load 1st 4
__m256d first = _mm256_load_pd(arr);

//load last 4
__m256d last = _mm256_load_pd(arr + 4);

//pairwise addition
__m256d sum = _mm256_add_pd(first, last);

double arr1[4] = {0, 0, 0, 0};

//copy
_mm256_store_pd(arr1,sum);

}