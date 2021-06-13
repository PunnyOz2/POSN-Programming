/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int main()
{
	int n,q,cou,a,b,old,y,last,ans=0;
	char Q;
	scanf("%d %d",&n,&q);
	while(q--){
        scanf("%d %d",&a,&b);
        mp[a]++;
        mp[b+1]--;
	}
	mp[n+1]--;
	scanf(" %c",&Q);
	if(Q=='R')y=0;
	else if(Q=='G')y=1;
	else if(Q=='B')y=2;
	old=0;
	last=1;
	ans=0;
	for(auto x:mp){
        if(y==0){
            if(old%3==1)
                ans+=2*(x.first-last);
            if(old%3==2)
                ans+=1*(x.first-last);
        }
        if(y==1){
            if(old%3==0)
                ans+=1*(x.first-last);
            if(old%3==2)
                ans+=2*(x.first-last);
        }
        if(y==2){
            if(old%3==1)
                ans+=1*(x.first-last);
            if(old%3==0)
                ans+=2*(x.first-last);
        }
        last=x.first;
        x.second+=old;
        old=x.second;
	}
    printf("%d",ans);
    return 0;
}
/*
3 2
1 2
2 3
R
*/
