/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue<int> h;
vector<int> ans,ans2,g[50100];
int in[50100],in2[50100];
int main()
{
	int n,q,i,v,u,last=0,temp;
	scanf("%d %d",&n,&q);
	for(i=0;i<q;i++){
        scanf("%d %d",&v,&u);
        in[v]++,in2[v]++;
        g[u].push_back(v);
	}
	for(i=1;i<=n;i++)
        if(in[i]==0)h.push(-i);
    while(!h.empty()){
        u=h.top()*-1;
        if(h.size()>1)last=u;
        h.pop();
        ans.push_back(u);
        for(auto x:g[u]){
            in[x]--;
            if(in[x]==0)h.push(-x);
        }
    }
    for(i=1;i<=n;i++)
        if(in2[i]==0)h.push(-i);
    while(!h.empty()){
        u=h.top()*-1,h.pop();
        if(u==last){
        temp=h.top()*-1,h.pop(),ans2.push_back(temp);
            for(auto x:g[temp]){
                in2[x]--;
                if(in2[x]==0)h.push(-x);
            }
        }
        ans2.push_back(u);
        for(auto x:g[u]){
            in2[x]--;
            if(in2[x]==0)h.push(-x);
        }
    }
    if(ans.size()!=n){printf("Never\n");return 0;}
    int ch=1;
    for(i=0;i<n;i++){
        if(ans[i]!=ans2[i]){ch=0;break;}
    }
    if(ch==0 || last!=0){
        printf("Different\n");
        for(i=0;i<n;i++)
            printf("%d ",ans2[i]);

    }
    else {
        printf("Same\n");
        for(i=0;i<n;i++)
            printf("%d ",ans[i]);
    }
    return 0;
}
/*
4 4
2 1
3 1
4 2
4 3

2 2
1 2
2 1

2 1
1 2
*/
