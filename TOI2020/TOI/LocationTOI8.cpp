#include <bits/stdc++.h>
using namespace std;
int qs[1100][1100],a[1100][1100];
int main(){
    int n,m,k,Max,i,j;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            qs[i][j]=a[i][j]+qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
        }
    }
    Max=0;
    for(i=k;i<=n;i++){
        for(j=k;j<=m;j++){
            Max=max(Max,qs[i][j]-qs[i-k][j]-qs[i][j-k]+qs[i-k][j-k]);
            //printf("%d %d %d\n",i,j,qs[i][j]-qs[i-k][j]-qs[i][j-k]+qs[i-k][j-k]);
        }
    }
    printf("%d\n",Max);
}
/*
5 10
2
5 9 2 9 1 2 8 9 1 6
9 1 3 9 8 4 2 1 5 7
2 7 9 3 8 5 2 7 6 8
1 6 2 1 7 7 1 9 4 1
8 5 2 3 9 8 5 6 3 3
*/