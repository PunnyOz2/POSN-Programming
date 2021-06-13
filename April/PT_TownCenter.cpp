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
int p[1200];
int fin(int i){
    if(p[i]==i) return i;
    return p[i]=fin(p[i]);
}
priority_queue<A> q;
int line[1200];
int main()
{
	int Q,n,i,j,pu,pv,Max,ans,ansline,num,cou;
	scanf("%d",&Q);
	while(Q--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                scanf("%d",&num);
                if(i!=j)q.push({i,j,num});
            }
        }
        for(i=1;i<=n;i++)p[i]=i;
        cou=0;
        while(!q.empty()){
            i=q.top().i,j=q.top().j,q.pop();
            pu=fin(i),pv=fin(j);
            if(pu!=pv){
                cou++;
                p[pu]=pv;
                line[i]+=1;
                line[j]+=1;
            }
            if(cou==n)break;
        }
        Max=0;
        for(i=1;i<=n;i++){
                //printf("%d ",line[i]);
            if(line[i]>Max)Max=line[i],ans=i,ansline=line[i];
        }
        printf("%d %d\n",ans,ansline);
        memset(line,0,sizeof line);
	}
    return 0;
}
/*
4
7
0 13 5 8 12 17 15
13 0 8 11 15 20 18
5 8 0 3 7 12 10
8 11 3 0 10 15 13
12 15 7 10 0 5 3
17 20 12 15 5 0 8
15 18 10 13 3 8 0

4
0 7 12 8
7 0 5 1
12 5 0 6
8 1 6 0

6
0 1 2 3 4 5
1 0 3 4 5 6
2 3 0 5 6 7
3 4 5 0 7 8
4 5 6 7 0 9
5 6 7 8 9 0

4
0 7 12 8
7 0 5 1
12 5 0 6
8 1 6 0
*/
