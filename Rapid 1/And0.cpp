/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int idx,st;
    bool operator<(const A&o)const{
        return idx<o.idx;
    }
};
vector<A> g;
int a[1000100];
int main()
{
	int n,q,i,l,r,j;
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    while(q--){
        scanf("%d %d",&l,&r);
        g.push_back({l,1});
        g.push_back({r+1,-1});
    }
    sort(g.begin(),g.end());
    int st=0,tmp;
    j=0;
    for(i=1;i<=n;i++){
        if(g[j].idx==i)st+=g[j].st,j++;
        while(g[j].idx==i)st+=g[j].st,j++;
        if(st>0){
            printf("0 ");
        }
        else printf("%d ",a[i]);
    }
    return 0;
}
