/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue<int> q;
int a[10000010];
int main()
{
	int n,m,Q,r,sum,i,w,c,cou,last,idx,idx2;
	scanf("%d %d %d %d",&n,&m,&Q,&r);
	for(i=0;i<n;i++){
        scanf("%d",&w);
        a[i]=w;
	}
	while(Q--){
        last=0;
        cou=0;
        for(i=0;i<m;i++){
            scanf("%d",&c);
            q.push(c*-1);
        }
        while(!q.empty()){
            c=q.top()*-1,q.pop();
            idx=lower_bound(a,a+n,c-r)-a;
            if(idx<last)idx=last;
            idx2=upper_bound(a,a+n,c+r)-a;
            cou+=(idx2-idx);
            last=idx2;
        }
        printf("%d\n",cou);
	}
    return 0;
}
/*
3 2 4 100
100 300 500
200 1000
199 1000
*/
