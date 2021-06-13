/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
int main()
{
    int N,M;
    int skill;
    scanf("%d %d",&N,&M);
    if(M>=N){
        skill=(N-3)*2 +4;
        printf("%d",skill);
    }
    else if(N>M){
        skill=2*M-1;
        printf("%d",skill);
    }



    return 0;
}
