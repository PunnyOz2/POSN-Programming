/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
queue<pair<int,int>> q;
stack<pair<int,int>> st;
int di[4]={1,-1,0,0},dj[4]={0,0,1,-1},mark[500][500],ans[200000];
int main()
{
	int r,c,Q,i,j,ii,jj,cou,k,ch;
	scanf("%d %d %d",&r,&c,&Q);
	while(Q--){
        scanf("%d %d",&i,&j);
        mark[i][j]=2;
        st.push({i,j});
	}
	for(i=0;i<r;i++){
        if(!mark[i][0])q.push({i,0});
        if(!mark[i][c-1])q.push({i,c-1});
    }
	for(i=0;i<c;i++){
        if(!mark[0][i])q.push({0,i});
        if(!mark[r-1][i])q.push({r-1,i});
    }
	cou=0;
	while(!q.empty()){
        i=q.front().first,j=q.front().second,q.pop();
        if(mark[i][j]==2 || mark[i][j]==1)continue;
        cou++;
        mark[i][j]=1;
        for(k=0;k<4;k++){
            if(i+di[k]<r && i+di[k]>=0 && j+dj[k]>=0 && j+dj[k]<c && mark[i+di[k]][j+dj[k]]==0)q.push({i+di[k],j+dj[k]});
        }
	}
	Q=0;
	ans[Q++]=cou;
	while(!st.empty()){
        ch=1;
        i=st.top().first,j=st.top().second,st.pop();
        for(k=0;k<4;k++){
            if(i+di[k]>r-1 || i+di[k]<0 || j+dj[k]<0 || j+dj[k]>c-1 || mark[i+di[k]][j+dj[k]]==1){ch=0;break;}
        }
        mark[i][j]=0;
        if(ch==0){
            q.push({i,j});
            while(!q.empty()){
                ii=q.front().first,jj=q.front().second,q.pop();
                if(mark[ii][jj]==2 || mark[ii][jj]==1 )continue;
                mark[ii][jj]=1;
                cou++;
                for(k=0;k<4;k++){
                    if(ii+di[k]<r && ii+di[k]>=0 && jj+dj[k]>=0 && jj+dj[k]<c && mark[ii+di[k]][jj+dj[k]]==0)q.push({ii+di[k],jj+dj[k]});
                }
            }
        }
        /*
        for(i=0;i<r;i++){
            for(j=0;j<c;j++)printf("%d ",mark[i][j]);
            printf("\n");
        }
        */
        ans[Q++]=cou;
	}
	for(i=Q-2;i>=0;i--){
        printf("%d\n",ans[i]);
	}
    return 0;
}
/*
3 3 9
2 2
2 0
1 0
0 1
0 2
0 0
2 1
1 2
1 1
*/
