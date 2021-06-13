/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int p[5000010];
char a[10000010];
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf(" %c",&a[i]);
        a[i+n]=a[i];
    }
    int j=0;
    for(i=2;i<=n;i++){
        while(j!=0 && a[i]!=a[j+1]) j=p[j];
        if(a[i] == a[j+1])  j++;
        p[i] = j;
//        printf("%d ",p[i]);
    }
    int ans=10000;
    j=0;
    for(i=2;i<=n*2;i++){
        while( j!=0 && a[i]!=a[j+1])j=p[j];
        if(a[i]==a[j+1])j++;
        if(j==n){ans=i-j;break;}
    }
    printf("%d\n",ans);
    return 0;
}
/*
10
1010101010

10
1000000010
*/
