/*
	TASK:
	LANG: CPP
	AUTHOR: Pun~
	SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int mark[200100],fw[200100],a[200100],ans[200100];
void update(int a,int b){
	while(a<=200003){
		fw[a]+=b;
		a+=(a&-a);
	}
}
int query(int a){
	int sum=0;
	while(a>0){
		sum+=fw[a];
		a-=(a&-a);
	}
	return sum;
}
int main()
{
	int n,k,Q,i,idx,l,r;
	scanf("%d %d %d",&n,&k,&Q);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++){
		if(mark[a[i]]==0)update(a[i],1);
		mark[a[i]]++;
		if(query(k)==k)break;
	}
	idx=i;
	ans[1]=idx;
	//printf("%d\n",idx);
	for(i=2;i<=n;i++){
		mark[a[i-1]]--;
		//printf("%d  ",i);
		if(mark[a[i-1]]==0)update(a[i-1],-1);
		if(query(k)==k)ans[i]=idx;
		else{
			//printf("%d ",idx);
			while(query(k)<k && idx<n){
				idx++;
				if(mark[a[idx]]==0)update(a[idx],1);
				mark[a[idx]]++;
			}
			if(query(k)==k)ans[i]=idx;
			else ans[i]=1111111;
		}
		//printf("%d\n",idx);
	}
	while(Q--){
		scanf("%d %d",&l,&r);
		if(ans[l]<=r)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
/*
10 3 5
1 2 3 1 2 7 8 2 3 1
1 5
4 8
4 9
8 10
7 8
if(query(k)==k)ans[i]=idx;
			else ans[i]=1111111;
*/
