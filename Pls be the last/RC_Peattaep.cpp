/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int cnt=1,cnt2=1,indexx[100100],lowlink[100100],scc[100100],onstack[100100];
stack<int> st;
vector<pair<int,int>> g[100100];
set<int> se,se2;
void dfs(int u,int p){
    indexx[u]=lowlink[u]=cnt++;
    onstack[u]=1;
    st.push(u);
    int c=0;
    for(auto x:g[u]){
        if(x.first==p)continue;
        if(indexx[x.first]==0){
            dfs(x.first,u);
            c++;
            if(indexx[u]!=1 && lowlink[x.first]>=indexx[u])se.insert(u);
            else if(indexx[u]==1 && c>=2)se.insert(u);
            if(indexx[u]<lowlink[x.first])se2.insert(x.second);
            lowlink[u]=min(lowlink[u],lowlink[x.first]);
        }
        else if(onstack[x.first]!=0){
            lowlink[u]=min(lowlink[u],indexx[x.first]);
        }
    }
    if(lowlink[u]==indexx[u]){
        while(!st.empty() && st.top()!=u){
            scc[st.top()]=cnt2;
            onstack[st.top()]=0;
            st.pop();
        }
        st.pop();
        scc[u]=cnt2++;
        onstack[u]=0;
    }
}
int main()
{
    int n,m,i,u,v;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
    for(i=0;i<n;i++){
        if(indexx[i]==0)dfs(i,-1);
    }
    if(se.empty()){
        printf("-1\n");
    }
    else{
        for(auto x:se){
            printf("%d ",x);
        }
        printf("\n");
    }
    if(se2.empty()){
        printf("-1\n");
    }
    else{
        for(auto x:se2){
            printf("%d ",x);
        }
        printf("\n");
    }
    return 0;
}
/*
5 5
0 1
0 2
1 2
0 3
3 4
*/
