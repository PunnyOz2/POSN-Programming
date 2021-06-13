/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int rmg[20][1000005];
int main()
{
	int n,q,a,b,i,j,k;
	scanf("%d %d",&n,&q);
	for(i=0;i<n;i++){
        scanf("%d",&rmg[0][i]);
	}
	for(i=1;(1<<i)<=n;i++){
        for(j=0;j+(1<<i)<=n;j++){
            rmg[i][j]=max(rmg[i-1][j],rmg[i-1][j+(1<<(i-1))]);
        }
	}
	while(q--){
        scanf("%d %d",&a,&b);
        k=log2(b-a+1);
        printf("%d\n",max(rmg[k][a],rmg[k][b-(1<<k)+1]));
	}
    return 0;
}
/*
6 3
1 3 2 4 2 6
0 5 0 2 3 5
*/
