/*
    TASK:Oh my god
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long finddis(pair<long long,long long>x,pair<long long,long long>y){
    long long tx=abs(y.first-x.first);
    long long ty=abs(y.second-x.second);
    if(tx==ty)return tx;
    if(tx>ty)return ty+min(abs(tx-ty),abs(tx+ty));
    if(tx<ty)return tx+((min(abs(tx-ty),abs(tx+ty))+1)/2)*2;
}
struct A{
    long long x,y;
};
struct B{
    long long u,w;
    bool operator<(const B&o)const{
        return w>o.w;
    }
};
A a[210][210];
vector<A> g;
vector<int> g2[210];
map<pair<long long,long long>,long long>mp;
long long dis[210];
pair<long long,long long> poi[210];
priority_queue<B> q;
int main()
{
    long long m,Q,i,x,y,xx,yy,idx=1,temp,j,k,ch,ch1,u,w;
    scanf("%lld %lld",&m,&Q);
    for(i=1;i<=m;i++){
        scanf("%lld %lld %lld %lld",&x,&y,&xx,&yy);
        if(mp[{x,y}]==0)mp[{x,y}]=idx,poi[idx++]={x,y};
        if(mp[{xx,yy}]==0)mp[{xx,yy}]=idx,poi[idx++]={xx,yy};
        g2[mp[{x,y}]].push_back(mp[{xx,yy}]);
        g2[mp[{xx,yy}]].push_back(mp[{x,y}]);
    }
    while(Q--){
        temp=idx;
        ch=0;
        ch1=0;
        for(i=1;i<=202;i++){
            dis[i]=1<<30;
        }
        scanf("%lld %lld %lld %lld",&x,&y,&xx,&yy);
        if(mp[{x,y}]==0)mp[{x,y}]=temp,poi[temp++]={x,y},ch=1;
        if(mp[{xx,yy}]==0)mp[{xx,yy}]=temp,poi[temp++]={xx,yy},ch1=1;
        dis[mp[{x,y}]]=0;
        q.push({mp[{x,y}],0});
        while(!q.empty()){
            u=q.top().u;
            w=q.top().w;
            q.pop();
            for(auto x:g2[u]){
                if(dis[x]>dis[u]+1)dis[x]=dis[u]+1,q.push({x,dis[x]});
            }
            for(i=1;i<=temp;i++){
                if(u==i)continue;
                if(dis[i]>dis[u]+finddis(poi[i],poi[u]))dis[i]=dis[u]+finddis(poi[i],poi[u]),q.push({i,dis[i]});
            }
        }
        printf("%lld\n",dis[mp[{xx,yy}]]);
        if(ch==1)mp[{x,y}]=0;
        if(ch1==1)mp[{xx,yy}]=0;
    }
    return 0;
}
/*
0 1
0 0 0 1

1 2
0 0 10 10
1 0 11 10
10 0 11 2

0 199
0 0 -5 7
*/
