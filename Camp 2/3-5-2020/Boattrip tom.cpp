/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long i,j;
    bool operator<(const A&o)const{
        if(j!=o.j)return j<o.j;
        return i>o.i;
    }
};
vector<A> g;
int main()
{
    long long n,m,Max=0,i,a,b,sum,posj,posi;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%lld %lld",&a,&b);
        if(a<=b)continue;
        g.push_back({b,a});
    }
    sum=m;
    sort(g.begin(),g.end());
//    posj=g[g.size()-1].j;
//    posi=g[g.size()-1].i;
    posi=1e9+1;
    for(i=g.size()-1;i>=0;i--){
        //printf("%d %d\n",g[i].i,g[i].j);
        if(g[i].j<posi){
            posi=g[i].i;
            posj=g[i].j;
        }
        else if(posi<=g[i].j){
            posi=min(posi,g[i].i);
        }
        //printf("    %d %d\n",posi,posj);
        if(i==0 || g[i-1].j<posi){
            sum+=(posj-posi)*2;
        }
    }
    printf("%lld\n",sum);
    return 0;
}
/*
2 15
6 4
2 9
19

6 9
5 3
6 2
3 2
8 5
5 9
1 2
*/
