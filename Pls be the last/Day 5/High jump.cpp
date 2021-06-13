/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[700][710];
int main()
{
    long long n,i,j,now,k;
    scanf("%lld",&n);
    for(i=1;i<=2*n;i++){
        for(j=1;j<=2*n;j++){
            scanf("%lld",&a[i][j]);
            if(i<j && a[i][j]==0)a[i][j]=1<<30;
        }
    }
    for(k=2;k<=2*n;k++){
        for(i=2;i<=2*n;i++){
            for(j=2;j<=2*n;j++){
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
    printf("%lld\n",a[2*n][2]);
    return 0;
}
/*
5
0 0  0  0  0  0  0  0  0  0
0 0  0  0  0  0  0  0  0  0
0 14 0  0  0  0  0  0  0  0
0 30 15 0  0  0  0  0  0  0
0 41 21 13 0  0  0  0  0  0
0 51 42 22 11 0  0  0  0  0
0 75 58 34 28 12 0  0  0  0
0 67 71 44 37 23 14 0  0  0
0 95 77 51 41 44 28 15 0  0
0 96 94 66 72 41 37 30 11 0
*/
