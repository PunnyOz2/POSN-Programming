/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[20];
int main()
{
    int i,Max=0;
    for(i=1;i<=8;i++){
        scanf("%d",&a[i]);
        a[i+8]=a[i];
    }
    for(i=1;i<=16;i++){
        a[i]+=a[i-1];
    }
    for(i=4;i<=16;i++){
        Max=max(Max,a[i]-a[i-4]);
    }
    printf("%d\n",Max);
    return 0;
}
