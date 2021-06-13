/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<cstdio>
#include<algorithm>
using namespace std;
long long qs[2020][2020],qss[2020][2020],a[2020][2020];
int main()
{
    long long n,m,k,i,j,Max=-1e18,cou;
    scanf("%lld %lld %lld",&n,&m,&k);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%lld",&a[i][j]);
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){//down
            qs[i][j]=a[i][j]+qs[i-1][j];
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            qss[i][j]=a[i][j]+qss[i-1][j-1];
        }
    }
    for(i=k;i<=n;i++){
        cou=0;
        for(j=1;j<=k;j++){
            cou+=qss[i][j];
        }
        Max=max(Max,cou);
        for(j=k+1;j<=m;j++){
            cou+=qss[i][j];
            cou-=qss[i-k][j-k];
            cou-=qs[i][j-k];
            cou+=qs[i-k][j-k];
            Max=max(Max,cou);
        }
    }
    //printf("%lld\n",Max);
    for(i=1;i<=n;i++){
        for(j=m;j>=1;j--){
            qss[i][j]=a[i][j]+qss[i-1][j+1];
        }
    }
    for(i=k;i<=n;i++){
        cou=0;
        for(j=m;j>=m-k+1;j--){
            cou+=qss[i][j];
        }
        Max=max(Max,cou);
        for(j=m-k;j>=1;j--){
            cou+=qss[i][j];
            cou-=qss[i-k][j+k];
            cou-=qs[i][j+k];
            cou+=qs[i-k][j+k];
            Max=max(Max,cou);
        }
    }
    printf("%lld\n",Max);
    return 0;
}
/*
4 5 3
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
*/
