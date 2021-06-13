/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[3100][3100];
int main()
{
    int n,m,i,j,stj=10000000,enj=-1;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf(" %s",a[i]+1);
        for(j=1;j<=m;j++){
            if(a[i][j]=='X')stj=min(stj,j),enj=max(enj,j);
        }
    }
    int l,r,Min=4000;
    for(j=stj;j<=enj;j++){
        for(i=1;i<=n;i++){
            if(a[i][j]=='X')l=i;
            if(a[i][j]=='#'){r=i;break;}
        }
        Min=min(Min,r-l-1);
    }
    for(i=n;i>0;i--){
        for(j=m;j>0;j--){
            if(a[i][j]=='X')a[i][j]='.',a[i+Min][j]='X';
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++)printf("%c",a[i][j]);
        printf("\n");
    }
    return 0;
}
/*
5 6
.XXXX.
...X..
......
#..###
######
*/
