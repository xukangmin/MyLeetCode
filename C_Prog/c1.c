#include <stdio.h>
#include <stdlib.h>



void exchange(int  *x, int *y)
{
    int *t = x;
    *x = *y;
    *y = *t;
}



int main(void) {
    int a,b;
    scanf("%d %d",&a, &b);

    exchange(&a,&b);

    printf("%d %d", a, b);
    
}