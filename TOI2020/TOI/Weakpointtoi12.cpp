#include <bits/stdc++.h>
using namespace std;
int cou[500100],in[500100];
vector<int> g[500100];
queue<pair<int,int>>q;
int main(){
    int n,st,i,u,v,Max,ans,temp,ch,p;
    scanf("%d %d",&n,&st);
    for(i=1;i<=n;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
        in[u]++;
        in[v]++;
    }
    for(i=1;i<=n;i++){
        if(in[i]==1){
            q.push({i,0});
            while(!q.empty()){
                u=q.front().first;
                p=q.front().second;
                q.pop();
                for(auto x:g[u]){
                    if(x==p)continue;
                    if(in[x]==0)continue;
                    in[x]--;
                    in[u]--;
                    cou[x]+=cou[u]+1;
                    if(in[x]==1)q.push({x,u});
                }
            }
        }
    }
    if(in[st]==0){
        Max=0;
        for(auto x:g[st]){
            if(in[x]!=0 || cou[x]>cou[st]){
                temp=n-cou[st]-1-1;
                if(Max<temp){
                    Max=temp;
                    ans=x;
                }
            }
            else if(Max<cou[x]){
                Max=cou[x];
                ans=x;
            }
        }
        printf("%d\n%d",ans,Max);
    }
    else
    {
        Max=0;
        ch=0;
        for(i=1;i<=n;i++){
            if(i!=st){
                if(Max<cou[i]){
                    Max=cou[i];
                    ans=i;
                    ch=1;
                }
            }
        }
        if(ch==1)printf("%d\n%d",ans,Max);
        else{
            if(st==1)printf("2\n");
            else printf("1\n");
            printf("%d\n",Max);
        }
    }
}
/*
12 8
1 2
1 6
1 7
1 12
6 8
6 9
2 3
2 10
10 11
3 4
4 5
5 12

5 2
1 2
2 3
3 4
4 5
5 1

5 1
1 2
2 3
3 4
4 1
4 5
*/
