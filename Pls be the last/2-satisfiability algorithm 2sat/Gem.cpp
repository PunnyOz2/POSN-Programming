/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[400100];
stack<int> st;
int scc[400100],lowlink[400100],indexx[400100],cnt=1,cnt2=1,onstack[400100];
void dfs(int u){
    lowlink[u]=indexx[u]=cnt++,onstack[u]=1;
    st.push(u);
    for(auto x:g[u]){
        if(indexx[x]==0){
            dfs(x);
            lowlink[u]=min(lowlink[u],lowlink[x]);
        }
        else if(onstack[x]==1){
            lowlink[u]=min(lowlink[u],indexx[x]);
        }
    }
    if(lowlink[u]==indexx[u]){
        while(!st.empty() && st.top()!=u){
            scc[st.top()]=cnt2;
            onstack[st.top()]=0;
            st.pop();
        }
        scc[st.top()]=cnt2++;
        onstack[st.top()]=0;
        st.pop();
    }
}
int main()
{
    int q=5,n,m,i,x,y,ch;
    while(q--){
        cnt=1;
        ch=1;
        cnt2=1;
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++){
            scanf("%d %d",&x,&y);
            g[x*2+1].push_back(y*2);
            g[y*2+1].push_back(x*2);
        }
        for(i=1;i<=m/2;i++){
            scanf("%d %d",&x,&y);
            g[x*2].push_back(y*2+1),g[y*2].push_back(x*2+1);
        }
        for(i=2;i<=2*m+1;i++){
            if(indexx[i]==0){
                dfs(i);
            }
        }
        for(i=1;i<=m;i++){
            if(scc[2*i]==scc[2*i+1])
                ch=0;
        }
        printf((ch)?"Y":"N");
        memset(scc,0,sizeof scc);
        memset(lowlink,0,sizeof lowlink);
        memset(indexx,0,sizeof indexx);
        for(i=2;i<=2*m+1;i++)
            g[i].clear();
    }

    return 0;
}
/*
4 6
2 3 6 5 3 4 1 2
1 3 2 5 4 6
3 4
1 2 2 3 4 3
1 3 2 4
4 8
1 2 3 4 5 6 7 8
1 3 2 4 5 7 6 8
3 4
1 2 2 3 3 4
2 3 1 4
5 4
1 2 2 3 4 3 1 3 4 2
1 4 2 3
*/
