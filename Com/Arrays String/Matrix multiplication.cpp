/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
char Array1[15][15];
char Array2[15][15];
char Array3[15][15];
int main()
{
    int n1,m1,n2,m2,i,j,k;
    scanf("%d %d %d %d",&n1,&m1,&n2,&m2);
    for(i=0;i<n1;i++){
        for(j=0;j<m1;j++){
            scanf("%d",&Array1[i][j]);};
        }
    for(i=0;i<n2;i++){
        for(j=0;j<m2;j++){
            scanf("%d",&Array2[i][j]);};
        }
    if(m1==n2){
        for(i=0;i<n1;i++){
            for(j=0;j<m2;j++){
                int sum=0;
                for(k=0;k<m1;k++){
                    sum+=Array1[i][k]*Array2[k][j];

                }
                printf("%d ",sum);
        }
        printf("\n");}
    }
    else{
        printf("Can't Multiply.");
    }

    return 0;
}
