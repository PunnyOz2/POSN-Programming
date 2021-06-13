/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int mark[1000010];
int main()
{
	int n,r,j,nub=0;
	scanf("%d %d",&n,&r);
	int i=0;
	int cou=0;
	while(cou<n){
        i++;
        i%=(n+1);
        if(i==0)i++;
        if(mark[i]!=0)continue;
        nub++;
        if(i==0)i++;
        if(nub==r)printf("%d ",i),mark[i]=1,cou++,nub=0;
	}
    return 0;
}
