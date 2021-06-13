/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
#include<math.h>
void Frac(int y){
    if(y==1)
        printf("*");
    if(y!=1){
    int i;
    int j;
    int x = y-1;
    int b = pow(2,x);
    Frac(y-1);
    for(i=0;i<b-1;i++){
        for(j=0;j<b/2;j++){
            printf("-");
        }
        printf("\n");
    }
    for(j=0;j<b;j++)
        printf("*");
    printf("\n");
    for(i=0;i<b-1;i++){
        for(j=0;j<b/2;j++){
            printf("-");
        }
    }
    Frac(y-1);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    Frac(n);




    return 0;
}
