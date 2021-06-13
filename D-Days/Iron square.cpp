/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[110][110];
int qs[110][110];
int qs2[110][110];
int main()
{
    int n,m,k,i,j;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++){
        scanf(" %s",a[i]+1);
        for(j=1;j<=m;j++){
            if(a[i][j]=='*')qs[i][j]++;
            qs[i][j]+=qs[i][j-1]+qs[i-1][j]-qs[i-1][j-1];
        }
    }
    int Max=-1,sti,stj;
    for(i=k;i<=n;i++){
        for(j=k;j<=m;j++){
            qs2[i][j]=qs[i-1][j-1]-qs[i-1-k+2][j-1]-qs[i-1][j-1-k+2]+qs[i-1-k+2][j-1-k+2];
            if(qs2[i][j]>Max)Max=qs2[i][j],sti=i,stj=j;
        }
    }
    int ii,jj;
    for(ii=sti;ii>sti-k;ii--){
        a[ii][stj]='|';
        a[ii][stj-k+1]='|';
    }
    for(jj=stj;jj>stj-k;jj--){
        a[sti][jj]='-';
        a[sti-k+1][jj]='-';
    }
    a[sti][stj]='+';
    a[sti-k+1][stj]='+';
    a[sti][stj-k+1]='+';
    a[sti-k+1][stj-k+1]='+';
    printf("%d\n",Max);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
/*
7 6 4
......
.*.*.*
......
.*.*..
..*...
..*...
*....*
*/
