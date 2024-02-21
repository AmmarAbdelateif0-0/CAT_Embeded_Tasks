#include<stdio.h>
#include"Ammar.h"

void main(void) {
    #if X
        printf("value of X = %d\n",X);
    #else
        printf("value of X = -1\n");
    #endif
/**************************************/
    #if Y
        printf("value of Y = %d\n",Y);
    #else
        printf("value of Y = -1\n");
    #endif
}