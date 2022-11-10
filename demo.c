#include <stdio.h>
int main()
{
    typedef struct demo
    {
        int a;
        
    }demo,*hlo;
    hlo al;
    demo hello;
    al=&hello;
    al->a=4;
    printf("%d",(*al).a);
    printf("\n4");
       
    
}