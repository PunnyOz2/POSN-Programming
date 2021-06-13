/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100],l[100100],r[100100];
int main()
{
    int q,sum=0,n,i,ans;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        sum=0;
        for(i=1;i<=n;i++){
            sum+=a[i];
            sum=max(0,sum);
            l[i]=max(l[i-1],sum);
        }
        sum=0;
        for(i=n;i>=1;i--){
            sum+=a[i];
            sum=max(0,sum);
            r[i]=max(r[i+1],sum);
        }
        for(i=1,ans=-1;i<=n;i++){
            ans=max(ans,l[i]+r[i+1]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
