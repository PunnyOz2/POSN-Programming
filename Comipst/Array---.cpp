/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long opr,a,b,val;
};
A ar[200100];
vector<long long > comp;
long long se[800100],lazy[800100];
void update(long long l,long long r,long long a,long long b,long long val,long long now){
    if(lazy[now]!=1e10){
        if(l!=r)    lazy[now*2]=lazy[now],lazy[now*2+1]=lazy[now];
//        if(comp[l-1]!=-1)se[now]=(lazy[now]*(comp[r]-comp[l-1]+1));
//        else se[now]=(lazy[now]*(comp[r]+1));
        se[now] = (comp[r]-comp[l])*lazy[now];
        lazy[now]=1e10;
    }
    if(r<a||l>b)    return;
    if(a<=l && r<=b){
        printf("%lld %lld %lld %lld\n",l,comp[l],r,comp[r]);
        se[now]=(val*(comp[r]-comp[l]));
        if(l!=r)    lazy[now*2]=val,lazy[now*2+1]=val;
        return;
    }
    long long mid =(l+r)/2;
    update(l,mid,a,b,val,now*2);
    update(mid+1,r,a,b,val,now*2+1);
    se[now] = se[now*2]+se[now*2+1];
}
long long query(long long l,long long r,long long a,long long b,long long now){
    if(lazy[now]!=1e10){
        if(l!=r)    lazy[now*2]=lazy[now],lazy[now*2+1]=lazy[now];
//        if(comp[l-1]!=-1)se[now]=(lazy[now]*(comp[r]-comp[l-1]+1));
//        else se[now]=(lazy[now]*(comp[r]+1));
        se[now] = (comp[r]-comp[l])*lazy[now];
        lazy[now]=1e10;
    }
    if(r<a||l>b)        return 0;
    if(a<=l && r<=b)    return se[now];
    long long mid=(l+r)/2;
    return query(l,mid,a,b,now*2)+query(mid+1,r,a,b,now*2+1);
}
int main()
{
    long long n,m,i=0,num,q,opr,b,c,val,l,r,Q=0,cou=0;
    scanf("%lld %lld",&n,&q);
    while(q--){
        scanf("%lld",&opr);
        if(opr==0){
            scanf("%lld %lld %lld",&c,&b,&val);
            comp.push_back(c);
            comp.push_back(b);
            ar[Q++]={opr,c,b,val};
        }
        if(opr==1){
            scanf("%lld %lld",&c,&b);
            ar[Q++]={opr,c,b,0};
            comp.push_back(c);
            comp.push_back(b);
        }
    }
    comp.push_back(-1);
    sort(comp.begin(),comp.end());
    comp.resize(unique(comp.begin(),comp.end())-comp.begin());
    cou = comp.size();
    cou--;
    for(i=1;i<=800010;i++){
        lazy[i]=1e10;
    }
    //for(auto x : comp)  printf("%d ",x);
    //printf("\n");
    for(i=0;i<Q;i++){
        l=lower_bound(comp.begin(),comp.end(),ar[i].a)-comp.begin();
        r=lower_bound(comp.begin(),comp.end(),ar[i].b)-comp.begin();
        printf("%lld->%lld %lld->%lld\n",ar[i].a,l,ar[i].b,r);
        if(ar[i].opr==0){
            update(1,cou,l,r,ar[i].val,1);
        }else if(ar[i].opr==1){
            printf("%lld\n",query(1,cou,l,r,1));
        }
    }
    return 0;
}
/*
10
6
1 0 10
0 0 5 1
1 0 10
0 5 10 2
1 0 10
1 3 8

100
10
1 0 2
0 0 100 2
0 4 10 3
1 9 11
1 4 10
0 9 11 5
1 9 11
0 4 10 4
1 4 10
1 0 10
*/
