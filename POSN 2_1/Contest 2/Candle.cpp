/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[2300][2300];
int mark[2300][2300];
typedef pair<int,int> PII;
queue<PII> q;
int main()
{
	int n,m,cou=0,iii,jjj,i,j,ii,jj;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf(" %c",&a[i][j]);
        }
	}
	for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i][j]=='1' && mark[i][j]==0)cou++,q.push({i,j});
            while(!q.empty()){
                ii=q.front().first,jj=q.front().second,q.pop();
                for(iii=ii-1;iii<=ii+1;iii++){
                    for(jjj=jj-1;jjj<=jj+1;jjj++){
                        if(a[iii][jjj]=='1' && mark[iii][jjj]==0)mark[iii][jjj]=1,q.push({iii,jjj});
                    }
                }
            }
        }
	}
	printf("%d",cou);
    return 0;
}
