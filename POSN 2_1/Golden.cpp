/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[5500],ans[5500][120],nn;
int play(int n,int t){
    int Max=0,i;
    if(n>nn || t==0) return 0;
    if(ans[n][t]!=0) return ans[n][t];
    if(t==1) return a[n];
    for(i=0;i<t;i++){
        Max=max(play(n*2,i)+play(n*2+1,t-i-1)+a[n],Max);
    }
    ans[n][t]=Max;
    return ans[n][t];
}
int main()
{
	int t,i;
	scanf("%d %d",&nn,&t);
	for(i=1;i<=nn;i++){
        scanf("%d",&a[i]);
	}
	int Max=0;
	for(i=1;i<=nn;i++){
        Max=max(play(i,t),Max);
	}
	printf("%d\n",Max);
    return 0;
}
/*
10 5
3 7 1 9 6 2 6 5 4 1
*/
