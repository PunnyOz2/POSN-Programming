/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long num,com;
    bool operator<(const A&o)const{
        return com>o.com;
    }
};
vector<A> g;
long long cou[1000100];
int main()
{
    long long a,b,c,d,ansa,ansb,temp,i,j,l,r,Max=-1;
    scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
    for(i=2;i<=d;i++){
        if(cou[i]==0){
            for(j=1;j<=d/i;j++){
                temp=j*i;
                while(temp%i==0)temp/=i,cou[j*i]++;
            }
        }
    }
    for(i=2;i<=b;i++){
        g.push_back({i,cou[i]});
    }
    sort(g.begin(),g.end());
    for(i=0;i!=g.size();i++){
        l=b/g[i].num;
        r=d/g[i].num;
        if(Max!=-1 &&i!=0&& g[i].com!=g[i-1].com)break;
        if(a<=g[i].num*l && g[i].num*l<=b && c<=g[i].num*r && g[i].num*r<=d){
            if(Max==g[i].num*l+g[i].num*r &&ansa<g[i].num*l){
                Max=g[i].num*l+g[i].num*r;
                ansa=g[i].num*l;
                ansb=g[i].num*r;
            }
            if(Max<g[i].num*l+g[i].num*r){
                Max=g[i].num*l+g[i].num*r;
                ansa=g[i].num*l;
                ansb=g[i].num*r;
            }
        }
    }
    printf("%lld %lld\n",ansa,ansb);
    return 0;
}
/*
2 8 10 12
*/
