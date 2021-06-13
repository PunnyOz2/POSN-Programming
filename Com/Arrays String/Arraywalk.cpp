/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
int Array[21][21];
int main()
{
    int i,j,n,k,N,M;
    scanf("%d %d",&N,&M);
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            scanf("%d",&Array[i][j]);
        }
    }
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            printf("%d ",Array[i][j]);
        }}
    printf("\n");
    for(i=N-1;i>=0;i--){
        for(j=M-1;j>=0;j--)
            printf("%d ",Array[i][j]);
        }
    printf("\n");
    for(j=0;j<M;j++){
        for(i=0;i<N;i++)
            printf("%d ",Array[i][j]);
        }
    printf("\n");
    for(j=M-1;j>=0;j--){
        for(i=N-1;i>=0;i--)
            printf("%d ",Array[i][j]);
        }
    return 0;
}

