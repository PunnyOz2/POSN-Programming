#include <bits/stdc++.h>
using namespace std;
int a[1010][4];
struct A{
    int dis,a,b;
    bool operator<(const A&o)const{
        return dis>o.dis;
    }
};
priority_queue<A>q;
int p[1100],mark[1010];
int fin(int i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
int main(){
    int Q,n,k,i,j,dis,pu,pv,cou,ans;
    scanf("%d",&Q);
    while(Q--){
        scanf("%d %d",&n,&k);
        for(i=1;i<=n;i++){
            scanf("%d %d",&a[i][1],&a[i][2]);
        }
        for(i=1;i<=n;i++){
            p[i]=i;
        }
        for(i=1;i<n;i++){
            for(j=i+1;j<=n;j++){
                dis=abs(a[i][1]-a[j][1])+abs(a[i][2]-a[j][2]);
                q.push({dis,i,j});
            }
        }
        cou=0;
        while(!q.empty()){
            i=q.top().a;
            j=q.top().b;
            dis=q.top().dis;
            pu=fin(i);
            pv=fin(j);
            if(pu!=pv)p[pu]=pv,cou++;
            q.pop();
            if(n-cou==k-1){
                printf("%d\n",dis);
                break;
            }
        }
        int ch=0;
        /*while(!q.empty()){
            i=q.top().a;
            j=q.top().b;
            dis=q.top().dis;
            pu=fin(i);
            pv=fin(j);
            q.pop();
            if(pu!=pv){printf("%d\n",dis);ch=1;break;}
        }*/
        while(!q.empty())q.pop();
    }
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
