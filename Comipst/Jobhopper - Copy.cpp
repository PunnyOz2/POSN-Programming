/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[3100],temp[3030],in[3030];
struct A{
    int u,w,cou;
};
vector<A> g[4000];
queue<A> q;
int mx[3005];
int main()
{
    int n,m,i,num,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&num);
        a[i]=num;
    }
    int l,r,mid,ch,u,cou,tempp;
    l=0,r=n-1;
    while(l<r){
        mid=(l+r) >> 1;
        ch=0;
        for(i=1;i<=n;i++){
            for(j=i+1;j<=i+mid;j++){
                tempp = j;
                if(j>n)tempp-=n;
                if(a[tempp]>a[i])g[i].push_back({tempp,0,0}),in[tempp]++;
            }
        }
        for(i=1;i<=n;i++){
            if(!in[i])
                q.push({i,0,0});
        }
        while(!q.empty()){
            u=q.front().u;
            cou=q.front().cou;
//            printf("%d %d %d\n",u,cou,mid);
            q.pop();
            if(cou==m){
                ch=1;
                break;
            }
            for(auto x:g[u]){
                mx[x.u] = mx[x.u] > mx[u]+1 ? mx[x.u] : mx[u]+1 ;
                in[x.u]--;
                if(!in[x.u]){
                    q.push({x.u,0,mx[x.u]});
                }
            }
        }
        if(ch){
            r=mid;
        }
        else{
            l=mid+1;
        }
        while(!q.empty())   q.pop();
        memset(in,0,sizeof in);
        memset(mx,0,sizeof mx);
        for(i=1;i<=n;i++){
            g[i].clear();
        }
    }
    printf("%d\n",l);
    return 0;
}
