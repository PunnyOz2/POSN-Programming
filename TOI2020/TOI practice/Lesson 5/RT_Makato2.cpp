#include<bits/stdc++.h>
using namespace std;
long long qs[100100],a[100100],pa[100100];
vector<long long> g[100100];
void play(long long u,long long p){
    qs[u]=a[u];
    for(auto x:g[u]){
        if(x==p)continue;
        pa[x]=u;
        play(x,u);
        qs[u]^=qs[x];
    }
}
int main(){
    long long n,i,u,v,Min,sum;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(i=1;i<=n-1;i++){
        scanf("%lld %lld",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    play(1,0);
    Min=1<<30;
    for(i=1;i<=n;i++){
        sum=0;
        for(auto x:g[i]){
            if(pa[i]==x){
                sum+=qs[1]^qs[i];
            }
            else{
                sum+=qs[x];
            }
        }
        Min=min(sum,Min);
    }
    printf("%lld\n",Min);
    return 0;
}
/*
5
7 3 8 5 2
4 3
1 5
3 2
3 1
*/
