/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[2200][2200],qs[2200][2200],b[2200],st[2200][2200];
int main()
{
	int n,m,k,i,j,Max=-2e9,sum,ii,temp;
	scanf("%d %d %d",&n,&m,&k);
	for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            qs[i][j]=qs[i-1][j]+qs[i][j-1]+a[i][j]-qs[i-1][j-1];
        }
	}
	for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            b[j]=(a[i][j]+b[j-1]);
            st[i][j]=b[j]+st[i-1][j-1];
        }
	}
	for(i=1;i<=n-k+1;i++){
        for(j=1;j<=m-k+1;j++){
            sum=st[i+k-1][j+k-1];
            sum-=qs[i+k-1][j-1];
            sum+=qs[i-1][j-1];
            sum-=st[i-1][j-1];
            Max=max(Max,sum);
        }
	}
	for(i=1;i<=n;i++){
        reverse(a[i]+1,a[i]+m+1);
        for(j=1;j<=m;j++){
            qs[i][j]=qs[i-1][j]+qs[i][j-1]+a[i][j]-qs[i-1][j-1];
        }
	}
	for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            b[j]=(a[i][j]+b[j-1]);
            st[i][j]=b[j]+st[i-1][j-1];
        }
	}
	for(i=1;i<=n-k+1;i++){
        for(j=1;j<=m-k+1;j++){
            sum=st[i+k-1][j+k-1];
            sum-=qs[i+k-1][j-1];
            sum+=qs[i-1][j-1];
            sum-=st[i-1][j-1];
            Max=max(Max,sum);
        }
	}
	printf("%d",Max);
    return 0;
}
/*
4 5 3
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6

6 7 4
-99 -99 -99 -99 -99 -99 -99
-99 -5 -99 -99 -99 -99 -99
-99 -5 -5 -99 -99 -99 -4
-99 -5 -5 -5 -99 -5 -6
-99 -5 -5 -5 -2 -5 -6
-99 -99 -99 -5 -5 -5 -4
*/
