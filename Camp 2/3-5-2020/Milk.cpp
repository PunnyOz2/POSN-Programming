/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int num,a,b;
    bool operator<(const A&o)const{
        return num>o.num;
    }
};
priority_queue<A> q;
int p[1000000],a[1000100][3];
int fin(int i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
int main()
{
    int n,Q,b,pu,pv,i,m,cou,j,num,u,v;
    scanf("%d",&Q);
    while(Q--){
        scanf("%d %d",&n,&m);
        cou=0;
        for(i=1;i<=n;i++){
            p[i]=i;
        }
        for(i=1;i<=n;i++){
            scanf("%d %d",&a[i][0],&a[i][1]);
        }
        for(i=1;i<n;i++){
            for(j=i+1;j<=n;j++){
                q.push({abs(a[i][0]-a[j][0])+abs(a[i][1]-a[j][1]),i,j});
            }
        }
        while(!q.empty()){
            if(n-cou<=m){
                break;
            }
            num=q.top().num;
            u=q.top().a;
            v=q.top().b;
            pu=fin(u);
            pv=fin(v);
            q.pop();
            if(pu!=pv){
                p[pu]=pv;
                cou++;
            }
        }
        while(!q.empty()){
            u=q.top().a;
            v=q.top().b;
            num=q.top().num;
            pu=fin(u);
            pv=fin(v);
            q.pop();
            if(pu!=pv){
                printf("%d\n",num);
                break;
            }
        }
        while(!q.empty())q.pop();
    }
    return 0;
}
/*
2
3 2
0 0
2 2
3 2
6 2
0 1
0 0
1 0
2 2
2 3
3 2
*/
