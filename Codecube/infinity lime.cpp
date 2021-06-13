/*
	TASK:
	LANG: CPP
	AUTHOR: Pun~
	SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> mp;
int a[700100];
int main()
{
	int m,k,i,num,cou,idx,tmp,old=0,oldidx=0,now;
	scanf("%d %d",&m,&k);
	for(i=0;i<m;i++)scanf("%d",&a[i]);
	//a[m+1]=1e9+70000;
	sort(a,a+m);
	for(i=0;i<k;i++){
		scanf("%d",&num);
		now=num;
		old=0;
		oldidx=0;
		while(old!=now){
            idx=upper_bound(a,a+m,now)-a;
            old=now;
            now+=idx-oldidx;
            oldidx=idx;
		}
		printf("%d\n",now);
	}
	return 0;
}
/*
3 4
5 7 1
2 8 4 1
*/

/*
10 4
1 2 3 4 5 6 7 8 9 10 15 20
2 17 1 3

3 11 6 2

10 10
1 3 4 51 6 5
*/
