/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> m[2100];
priority_queue<int> q;
int main()
{
	int n,ans=0,i,j,t;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            scanf("%d",&t);
            m[i+j-2].push_back(t);
        }
    for(i=2000;i>0;i--){
        for(auto x:m[i]){
            q.push(x);
        }
        if(!q.empty()){
            ans+=q.top();
            q.pop();
        }
    }
    printf("%d\n",ans);
    return 0;
}
