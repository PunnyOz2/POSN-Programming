/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[120][120];
int p[20020];
int l(int i,int j)
{
    int node=m*(i-1)+j;
    return node*2-1;
}
int r(int i,int j)
{
    int node=m*(i-1)+j;
    return node*2;
}
int fin(int i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
struct A{
    int i,j,w;
    bool operator<(const A& o)const{
        return w>o.w;
    }
};
priority_queue<A> q;
int main()
{
    int i,j,num,pu,pv;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf(" %c",&a[i][j]);
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&num);
            q.push({i,j,num});
        }
    }
    for(i=1;i<=n*m*2;i++)p[i]=i;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(j-1>0){
                pu=fin(l(i,j)),pv=fin(r(i,j-1));
                if(pu!=pv){
                    p[pv]=pu;
                }
            }
            if(a[i][j]=='/'){
                if(i-1==0)continue;
                if(a[i-1][j]=='/'){
                    pu=fin(l(i,j)),pv=fin(r(i-1,j));
                    if(pu!=pv){
                        p[pv]=pu;
                    }
                }
                if(a[i-1][j]=='\\'){
                    pu=fin(l(i,j)),pv=fin(l(i-1,j));
                    if(pu!=pv){
                        p[pv]=pu;
                    }
                }
            }
            else{
                if(i-1==0)continue;
                if(a[i-1][j]=='/'){
                    pu=fin(r(i,j)),pv=fin(r(i-1,j));
                    if(pu!=pv){
                        p[pv]=pu;
                    }
                }
                if(a[i-1][j]=='\\'){
                    pu=fin(r(i,j)),pv=fin(l(i-1,j));
                    if(pu!=pv){
                        p[pv]=pu;
                    }
                }
            }
        }
    }
    int sum=0,w;
    while(!q.empty()){
        i=q.top().i;
        j=q.top().j;
        w=q.top().w;
        q.pop();
        pu=fin(l(i,j)),pv=fin(r(i,j));
        //printf("%d %d %d %d\n",i,j,pu,pv);
        if(pu!=pv){
            p[pv]=pu;
            sum+=w;
        }
    }
    printf("%d\n",sum);
    return 0;
}
/*
2 2
\/
\\
7 10
12 9
*/
