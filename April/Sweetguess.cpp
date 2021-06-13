/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100],b[100100],mark[100100];
int main()
{
	int q,n,m,i,ii,idx,ch,ch2;
	scanf("%d",&q);
	int j=0;
	for(i=2;i<=100000;i++){
        if(mark[i]!=1)b[j++]=i;
        for(ii=i;ii<=100000;ii+=i){
            mark[ii]=1;
        }
	}
	int cou=1;
	while(q--){
        ch=0;
        ch2=0;
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++){
            scanf("%d",&a[i]);
            idx=lower_bound(b,b+j,a[i])-b;
            if(a[i]==1)ch2=1;
            if(a[i]<n && b[idx]==a[i])ch=1;
        }
        printf("Case %d: ",cou++);
        idx=lower_bound(b,b+j,n)-b;
        if(n==2)printf("0\n");
        else if(ch2==1 && ch==0)printf("%d\n",idx);
        else if(ch2==0)printf("1\n");
        else printf("can't guess\n");
	}
    return 0;
}
