/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char x[1010];
int mic[1010][1010];
int main()
{
    int n,i,j,k;
    scanf("%d", &n);
    for(i=1;i<=n;i++)
        scanf(" %c",&x[i]);
    for(j=1;j<=n;j++){
        for(i=j-1;i>=1;i--){
            if(x[i]==x[j])
                mic[i][j]=mic[i+1][j-1]+1;
            for(k=i;k<j;k++)
                mic[i][j]=max(mic[i][j],mic[i][k]+mic[k+1][j]);
        }
    }
    printf("%d\n",mic[1][n]);
    return 0;
}
/*
3
5 10
10 20
20 35
*/
