#include<immintrin.h>
#include<avxintrin.h>
#include<avx2intrin.h>

int main(){


__m256d a = {0.0, 1.0, 2.0, 3.0};
__m256d b = {2.0, 4.0, 6.0, 8.0};
__m256d c;

c = _mm256_add_pd(a,b);


}