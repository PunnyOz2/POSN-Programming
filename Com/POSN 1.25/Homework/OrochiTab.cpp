/*
    TASK: Orochimaru Table
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[110][110];
int n,m;
long long ans=-2000000000;
void play(int i,int j,long long sum){
    if(j=m){
        if(sum>ans) ans=sum;
        return;
    }
    sum+=a[i][j];
    play(abs(i-1),j+1,sum);
    play(i,j+1,sum);
    play((i+1)%(n-1),j+1,sum);
    return;
}
int main()
{
    int i,j;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            scanf("%lld",&a[i][j]);
    }
    for(i=0;i<n;i++)play(i,0,0);
    printf("%lld",ans);
    return 0;
}
/*
4 8
7 1 8 10 4 1 -5 -1
4 16 5 3 9 5 -3 -9
2 24 4 6 7 4 0 -2
6 10 3 7 2 11 -7 -4
*/
