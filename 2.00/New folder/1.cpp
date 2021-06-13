/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[1100][1100],Minl[1100][1100],Minr[1100][1100],Minu[1100][1100],Mind[1100][1100],Min=1<<30;
int main()
{
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<=n+1;i++){
        for(j=0;j<=m+1;j++){
            Minl[i][j]=Minr[i][j]=Minu[i][j]=Mind[i][j]=1<<30;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            Minl[i][j]=min(Minl[i][j-1],a[i][j]);
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            Minu[i][j]=min(Minu[i-1][j],a[i][j]);
        }
    }
    for(j=1;j<=m;j++){
        for(i=n;i>=1;i--){
            Mind[i][j]=min(Mind[i+1][j],a[i][j]);
        }
    }
    for(i=1;i<=n;i++){
        for(j=m;j>=1;j--){
            Minr[i][j]=min(Minr[i][j+1],a[i][j]);
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            Min=min(Min,a[i][j]+min(Minl[i][j-1],Minr[i][j+1])+min(Minu[i-1][j],Mind[i+1][j]));
        }
    }
    printf("%d",Min);
    return 0;
}
/*
5 7
99 45 21 32 11 85 15
33 21 12 15 47 85 65
32 54 75 65 85 95 85
12 91 42 32 52 76 61
37 22 40 62 10 25 32
*/
