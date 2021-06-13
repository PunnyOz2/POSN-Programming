/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> mp;
int mark[10000010];
int main()
{
	int n,m,q,r,sum,i,w,c;
	scanf("%d %d %d %d",&n,&m,&q,&r);
	for(i=0;i<n;i++){
        scanf("%d",&w);
        mp[w]=1;
	}
	while(q--){
        sum=0;
        for(i=0;i<m;i++){
            scanf("%d",&c);
            for(auto x:mp){
                if(mark[x.first]==0 && x.first>=c-r && x.first<=c+r)mark[x.first]=1,sum++;
            }
        }
        printf("%d\n",sum);
        for(i=0;i<=c+r;i++)mark[i]=0;
	}
    return 0;
}
/*
3 2 4 100
100 300 500
200 1000
199 1000
200 600
1000 1001
*/
