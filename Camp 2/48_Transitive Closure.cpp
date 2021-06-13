/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[600][600];
int main()
{
    long long n,m,i,j,k,u,v,w,num;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%lld",&num);
            a[i][j]=num;
        }
    }
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                a[i][j]|=a[i][k]&a[k][j];
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)if(a[i][j]==1e17)printf("0 ");else printf("%lld ",a[i][j]);
        printf("\n");
    }
    return 0;
}
/*
4
0 0 1 0
1 0 0 1
0 0 0 0
0 1 0 0
*/
