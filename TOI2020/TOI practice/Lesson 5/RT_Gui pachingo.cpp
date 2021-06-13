#include<bits/stdc++.h>
using namespace std;
vector<long long> g[100100];
struct A{
    long long u,Max;
    bool operator<(const A&o)const{
        return Max<o.Max;
    }
};
vector<A> g2[100100];
long long Max[100100];
void dfs(long long u){
    Max[u]=u;
    for(auto x:g[u]){
        dfs(x);
        Max[u]=max(Max[x],Max[u]);
    }
}
long long cou=1;
long long qs[100100];
void play(long long u){
    if(g[u].size()==0){qs[cou++]=u;return;}
    for(auto x:g2[u]){
        play(x.u);
    }
    qs[cou++]=u;
}
int main(){
    long long n,q,i,num,st,c;
    scanf("%lld %lld",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%lld",&num);
        g[num].push_back(i);
        if(num==0)st=i;
    }
    dfs(st);
    for(i=1;i<=n;i++){
        for(auto x:g[i]){
            g2[i].push_back({x,Max[x]});
        }
        sort(g2[i].begin(),g2[i].end());
    }
    play(st);
    for(i=1;i<=n;i++){
        qs[i]+=qs[i-1];
    }
    long long now=0;
    while(q--){
        scanf("%lld",&c);
        if(c==1){
            scanf("%lld",&num);
            now+=num;
            printf("%lld\n",qs[now]-qs[now-1]);
        }
        if(c==2){
            scanf("%lld",&num);
            now-=num;
        }
        if(c==3){
            printf("%lld\n",qs[now]);
        }
    }
    return 0;
}
/*
7 5
7 7 5 0 4 4 4
1 3
1 1
3
1 3
3
*/
