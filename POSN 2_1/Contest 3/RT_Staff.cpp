/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[2000100],b[2000100];
int main()
{
	int Q,n,idx,i,w,ans;
	scanf("%d",&Q);
	while(Q--){
        int Max=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            Max=max(Max,a[i]);
        }
        b[n]=0;
        for(i=n+1;i<=n+1+Max;i++)b[i]=1200000;
        for(i=n-1;i>=1;i--){
            b[i]=min(b[i+1]+1,b[i+a[i]]+1);
        }
        printf("%d\n",b[1]);
	}
    return 0;
}
/*
2
5
2 3 3 1 1
6
3 2 2 3 2 5
*/
