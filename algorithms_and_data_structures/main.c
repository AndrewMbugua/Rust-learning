#include<stdio.h>

int main (){


printf("%x\n",0x03f2 + 0xf5f4 + 0b0100 + 0xf7f6);


//127708 -expected
//127456
//off by 252
}