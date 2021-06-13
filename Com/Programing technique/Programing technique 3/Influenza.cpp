/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100],b[100100];
int main()
{
    int n,i,now,ans=-1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    sort(b,b+n);
    sort(a,a+n);
    for(i=0;i<n;i++){
        now = min(a[i],b[n-1-i]);
        ans = max(ans,now);
    }
    printf("%d\n",ans);

    return 0;
}

