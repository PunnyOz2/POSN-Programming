/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
char a[100][100];
int M;
int Max=-1000;
void walk(int i,int j){
    if(a[i][j]>Max)Max=a[i][j];
    if(i+1<=M && a[i+1][j]!=100 && a[i][j]<a[i+1][j] ){walk(i+1,j);}
    if(i-1>0 && a[i-1][j]!=100 && a[i][j]<a[i-1][j] ){walk(i-1,j);}
    if(j+1<=M && a[i][j+1]!=100 && a[i][j]<a[i][j+1]){walk(i,j+1);}
    if(j-1>0 && a[i][j-1]!=100 && a[i][j]<a[i][j-1]){walk(i,j-1);}
}
int main()
{
    int i,j;
    int starti,startj;
    scanf("%d",&M);
    scanf("%d %d",&starti,&startj);
    for(i=1;i<=M;i++){
        for(j=1;j<=M;j++){
                scanf("%d",&a[i][j]);
        }
    }
            walk(startj,starti);
            printf("%d",Max);

    return 0;
}
/*4
2 1
100 1 3 8
0 2 1 4
2 3 5 100
0 8 8 100

5
4 2
0 1 100 100 0
100 2 3 1 1
100 100 4 5 100
8 7 100 6 100
7 100 100 100 9





*/
