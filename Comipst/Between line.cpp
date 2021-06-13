/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[10100];
int main()
{
    int n,x=1,y=1,z=1,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++){
        if(a[i]==10)y++;
        if(a[i]==13)z++;
    }
    for(i=1;i<n;i++){
        if(a[i]==13 && a[i+1]==10)x++;
    }
    printf("%d %d %d\n",x,y,z);
    return 0;
}
