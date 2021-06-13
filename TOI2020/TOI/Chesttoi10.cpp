#include <bits/stdc++.h>
using namespace std;
struct A{
    long long idx,mul;
    bool operator<(const A&o)const{
        return idx<o.idx;
    }
};
A ev[400100];
long long cou[12];
vector<pair<long long,long long>> Plus[10];
int main(){
    long long n,m,tt=0,Max=0,ans=0,mul,i,j,temp;
    scanf("%lld %lld",&n,&m);
    Plus[2].push_back({2,1});
    Plus[3].push_back({3,1});
    Plus[4].push_back({2,2});
    Plus[5].push_back({5,1});
    Plus[6].push_back({2,1}),Plus[6].push_back({3,1});
    Plus[7].push_back({7,1});
    Plus[8].push_back({2,3});
    Plus[9].push_back({3,2});
    Plus[10].push_back({2,1}),Plus[10].push_back({5,1});
    while(n--){
        scanf("%lld %lld %lld",&mul,&i,&j);
        ev[tt++]={i,mul};
        ev[tt++]={j+1,-mul};
    }
    ev[tt]={m+1,0};
    sort(ev,ev+tt);
    for(i=0;i<tt;){
        do{
            if(ev[i].mul>0){
                for(auto x:Plus[ev[i].mul]){
                    cou[x.first]+=x.second;
                }
            }
            else{
                for(auto x:Plus[-ev[i].mul]){
                    cou[x.first]-=x.second;
                }
            }
            i++;
        }
        while(i!=tt-1 && ev[i-1].idx==ev[i].idx);
        temp=1;
        for(j=2;j<=9;j++)temp*=(cou[j]+1);
        if(temp>Max){
            Max=temp;
            ans=ev[i].idx-ev[i-1].idx;
        }
        else if(temp==Max){
            ans+=ev[i].idx-ev[i-1].idx;
        }
    }
    printf("%lld %lld\n",Max,ans);
}
/*
5 10
3 0 4
2 2 3
5 4 7
6 7 9
2 3 3

5 5
6 1 2
6 2 3
6 4 5
1 1 1
1 1 1
*/
