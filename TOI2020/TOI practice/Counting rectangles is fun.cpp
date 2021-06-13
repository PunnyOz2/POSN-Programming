#include<bits/stdc++.h>
using namespace std;
int ch[42][42][42][42],qs[42][42],ans[42][42][42][42];
int b[42][42],cou[42][42];
char a[42];
int main(){
    int n,m,q,i,j,ii,jj;
    scanf("%d %d %d",&n,&m,&q);
    for(i=1;i<=n;i++){
        scanf(" %s",a+1);
        for(j=1;j<=m;j++)if(a[j]=='1')b[i][j]=1;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            qs[i][j]=b[i][j]+qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(b[i][j]==1)continue;
            for(ii=1;ii<=i;ii++){
                for(jj=1;jj<=j;jj++){
                    if(qs[i][j]-qs[i][jj-1]-qs[ii-1][j]+qs[ii-1][jj-1]==0)ch[i][j][ii][jj]=1;
                    ch[i][j][ii][jj]+=ch[i][j][ii][jj-1];
                    ch[i][j][ii][jj]+=ch[i][j][ii-1][jj];
                    ch[i][j][ii][jj]-=ch[i][j][ii-1][jj-1];
                }
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            for(ii=1;ii<=i;ii++){
                for(jj=1;jj<=j;jj++){
                    ans[i][j][ii][jj]=ch[i][j][i][j]-ch[i][j][ii-1][j]-ch[i][j][i][jj-1]+ch[i][j][ii-1][jj-1];
                }
            }
        }
    }
    for(ii=1;ii<=n;ii++){
        for(jj=1;jj<=m;jj++){
            for(i=1;i<=ii;i++){
                for(j=1;j<=jj;j++){
                    ans[ii][jj][i][j]+=ans[ii-1][jj][i][j];
                    ans[ii][jj][i][j]+=ans[ii][jj-1][i][j];
                    ans[ii][jj][i][j]-=ans[ii-1][jj-1][i][j];
                }
            }
        }
    }
    while(q--){
        scanf("%d %d %d %d",&i,&j,&ii,&jj);
        printf("%d\n",ans[ii][jj][i][j]-ans[ii][j-1][i][j]-ans[i-1][jj][i][j]+ans[i-1][j-1][i][j]);
    }
    return 0;
}
/*
5 5 5
00101
00000
00001
01000
00001
1 2 2 4
4 5 4 5
1 2 5 2
2 2 4 5
4 2 5 3
*/
