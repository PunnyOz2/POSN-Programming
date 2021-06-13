/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[1200][1200];
int main()
{
    int n,m,k,i,j,Max=-100;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }
	for(i=1+k;i<=n;i++){
        for(j=1+k;j<=m;j++){
            Max=max(Max,a[i][j]-a[i-k][j]-a[i][j-k]+a[i-k][j-k]);
        }
	}
	printf("%d",Max);
    return 0;
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
