/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[6000],b[6000];
int main()
{
    int m,i,Max,Max2;
    int n;
    scanf("%d %d",&m,&n);
    for(i=1;i<=n;i++){
        scanf("%d %d",&a[i],&b[i]);
    }
    a[0]=0;
    b[0]=0;
    b[n+1]=m;
    a[n+1]=m;
    sort(a,a+n+2);
    sort(b,b+n+2);
    Max=0,Max2=0;
    for(i=1;i<=n+1;i++){
        Max=max(Max,a[i]-a[i-1]);
    }
    for(i=1;i<=n+1;i++){
        Max2=max(Max2,b[i]-b[i-1]);
    }
    Max=min(Max,Max2);
    printf("%.3lf\n",(double)(Max)/(double)(2));
    return 0;
}
/*
10
5
9 5 7 5 5 5 3 5 1 5
*/
