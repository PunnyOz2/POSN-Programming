/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[103][103];
int main()
{
    int n,q,i,j,sum;
    scanf("%d",&q);
    while(q--){
        sum=0;
        scanf("%d",&n);
        for(i=1;i<=2*n;i++)
            for(j=1;j<=n*2;j++)
                scanf("%d",&a[i][j]);
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                sum+=max(a[i][j],max(a[i][n+n-j+1],max(a[n+n-i+1][j],a[n+n-i+1][n+n-j+1])));
            }
            printf("\n");
        }
        printf("%d\n",sum);
    }
    return 0;
}
/*
1
2
1 4 2 6
2 4 1 3
2 2 5 8
4 5 3 2
*/
