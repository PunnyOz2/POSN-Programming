/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue<int> q;
vector<int> g[100100];
int main()
{
	int n,Max=0,day,pay,i;
	long long ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
	    scanf("%d %d",&day,&pay);
        g[day].push_back(pay);
	}
	int j=0,cou=0;
	for(i=100000;i>0;i--){
        for(auto x:g[i])
            q.push(x);
        if(!q.empty()){
            ans+=q.top();
            q.pop();
            cou++;
        }
	}
	printf("%lld\n",ans);
	printf("%d\n",cou);
    return 0;
}
/*
4
1 17
5 15
2 10
2 11
*/
