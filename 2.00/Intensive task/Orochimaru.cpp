/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
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
int dis[110][110];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",dis[i]);
    for(i=0;i<n;i++){
        q.push(i,0,0);
        while(!q.empty()){
            ii=q.top().i,jj=q.top().j,w=q.top().w,q.pop();
            if(dis[ii][jj]<w)continue;
            if(jj==(m-1))break;
            for(j=-1;j<=1;j++){
                if(ii+j<0 && w<dis[n-1][jj+1])q.push(n-1,jj+1),dis;
                else if(ii+j>=n && w<dis[n-1][jj+1])q.push(0,jj+1);
                else if(w<dis[n-1][jj+1])q.push(ii+j,jj+1);
            }
        }

    }
    return 0;
}
