/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[110][110];
long long dis[110][110];
struct A{
    long long i,j,w;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
priority_queue<A> q;
long long di[8]={1,-1,0,0,1,-1,-1,1},dj[8]={0,0,1,-1,1,-1,1,-1};
int main()
{
    long long Q,n,m,sti,stj,i,j,w,Max=0,idxi,idxj,k,ni,nj,temp;
    scanf("%lld",&Q);
    while(Q--){
        Max=-1;
        scanf("%lld %lld",&n,&m);
        for(i=1;i<=n;i++){
            scanf(" %s",a[i]+1);
            for(j=1;j<=m;j++){
                dis[i][j]=1<<30;
                if(Max<a[i][j]-'0' && a[i][j]!='#'){
                    Max=a[i][j]-'0';
                    idxi=i;
                    idxj=j;
                }
            }
        }
        scanf("%lld %lld",&sti,&stj);
        sti++;stj++;
        dis[sti][stj]=0;
        q.push({sti,stj,0});
        while(!q.empty()){
            i=q.top().i;
            j=q.top().j;
            w=q.top().w;
            if(i==idxi && j==idxj){
                printf("%lld\n",dis[idxi][idxj]);
                break;
            }
            q.pop();
            for(k=0;k<8;k++){
                ni=i+di[k];
                nj=j+dj[k];
                if(ni<1 || nj<1 || ni>n||nj>m)continue;
                if(a[ni][nj]=='#')continue;
                temp=( abs( (a[ni][nj]-'0') - (a[i][j]-'0') )+1 )*( abs( (a[ni][nj]-'0') - (a[i][j]-'0') )+1 );
                //printf("%lld\n",temp);
                if(dis[ni][nj]>dis[i][j]+temp){
                    dis[ni][nj]=dis[i][j]+temp;
                    q.push({ni,nj,dis[ni][nj]});
                }
            }
        }
        while(!q.empty()){
            q.pop();
        }
        if(dis[idxi][idxj]==1<<30)printf("NO\n");
    }
    return 0;
}
/*

*/
