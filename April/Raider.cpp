/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,cou;
};
queue<A> q;
int di[6]={1,1,0,0,-1,-1},dj[6]={-1,0,1,-1,0,-1};
int di2[6]={1,1,0,0,-1,-1},dj2[6]={1,0,1,-1,0,1};
int a[150][150];
int dis[150][150];
int main()
{
	int n,m,i,j,nexti,nextj,k,cou;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    //q.push({n/2-1,0,0});
    //q.push({n/2,0,0});
    q.push({n/2+1,0,0});
    while(!q.empty()){
        i=q.front().i,j=q.front().j,cou=q.front().cou,q.pop();
        printf("%d %d %d %d\n",i,j,a[i][j],cou);
        if(i==(n/2) && j==(m-1)){printf("%d\n",cou);break;}
        if(i%2==1){
            for(k=0;k<6;k++){
                nexti=i+di[k],nextj=j+dj[k];
                if(nexti<0 || nexti >=n || nextj >=m || nextj<0)continue;
                if(a[nexti][nextj]==0||a[nexti][nextj]%(cou+1)!=0||(cou+1)==dis[nexti][nextj])continue;
                printf("Hi\n");
                dis[nexti][nextj]=cou+1;
                q.push({nexti,nextj,cou+1});
            }
        }
        else{
            for(k=0;k<6;k++){
                nexti=i+di2[k],nextj=j+dj2[k];
                if(nexti<0 || nexti >=n || nextj >=m || nextj<0)continue;
                if(a[nexti][nextj]==0||a[nexti][nextj]%(cou+1)!=0 || (cou+1)==dis[nexti][nextj])continue;
                printf("Hi\n");
                dis[nexti][nextj]=cou+1;
                q.push({nexti,nextj,cou+1});
            }
        }
    }
    return 0;
}
