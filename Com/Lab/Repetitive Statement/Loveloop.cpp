/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
int main()
{
    int n,j,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",i+j+1);
        };
        printf("\n");
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<=n+i;j++){
            if(j<=n){printf("%d ",j);}
            if(j>n){printf("%d ",j-n);}

        };
        printf("\n");
    }



    return 0;
}
