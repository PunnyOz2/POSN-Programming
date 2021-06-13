/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,w,state;
    bool operator<(const A&o)const{
        return w<o.w;
    }
};
priority_queue<A> q;
int a[1010][1010];
int main()
{
    int Q,n,m,i,j,state,w;
    scanf("%d",&Q);
    while(Q--){
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                scanf("%d",&a[i][j]);
            }
        }
        q.push({1,1,0,0});
        q.push({1,1,a[1][1],1});
        while(!q.empty()){
            i=q.top().i;
            j=q.top().j;
            w=q.top().w;
            state=q.top().state;
            q.pop();
            if(i==n && j==m){
                printf("%d\n",w);

            }
            if(i+1<=n){
                if(state<2)q.push({i+1,j,a[i+1][j]+w,state+1});
                q.push({i+1,j,w,0});
            }
            if(j+1<=n){
                if(state<2)q.push({i,j+1,a[i][j+1]+w,state+1});
                q.push({i,j+1,w,0});
            }
        }
    }
    return 0;
}
