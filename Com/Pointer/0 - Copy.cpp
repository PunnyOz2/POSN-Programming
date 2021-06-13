/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
int main()
{
    int age;
    int *pointer;
    age = 25;
    pointer = &age;
    printf("Address = %p\n",pointer);

    return 0;
}
