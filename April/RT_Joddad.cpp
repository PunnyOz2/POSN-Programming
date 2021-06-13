/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
double a[250][250];
double dis[250];
struct A{
    int u;
    double dis,speed;
    bool operator<(const A&o)const{
        return dis>o.dis;
    }
};
priority_queue<A> dijk;
int main()
{
	int n,m,q,u,v,i,j;
	char opr[10];
	double w,speed,fat;
	scanf("%d %d %d",&n,&m,&q);
	for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i!=j)    a[i][j]=LONG_LONG_MAX;
	for(i=0;i<m;i++){
        scanf("%d %d %lf",&u,&v,&w);
        a[v][u]=a[u][v]=min(a[u][v],w);
	}
	while(q--){
        scanf(" %s",opr);
        if(opr[0]=='t'){
            for(i=1;i<=n;i++)
                dis[i]=LONG_LONG_MAX;
            scanf("%d %d %lf %lf",&u,&v,&speed,&fat);
            dis[u]=0;
            dijk.push({u,0,speed});//u dis left.speed
            while(!dijk.empty()){
                u=dijk.top().u;
                w=dijk.top().dis;
                speed=dijk.top().speed;
                dijk.pop();
                if(u==v){printf("%.2lf\n",dis[v]);goto jump;}
                if(speed<=0.0)  continue;
                for(i=1;i<=n;i++){
                    if(u==i)    continue;
                    if(a[u][i]!=LONG_LONG_MAX && dis[i]>w+a[u][i]/speed){
                        dis[i]=w+a[u][i]/speed;
                        dijk.push({i,dis[i],speed-fat*a[u][i]});
                    }
                }
            }
            printf("IMPOSSIBLE\n");
            jump:;
            while(!dijk.empty())dijk.pop();
        }
        if(opr[0]=='d'){
            scanf("%d",&u);
            for(i=1;i<=n;i++){
                if(i==u)    continue;
                a[u][i]=a[i][u]=LONG_LONG_MAX;
            }
        }
        if(opr[0]=='a'){
            int nn;
            scanf("%d %d",&u,&nn);
            for(i=0;i<nn;i++){
                scanf("%d %lf",&v,&w);
                a[v][u]=a[u][v]=min(a[u][v],w);
            }
        }
	}
    return 0;
}
/*
5 10 8
1 2 5.0
1 1 5.5
3 1 6.0
1 3 7.0
2 1 3.0
2 2 9.5
3 3 8.5
4 4 10.0
5 5 11.0
1 2 5.5
travel 2 3 10.0 1.0
travel 2 4 6.0 0.0
destroy 4
add 4 1
3 15.5
travel 1 4 3.5 0.1
destroy 2
add 2 3
1 1.0
3 3.0
5 5.0
travel 4 5 1.0 0.2
*/
