/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y,i;
    scanf("%d %d",&x,&y);
	for(i=1;i<=x;i++){
        if(x%i==0 && y%i==0)
            printf("%d %d %d\n",i,x/i,y/i);
	}
    return 0;
}
