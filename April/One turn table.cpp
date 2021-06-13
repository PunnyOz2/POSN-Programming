/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[60][60];
int mark[60][60];
stack<pair<int,int>> st;
queue<pair<int,int>> q;
int di[4]={1,-1,0,0},dj[4]={0,0,1,-1};
int main()
{
	int n,m,ans=0,i,j,ii,cou,jj,k;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
        scanf(" %s",a[i]);
        for(j=0;j<m;j++){
            if(a[i][j]=='B')ans++,st.push({i,j});
        }
	}
	while(!st.empty()){
        i=st.top().first,j=st.top().second,st.pop();
        cou=1;
        mark[i][j]=1;
        for(k=0;k<4;k++){
            ii=i,jj=j;
            while(1){
                ii+=di[k],jj+=dj[k];
                if(ii<0||ii>=n||jj<0||jj>=m) break;
                if(a[ii][jj]=='W') break;
                if(mark[ii][jj]!=0)continue;
                mark[ii][jj]=1;
                cou++;
                q.push({ii,jj});
            }
        }
        while(!q.empty()){
            i=q.front().first,j=q.front().second,q.pop();
            for(k=0;k<4;k++){
                ii=i,jj=j;
                while(1){
                    ii+=di[k],jj+=dj[k];
                    if(ii<0||ii>=n||jj<0||jj>=m) break;
                    if(a[ii][jj]=='W') break;
                    if(mark[ii][jj]!=0)continue;
                    mark[ii][jj]=1;
                    cou++;
                }
            }
        }
        if(cou!=ans){printf("NO\n");return 0;}
        memset(mark,0,sizeof mark);
	}
	printf("YES\n");
    return 0;
}
/*
4 4
WWBW
WBBB
BBBB
WBBW
3 4
WWBW
BWWW
WWWB
*/
