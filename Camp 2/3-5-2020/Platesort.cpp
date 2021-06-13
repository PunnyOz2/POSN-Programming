/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[300100];
int main()
{
    int q,n,now,i;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        now=n;
        for(i=n;i>=1;i--){
            if(a[i]==now)now--;
        }
        printf("%d\n",now);
    }
    return 0;
}
