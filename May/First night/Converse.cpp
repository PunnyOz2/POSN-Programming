/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int c1[100100],c2[100100];
int main()
{
    int n,q,ans,a,i;
    scanf("%d",&q);
    while(q--){
        memset(c1,0,sizeof c1);
        memset(c2,0,sizeof c2);
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a);
            c1[a]++;
        }
        for(i=1;i<=n;i++){
            scanf("%d",&a);
            c2[a]++;
        }
        ans=0;
        for(i=1;i<=5;i++){
            if((c1[i]+c2[i])%2==1){printf("-1\n");goto jump;}
            ans+=abs(c1[i]-((c1[i]+c2[i])/2));
        }
        printf("%d",ans/2);
        jump:;
    }
    return 0;
}
