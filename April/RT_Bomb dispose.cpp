/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int defuse,u,w,bit,cou;
};
deque<A> q;
int a[20];
int mark[20][20][1<<17];
int main()
{
	int Q,n,p,i,defuse,u,w,cou,bit,j,k;
	scanf("%d",&Q);
	while(Q--){
        scanf("%d %d",&n,&p);
        for(i=0;i<=n;i++){
            for(j=0;j<=n;j++){
                for(k=0;k<=(1<<(n+1));k++)mark[i][j][k]=1<<30;
            }
        }
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(i=1;i<=n;i++){
            if(a[i]==1)q.push_back({1,i,0,0,0}),mark[0][i][0]=0;
            else
                q.push_back({0,i,0,0,0}),mark[0][i][0]=0;
        }
        while(!q.empty()){
            defuse=q.front().defuse;
            u=q.front().u;
            w=q.front().w;
            bit=q.front().bit;
            cou=q.front().cou;
            q.pop_front();
            if(defuse==n){printf("%d\n",w);break;}
            if((bit&(1<<(defuse+1)))!=0){
                if(mark[defuse+1][u][bit]>w){
                    mark[defuse+1][u][bit]=w;
                    q.push_front({defuse+1,u,w,bit,cou-1});
                }
            }
            if(cou<p && (bit&(1<<a[u]))==0){
                if(mark[defuse][u][bit|(1<<a[u])]>w){
                    mark[defuse][u][bit|(1<<a[u])]=w;
                    q.push_front({defuse,u,w,bit|(1<<a[u]),cou+1});
                }
            }
            if(u+1<=n){
                if(a[u+1]==defuse+1){
                    if(mark[defuse+1][u+1][bit]>w+1){
                        mark[defuse+1][u+1][bit]=w+1;
                        q.push_back({defuse+1,u+1,w+1,bit,cou});
                    }
                }
                else{
                    if(mark[defuse][u+1][bit]>w+1){
                        mark[defuse][u+1][bit]=w+1;
                        q.push_back({defuse,u+1,w+1,bit,cou});
                    }
                }
            }
            if(u-1>0){
                if(a[u-1]==defuse+1){
                    if(mark[defuse+1][u-1][bit]>w+1){
                        mark[defuse+1][u-1][bit]=w+1;
                        q.push_back({defuse+1,u-1,w+1,bit,cou});
                    }
                }
                else{
                    if(mark[defuse][u-1][bit]>w+1){
                        mark[defuse][u-1][bit]=w+1;
                        q.push_back({defuse,u-1,w+1,bit,cou});
                    }
                }
            }
        }
        while(!q.empty())q.pop_back();
	}
    return 0;
}
/*
4
5 0
1 3 4 5 2
5 1
1 3 4 5 2
5 2
1 3 4 5 2
5 3
1 3 4 5 2

4
5 0
1 2 3 4 5

9
6
5
4
*/
