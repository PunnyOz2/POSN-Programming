/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
long factorial(long);
int main()
{
    int i;
    scanf("%d",&i);
    printf("%d! =%ld\n",i,factorial(i));
}
long factorial(long number){
if(number <=1)
    return 1;
else
    return(number*factorial(number-1));
}


