/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[1001000],b[1001000],c[1001000],d[1001000];
int main()
{
    int n,i,Ma;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    a[0]=a[1];
    for(i=0;i<n;i++){
        a[i+1]=max(a[i],a[i+1]);
    }
    b[n+1]=b[n];
    for(i=n;i>=1;i--){
        b[i-1]=max(b[i],b[i-1]);
    }
    for(i=1;i<n;i++)printf("%d ",min(a[i],b[i+1]));
    return 0;
}
// 9   1 2 5 2 3 2 4 3 2
