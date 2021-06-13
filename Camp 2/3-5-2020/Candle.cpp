/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int posi[8]={1,-1,0,0,1,-1,1,-1},posj[8]={0,0,1,-1,-1,1,1,-1},now,mark[2200][2200];
char a[2200][2200];
queue<pair<int,int>> q;
int main()
{
    int n,m,i,j,ii,jj,iii,jjj,k,r,c,num=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf(" %s",a[i]+1);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i][j]=='1')q.push({i,j}),num++,a[i][j]='0';
            while(!q.empty()){
                iii=q.front().first;
                jjj=q.front().second;
                q.pop();
                for(k=0;k<8;k++){
                    ii=iii+posi[k];
                    jj=jjj+posj[k];
                    if(ii<1 || jj<1 || ii>n || jj>m)continue;
                    if(a[ii][jj]=='1')q.push({ii,jj});
                    a[ii][jj]='0';
                }
            }
        }
    }
    printf("%d\n",num);
    return 0;
}
/*
4 5
10011
00001
01100
10011
*/
