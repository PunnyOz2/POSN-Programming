/*
    TASK: BUU Climbing
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,w;
    bool operator< (const A&o)const{
        return w>o.w;
    }
};
priority_queue<A> q;
int dis[110][110],di[8]={0,0,1,1,1,-1,-1,-1},dj[8]={1,-1,1,0,-1,1,0,-1};
char a[110][110];
int main()
{
    int Q,r,c,i,j,sti,stj,eni,enj,ma,nowi,nowj,noww,ch,diff,w,ii,jj,k;
    scanf("%d",&Q);
    while(Q--){
        scanf("%d %d",&r,&c);
        for(i=0,ma=-1,ch=1;i<r;i++){
            for(j=0;j<c;j++){
                scanf(" %c",&a[i][j]);
                if(isdigit(a[i][j]) && a[i][j]>ma)
                    ma=a[i][j],eni=i,enj=j;
            }
        }
        scanf("%d %d",&sti,&stj);
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                dis[i][j]=1<<30;
        q.push({sti,stj,0});
        dis[sti][stj]=0;
        while(!q.empty()){
            nowi=q.top().i,nowj=q.top().j,noww=q.top().w;
            q.pop();
            if(nowi==eni&&nowj==enj){
                printf("%d\n",dis[eni][enj]);
                ch=0; break;
            }
            for(k=0;k<8;k++){
                ii=nowi+di[k],jj=nowj+dj[k];
                if(ii<0||jj<0||ii>=r||jj>=c) continue;
                if(a[ii][jj]=='#') continue;
                diff = abs(a[ii][jj]-a[nowi][nowj])+1;
                w = diff*diff;
                if(dis[nowi][nowj]+w<dis[ii][jj]){
                    dis[ii][jj]=dis[nowi][nowj]+w;
                    q.push({ii,jj,dis[ii][jj]});
                }
            }
        }
        if(ch) printf("NO\n");
        while(!q.empty()) q.pop();
    }

    return 0;
}
/*
2
5 5
11111
1###1
12341
12221
12221
0 0
*/
