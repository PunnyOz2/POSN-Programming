/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[100003],rev[100003];
int degin[100003],mk[100003];
int level[100003],dp[100003];
priority_queue<pair<int,int>> heap;
int main()
{
    int n,k,t;
    scanf("%d %d %d",&n,&k,&t);
    for(i=1;i<=n;i++){
        scanf("%d %d",&level[i],&a);
        for(j=0;j<a;j++){
            scanf("%d",&b);
            g[i].push_back(b);
            degin[b]++;
        }
    }
    for(i=1;i<=n;i++){
        if(degin[i]){
            mk[i]=1;
            bfs.push(i);
        }
    }
    while(!bfs.empty()){
        int now=bfs.front();
        for(int e:g[now]){
            degin[e]--;
            if(degin[e]==0){
                mk[e]=1;
                bfs.push(e);
            }
        }
    }
    for(i=1;i<=n;i++){
        if(!mk[i])continue;
        for(int e:g[i]){
            if(mk[e]){
                rev[e].push_back(i);degin[i]++;
            }
        }
    }
    for(i=1;i<=n;i++){
        dp[i]=level[i];
        if(!mk[i])continue;
        if(!degin[i])bfs.push(i);
    }
    while(!bfs.empty()){
        int now=bfs.front();
        bfs.pop();
        for(int e:rev[now]){
            degin[e]--;
            dp[e]=min(dp[e],dp[now]);
            if(!degin[e])bfs.push(e);
        }
    }
    for(i=1;i<+n;i++){
        if(!mk[i])continue;
        for(int e:g[i])degin[e]++;
    }
    for(i=1;i<=n;i++){
        if(!mk[i]||!degin[i])continue;
        heap.push({-dp[i],i});
    }
    while(!heap.empty()){
        int now=heap.top().second;
        heap.pop();
        ans[level[now]]++;
        for(int e:g[now]){
            if(!mk[e])continue;
            degin[e]--;
            if(!degin[e])heap.push(e);
        }
    }
    return 0;
}
