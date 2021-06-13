/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q,n,k;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&k);
        if(sqrt(n)<=k)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
