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
    int a,n,now=0,mo,i;
    scanf("%d %d",&a,&n);
    for(i=1;i<=n;i++){
        now+=a;
        scanf("%d",&mo);
        now-=mo;
        //if(now>=a)now=a;
        //printf("%d\n",now);
    }
    printf("%d\n",now+a);
    return 0;
}
/*
15
3
15
10
19
*/
