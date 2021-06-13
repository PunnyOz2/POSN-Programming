#include <bits/stdc++.h>
using namespace std;
int mark[500100];
struct A{
    int u,v,i;
    bool operator<(const A&o)const{
        return u<o.u;
    }
};
priority_queue<int> q;
vector<A>g;
int main(){
    int n,k,m,i,u,v,num,id;
    scanf("%d %d %d",&n,&k,&m);
    for(i=1;i<=n;i++){
        scanf("%d %d",&u,&v);
        g.push_back({u,v,i});
    }
    sort(g.begin(),g.end());
    for(auto x:g){
        u=x.u;
        v=x.v;
        id=x.i;
        while(!q.empty() && u>-q.top())q.pop();
        if(q.size()<k)q.push(-v),mark[id]=1;
    }
    while(m--){
        scanf("%d",&num);
        if(mark[num]==1)printf("Y ");
        else printf("N ");
    }
}
/*
6 1 4
3 7 2 4 1 3 7 8 8 10 9 15
3 5 4 1
*/
