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
    long long q,i,a,b,n,x,y,z,Max,cou,coujob;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld %lld %lld",&n,&x,&y,&z);
        Max=x*n;
        for(i=1;i<=n;i++){
            scanf("%lld %lld",&a,&b);
            g.push_back({a,1});
            g.push_back({b+1,-1});
        }
        sort(g.begin(),g.end());
        cou=0;
        coujob=0;
        for(i=0;i<g.size();i++){
            if(g[i].val==1)cou++;
            if(g[i].val==-1)cou--,coujob++;
            while(g[i].i==g[i+1].i){
                i++;
                if(g[i].val==1)cou++;
                if(g[i].val==-1)cou--,coujob++;
            }
            //printf("%lld %lld %lld %lld\n",g[i].i,cou,coujob,n-cou-coujob);
            Max=max(Max,coujob*z+(cou)*y+(n-cou-coujob)*x);
        }
        printf("%lld\n",Max);
        g.clear();
    }
    return 0;
}
/*
1
4 7 9 6
5 8
3 4
13 20
7 10
*/
