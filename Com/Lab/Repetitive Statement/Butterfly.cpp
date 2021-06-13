/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n-1;i++){
        for(j=0;j<=i;j++){
            printf("*");
        }
        for(j=0;j<2*n-3-2*i;j++){
            printf("-");
        }
        for(j=0;j<=i;j++){
            printf("*");
        }
        printf("\n");
        }
    for(j=0;j<2*n-1;j++){
        printf("*");
    }
    printf("\n");
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            printf("*");
        }
        for(j=0;j<2*i+1;j++){
            printf("-");
        }
        for(j=0;j<n-i-1;j++){
            printf("*");
        }
        printf("\n");
        }


    return 0;
}
