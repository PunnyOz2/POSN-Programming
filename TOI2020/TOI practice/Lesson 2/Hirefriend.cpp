#include<bits/stdc++.h>
using namespace std;
struct A{
    long long i,val;
    bool operator<(const A&o)const{
        return i<o.i;
    }
};
vector<A> g;
int main(){
    long long n,Max=0,i,now,sum,x,y;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld %lld",&x,&y);
        g.push_back({x,1});
        g.push_back({y+1,-1});
        //Max=max(y,Max);
    }
    sort(g.begin(),g.end());
    //g.push_back(Max+1)
    now=0;
    sum=0;
    for(i=0;i<g.size();i++){
        now+=g[i].val;
        if(g[i].i==g[i+1].i)i++,now+=g[i].val;
        if(now>1)sum+=(now-1)*(g[i+1].i-g[i].i);
    }
    printf("%lld\n",sum);
    return 0;
}
/*
3
1 5
4 8
3 11

4
2 5
6 8
9 12
14 19
*/
