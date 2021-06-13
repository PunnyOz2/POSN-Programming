/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,bit,time,dis;
    bool operator<(const A&o)const{
        return dis>o.dis;
    }
};
priority_queue<A> q;
char a[205][205];
int mark[8][130][205][205];
int di[4]={1,-1,0,0},dj[4]={0,0,1,-1};
map<pair<int,int>,int> gem;
int main()
{
	int n,m,i,j,sti,stj,nexti,nextj,bit,dis,k,T,kk;
	scanf("%d %d",&n,&m);
	int idx=1;
	for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j]=='S')sti=i,stj=j;
            if(a[i][j]=='G')gem[{i,j}]=idx++;
        }
	}
	for(i=1;i<=6;i++){
        for(j=0;j<=128;j++){
            for(k=0;k<n;k++){
                for(kk=0;kk<m;kk++){
                    mark[i][j][k][kk]=1<<30;
                }
            }
        }
	}
	mark[1][0][sti][stj]=1;
//	printf("hi\n");
	q.push({sti,stj,0,1,0});// i j bit time dis
	a[sti][stj]='.';
	int ans=1<<30;
	while(!q.empty()){
        i=q.top().i,j=q.top().j,bit=q.top().bit,T=q.top().time,dis=q.top().dis,q.pop();
        if(bit==127){ans=dis;break;}
//        printf("%d %d\n",i,j);
//        printf("%d\n",bit);
        int nexttime=(T%6)+1;
        if(isdigit(a[i][j])!=0&&__builtin_popcount(bit)>=a[i][j]-'0'){
            if(mark[nexttime][bit][i][j]>mark[T][bit][i][j]+1){
                mark[nexttime][bit][i][j]=mark[T][bit][i][j]+1;
                q.push({i,j,bit,nexttime,dis+1});
            }
        }
        else if(mark[nexttime][bit][i][j]>mark[T][bit][i][j]+1){
            mark[nexttime][bit][i][j]=mark[T][bit][i][j]+1;
            q.push({i,j,bit,nexttime,dis+1});
        }
        for(k=0;k<4;k++){
            nexti=i+di[k],nextj=j+dj[k];
            if(nexti<0 || nextj<0 || nexti>=n || nextj>=m)continue;
            if(a[nexti][nextj]=='#')continue;
            if(a[nexti][nextj]=='G'){
                idx=gem[{nexti,nextj}]-1;
                if(mark[nexttime][bit|(1<<idx)][nexti][nextj]>mark[T][bit][i][j]+1){
                    mark[nexttime][bit|(1<<idx)][nexti][nextj]=mark[T][bit][i][j]+1;
                    q.push({nexti,nextj,bit|(1<<idx),nexttime,dis+1});
                }
            }
            else if(a[nexti][nextj]=='.'){
                if(mark[nexttime][bit][nexti][nextj]>mark[T][bit][i][j]+1){
                    mark[nexttime][bit][nexti][nextj]=mark[T][bit][i][j]+1;
                    q.push({nexti,nextj,bit,nexttime,dis+1});
                }
            }
            else {
                if((__builtin_popcount(bit)>=a[nexti][nextj]-'0' || a[nexti][nextj]-'0'==nexttime )&& mark[nexttime][bit][nexti][nextj]>mark[T][bit][i][j]+1){
                    mark[nexttime][bit][nexti][nextj]=mark[T][bit][i][j]+1;
                    q.push({nexti,nextj,bit,nexttime,dis+1});
                }
            }
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

2 7
S11GGGG
111#GGG
*/
