/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,w;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
priority_queue<A> q;
int p[1010],cou[1010];
int fin(int i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
int main()
{
    int Q,n,i,j,num,w,pu,pv,Max,Maxx,cc;
    scanf("%d",&Q);
    while(Q--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            p[i]=i;
            for(j=1;j<=n;j++){
                scanf("%d",&num);
                if(i<j)q.push({i,j,num});
            }
        }
        cc=0;
        while(!q.empty() && cc<n-1){
            i=q.top().i;
            j=q.top().j;
            q.pop();
            pu=fin(i);
            pv=fin(j);
            if(pu!=pv){
                cc++;
                p[pu]=pv;
                cou[i]++;
                cou[j]++;
            }
        }
        while(!q.empty())q.pop();
        Max=-1;
        for(i=1;i<=n;i++){
            if(Max<cou[i]){
                Max=cou[i];
                Maxx=i;
            }
        }
        printf("%d %d\n",Maxx,Max);
        memset(cou,0,sizeof cou);
    }
    return 0;
}
/*
1
4
0 7 12 8
7 0 5 1
12 5 0 6
8 1 6 0
*/
