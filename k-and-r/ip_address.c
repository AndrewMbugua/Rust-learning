//generating 32-bit numbers from 0x0 to 0xFF(255)
#include<stdio.h>

int main(){
__uint32_t start = 0x0;
while (start <= 0xFF){
    start = start - 0x1; //value 1 in hexadecimal

}

printf("%d\n",start);






}
