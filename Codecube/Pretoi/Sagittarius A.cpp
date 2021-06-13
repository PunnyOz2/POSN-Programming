/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long u,v,w,i;
    bool operator<(const A&o)const{
        return w<o.w;
    }
};
priority_queue<A> q,q2;
vector<long long> ans;
long long p[100100];
long long fin(long long i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
int main()
{
    long long n,m,i,u,v,w,pu,pv;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        q.push({u,v,w,i});
    }
    for(i=1;i<=n;i++)p[i]=i;
    long long sum=0;
    while(!q.empty()){
        u=q.top().u;
        v=q.top().v;
        w=q.top().w;
        i=q.top().i;
        q.pop();
        pu=fin(u);
        pv=fin(v);
        if(pu!=pv){
            p[pu]=pv;
            sum+=w;
            ans.push_back(i);
            //cou++;
        }
        else{
            q2.push({u,v,w,i});
        }
        //if(cou==n-1)break;
    }
    if(!q2.empty()){
        u=q2.top().u;
        v=q2.top().v;
        w=q2.top().w;
        i=q2.top().i;
        sum+=w;
        ans.push_back(i);
    }
    long long t;
    scanf("%lld",&t);
    if(m<n){printf("-1\n");return 0;}
    if(t==1){
        for(i=1;i<n;i++){
            if(fin(i)!=fin(i+1)){printf("-1\n");return 0;}
        }
        printf("%lld\n",sum);
    }
    else if(t==2){
        for(i=1;i<n;i++){
            if(fin(i)!=fin(i+1)){printf("-1\n");return 0;}
        }
        printf("%lld\n",sum);
        sort(ans.begin(),ans.end());
        for(auto x:ans)printf("%lld ",x);
    }
    return 0;
}
/*
6 7
1 2 5
1 6 7
2 3 17
2 4 3
5 2 11
2 6 2
3 6 13
2

10 15
1 2 14
1 2 5
3 2 7
3 4 9
2 4 8
4 5 3
4 6 5
5 6 1
8 6 18
8 7 7
8 9 9
8 1 2
9 10 20
9 6 13
10 1 28

*/
