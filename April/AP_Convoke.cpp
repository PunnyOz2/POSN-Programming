/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int puen[20],disfoyld[230][230],dis[230][1<<18];
struct A{
    int u,w,puen;
    bool operator<(const A& o)const{
        return w>o.w;
    }
};
priority_queue<A> h;
int main()
{
	int n,m,k,u,v,w,i,j,bit,kk;
	scanf("%d %d %d",&n,&m,&k);
	for(i=0;i<k;i++){
        scanf("%d",&puen[i]);
	}
	for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i!=j)disfoyld[i][j]=1<<20;
        }
	}
	for(i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&w);
        disfoyld[u][v]=disfoyld[v][u]=w;
	}
    for(kk=1;kk<=n;kk++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                disfoyld[i][j]=min(disfoyld[i][kk]+disfoyld[kk][j],disfoyld[i][j]);
            }
        }
	}
	h.push({1,0,0});
	int ans=(1<<k)-1;
	for(i=1;i<=n;i++){
        for(j=0;j<=ans;j++)dis[i][j]=1<<20;
	}
	//for(i=1;i<=n;i++){
    //       for(j=1;j<=n;j++){
    //            printf("%d ",disfoyld[i][j]);
    //        }
    //        printf("\n");
    //    }
	while(!h.empty()){
        u=h.top().u,w=h.top().w,bit=h.top().puen,h.pop();
        //printf("%d %d %d\n",u,w,bit);
        for(i=0;i<k;i++){
            if(u!=puen[i] && w+disfoyld[u][puen[i]]<dis[puen[i]][bit|(1<<i)])dis[puen[i]][bit|(1<<i)]=w+disfoyld[u][puen[i]],h.push({puen[i],w+disfoyld[u][puen[i]],bit|(1<<i)});
        }
        if(u!=1 && w+disfoyld[u][1]<dis[1][bit])dis[1][bit]=w+disfoyld[u][1],h.push({1,w+disfoyld[u][1],bit});
        if(u!=n && w+disfoyld[u][n]<dis[n][bit])dis[n][bit]=w+disfoyld[u][n],h.push({n,w+disfoyld[u][n],bit});
	}
	printf("%d",dis[n][ans]);
    return 0;
}
/*
7 10 1
4
1 2 1
1 3 2
4 1 2
2 4 2
3 4 1
4 5 1
4 6 3
5 7 1
7 6 2
4 7 4
*/
