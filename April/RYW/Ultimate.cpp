/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100],color[100100],in[100100];
void dfs(int now,int col){
    if(color[now])return;
    color[now]=col;
    in[a[now]]--;
    if(in[a[now]]==0 || col==1)dfs(a[now],3-col);
}
int main()
{
	int q,n,i,ans;
	scanf("%d",&q);
	while(q--){
        scanf("%d",&n);
        memset(color,0,sizeof color);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            in[a[i]]++;
        }
        for(i=1;i<=n;i++){
			if(in[i]==0) dfs(i,1);
		}
		for(i=1;i<=n;i++){
            if(!color[i])dfs(i,2);
		}
        ans=0;
        for(i=1;i<=n;i++)if(color[i]==2)ans++;
        printf("%d\n",ans);
	}
    return 0;
}
/*
2
4
2 3 1 1
5
2 3 1 5 4
*/
