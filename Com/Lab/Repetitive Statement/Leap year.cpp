/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
int main()
{
    int x,y;
    scanf("%d %d",&x,&y);
    for(y;y>=x;y--)
    if(y%4==0 && y%100!=0 || y%400==0){
            printf("%d\n",y);
    }
    return 0;
}
