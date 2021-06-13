#include<bits/stdc++.h>
using namespace std;
long long a[200100],b[200100],temp[200100],ans;
int main(){
	long long n,m,i,idx,Max;
	scanf("%lld %lld",&n,&m);
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(i=1;i<=m;i++)scanf("%lld",&b[i]);
	for(i=1;i<=m;i++){
        idx=upper_bound(a+1,a+1+n,b[i])-a-1;
        Max=max(idx,n-idx);
        Max+=m-i;
        ans+=Max;
	}
	printf("%lld\n",ans);
}
/*
2 3
96 36
51 20 22

5 4
5 4 3 2 1

5 5
20 22 51 96 36

12 1
30 41 44 91 81 68 21 14 5 53 70 96
1

6 6
91 81 68 21 14 5
44 30 96 41 53 70
*/
