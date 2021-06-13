/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int ar[5200];
int main()
{
    int ll,rr,n,a,i,Max=0;
    scanf("%d %d %d",&rr,&ll,&n);
    rr+=ll;
    for(i=0;i<n;i++){
        scanf("%d",&a);
        if(ll<=a&&a<=rr)ar[a]++;
        Max=max(ar[a],Max);
    }
    printf("%d\n",Max);
    return 0;
}
