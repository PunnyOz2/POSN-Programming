/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int indexx[100100],lowlink[100100],scc[100100],onstack[100100],cnt=1,cnt2=1;
vector<int> g[100100];
stack<int>st;
void dfs(int u){
    indexx[u]=lowlink[u]=cnt++,onstack[u]=1;
    st.push(u);
    for(auto x:g[u]){
        if(indexx[x]==0){
            dfs(x);
            lowlink[u]=min(lowlink[u],lowlink[x]);
        }
        else if(onstack[x])
            lowlink[u]=min(lowlink[u],indexx[x]);
    }
    if(indexx[u]==lowlink[u]){
        while(!st.empty()&&st.top()!=u){
            int i=st.top();st.pop();
            scc[i]=cnt2;onstack[i]=0;
        }
        st.pop();scc[u]=cnt2++,onstack[u]=0;
    }
}
int main()
{
    int n,m,k,i,j,r;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&j);
        while(j--){
            scanf("%d",&r);
            g[i].push_back(r);
        }
    }
    for(i=1;i<=n;i++){
        if(!indexx[i])
            dfs(i);
    }
    while(k--){
        scanf("%d %d",&i,&j);
        if(scc[i]==scc[j])printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
