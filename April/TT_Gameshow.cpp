/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100],Q[100100][2],b[100100],c[100100];
int ans[100100];
int main()
{
	int q,n,i,j,now,Max=0;
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]<=100000)c[a[i]]++;
    }
	for(i=1;i<=q;i++)scanf("%d %d",&Q[i][0],&Q[i][1]);
	for(i=1;i<=100000;i++){
        if(c[i]>=i){
            for(j=1;j<=n;j++){
                b[j]=b[j-1];
                if(a[j]==i)b[j]++;
            }
            for(j=1;j<=q;j++){
                now=b[Q[j][1]]-b[Q[j][0]-1];
                if(now>=i)ans[j]++;
            }
        }
	}
	for(i=1;i<=q;i++){
        printf("%d\n",ans[i]);
	}
    return 0;
}
