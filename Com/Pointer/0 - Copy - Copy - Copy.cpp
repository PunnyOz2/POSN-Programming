/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
void swap (int *,int *);

int main()
{
    int a=9;
    int b=29;
    swap(a,b);
    printf("%d %d",a,b);

    void swap (int *px, int *px){
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
    }

    return 0;
}
