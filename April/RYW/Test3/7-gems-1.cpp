/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,bit,time;
};
queue<A> q;
char a[205][205];
int mark[8][130][205][205],gem[205][205];
int di[5]={1,-1,0,0,0},dj[5]={0,0,1,-1,0};
int main()
{
	int n,m,i,j,sti,stj,nexti,nextj,bit,dis,k,T,kk;
	scanf("%d %d",&n,&m);
	int idx=0;
	for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j]=='S')sti=i,stj=j;
            if(a[i][j]=='G')gem[i][j]=1<<idx++;
        }
	}
	a[sti][stj] = '.';
	mark[0][0][sti][stj]=1;
	q.push({sti,stj,0,0});// i j bit time
	int ans=1<<30;
	while(!q.empty()){
        i=q.front().i,j=q.front().j,bit=q.front().bit,T=q.front().time,q.pop();
        if(bit==(1<<7)-1){ans=T;break;}
        int nexttime=(T+1)%6;
        for(k=0;k<5;k++){
            nexti=i+di[k],nextj=j+dj[k];
            if(nexti<0 || nextj<0 || nexti>=n || nextj>=m)continue;
            if(a[nexti][nextj]=='#')continue;
            if(isdigit(a[nexti][nextj])){
                if(a[nexti][nextj]-'1'==nexttime || a[nexti][nextj]-'0'<=__builtin_popcount(bit));
                else continue;
            }
            if(mark[nexttime][bit|gem[nexti][nextj]][nexti][nextj])
                continue ;
            mark[nexttime][bit|gem[nexti][nextj]][nexti][nextj]=1;
            q.push({nexti,nextj,bit|gem[nexti][nextj],T+1});
        }
	}
	if(ans==1<<30)printf("-1\n");
	else printf("%d\n",ans);
    return 0;
}
/*
2 6
S##GGG
.6GGGG
*/
