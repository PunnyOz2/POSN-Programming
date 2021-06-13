/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int mica[1000003],micb[1000003];
int main()
{
    int n,i;
    char k;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf(" %c",&k);
        if(k=='A'){
            mica[i]=min(micb[i-1]+1,mica[i-1]);
            micb[i]=min(micb[i-1]+1,mica[i-1]+1);
        }
        else if(k=='B'){
            micb[i]=min(micb[i-1],mica[i-1]+1);
            mica[i]=min(micb[i-1]+1,mica[i-1]+1);
        }
    }
    printf("%d\n",mica[n]);
    return 0;
}
