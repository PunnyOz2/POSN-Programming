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
    int q,n,Max,i,num,divis;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        Max=-1;
        for(i=0;i<n;i++){
            scanf("%d",&num);
            Max=max(num,Max);
            if(i==0)divis=num;
            else divis=__gcd(divis,num);
        }
        Max/=divis;
        Max-=n;
        if(Max%2==0)printf("Dead\n");
        else printf("Alive\n");
    }
    return 0;
}
