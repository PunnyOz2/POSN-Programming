#include <bits/stdc++.h>
using namespace std;
int dis[15100];
int pos[15100][3];
priority_queue<int> q;
int main(){
    int n,k,i,j,Min,temp;
    long long sum=0;
    scanf("%d %d",&n,&k);
    k--;
    for(i=1;i<=n;i++){
        scanf("%d %d",&pos[i][0],&pos[i][1]);
        dis[i]=1<<30;
    }
    for(i=1;i<n;i++){
        Min=1<<30;
        for(j=i+1;j<=n;j++){
            dis[j]=min(dis[j],abs(pos[i][0]-pos[j][0])+abs(pos[i][1]-pos[j][1]));
            if(dis[j]<Min){
                Min=dis[j];
                temp=j;
            }
        }
        sum+=Min;
        q.push(Min);
        swap(dis[i+1],dis[temp]);
        swap(pos[i+1],pos[temp]);
    }
    while(!q.empty()&&k--)sum-=q.top(),q.pop();
    printf("%lld\n",sum);
}
/*
5 2
2 9
9 7
14 2
12 9
16 4
*/
