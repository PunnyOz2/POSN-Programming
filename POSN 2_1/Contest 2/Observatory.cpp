/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[2300][2300],b[2300][2300],c[2300][2300],d[2300][2300];
int main()
{
	int n,m,k,i,j,Max=-1000100000,sum,ii,temp;
	scanf("%d %d %d",&n,&m,&k);
	for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            b[i][j]=a[i][j];
            b[i][j]+=b[i-1][j+1];
            a[i][j]+=a[i-1][j-1];
            c[i][j]=a[i][j]+c[i-1][j];
            d[i][j]=b[i][j]+d[i-1][j];
        }
	}
	for(i=1;i<=n;i++){
        reverse(a[i]+1,a[i]+1+m);
        reverse(c[i]+1,c[i]+1+m);
	}
	for(i=k;i<=n;i++){
        sum=0;
        for(j=m;j>=1;j--){
            sum+=b[i][j];
            if(j<=m-k+1){
                sum-=b[i][j+k];
                temp=sum;
                sum-=d[i-1][j+k];
                printf("%d ",sum);
                Max=max(Max,sum);
                sum=temp;
            }
        }
	}
	for(i=k;i<=n;i++){
        sum=0;
        for(j=m;j>=1;j--){
            sum+=a[i][j];
            if(j<=m-k+1){
                sum-=a[i][j+k];
                temp=sum;
                sum-=c[i-1][j+k];
                printf("%d ",sum);
                Max=max(Max,sum);
                sum=temp;
            }
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
