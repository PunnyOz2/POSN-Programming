/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            printf("+");}
        for(j=i+1;j>0;j--){
            printf("0");}
        for(j=i;j>0;j--){
            printf("0");}
        for(j=i+1;j<n;j++){
            printf("+");}
        printf("\n");}
    for(i=0;i<n-1;i++){
        for(j=0;j<=i;j++){
            printf("+");
            }
        for(j=0;j<2*n-3-2*i;j++){
            printf("0");
            }
        for(j=0;j<=i;j++){
            printf("+");
            }
    printf("\n");
    }
    return 0;
}
