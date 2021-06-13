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
    int n,q,i,Min,idx,num;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]+=a[i-1];
    }
    Min=1<<30;
    for(i=n;i>0;i--){
        a[i]=min(Min,a[i]);
        Min=min(a[i],Min);
    }
    //for(i=1;i<=n;i++)printf("%d ",a[i]);
    while(q--){
        scanf("%d",&num);
        idx=upper_bound(a+1,a+1+n,num)-a;
        printf("%d\n",idx-1);
    }
    return 0;
}
