/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100];
int main()
{
    int n,m,idx,num,i,Min=1<<30;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]+=a[i-1];
    }
    for(i=n;i>=1;i--){
        Min=min(a[i],Min);
        a[i]=Min;
    }
    while(m--){
        scanf("%d",&num);
        idx=upper_bound(a+1,a+n+1,num)-a-1;
        printf("%d\n",idx);
    }
    return 0;
}
