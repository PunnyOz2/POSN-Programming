/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,idx;
    bool operator<(const A&o)const{
        return i<o.i;
    }
};
vector<A> g;
priority_queue<int> q;
int mark[500100];
int main()
{
	int n,k,Q,i,u,v,idx;
	scanf("%d %d %d",&n,&k,&Q);
	for(i=1;i<=n;i++){
        scanf("%d %d",&u,&v);
        g.push_back({u,v,i});
	}
	sort(g.begin(),g.end());
	for(auto x:g){
        while(!q.empty() && -q.top()<x.i)  q.pop();
        if(q.size()<k)q.push(-x.j),mark[x.idx]=1;
	}
	while(Q--){
        scanf("%d",&idx);
        if(mark[idx]==1)printf("Y ");
        else printf("N ");
	}
    return 0;
}
/*
6 2 4
3 7 2 4 1 3 7 8 8 10 9 15
3 5 4 1

4 1 4
1 5 2 3 3 4 4 5
1
*/
