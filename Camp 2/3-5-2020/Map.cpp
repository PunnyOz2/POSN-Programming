/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int up,left,right,down;
};
struct B{
    int i,j,now;
};
queue<B> q;
A a[40100];
int mark[500][500];
int main()
{
    int n,m,i,u,v,j,now;
    char c;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n*m-1;i++){
        scanf("%d %c %d",&u,&c,&v);
        u++;
        v++;
        if(c=='U'){
            a[u].down=v;
            a[v].up=u;
        }
        if(c=='L'){
            a[u].right=v;
            a[v].left=u;
        }
    }
    q.push({201,201,1});
    mark[201][201]=1;
    while(!q.empty()){
        i=q.front().i;
        j=q.front().j;
        now=q.front().now;
        //mark[i][j]=now;
        q.pop();
        if(a[now].up!=0 && mark[i-1][j]==0){
            mark[i-1][j]=a[now].up;
            q.push({i-1,j,a[now].up});
        }
        if(a[now].down!=0 && mark[i+1][j]==0){
            mark[i+1][j]=a[now].down;
            q.push({i+1,j,a[now].down});
        }
        if(a[now].left!=0 && mark[i][j-1]==0){
            mark[i][j-1]=a[now].left;
            q.push({i,j-1,a[now].left});
        }
        if(a[now].right!=0 && mark[i][j+1]==0){
            mark[i][j+1]=a[now].right;
            q.push({i,j+1,a[now].right});
        }
    }
    for(i=0;i<=450;i++){
        for(j=0;j<=450;j++){
            if(mark[i][j]!=0)goto jump;
        }
    }
    jump:;
    int tempi=i,tempj=j;
    //printf("%d %d\n",tempi,tempj);
    for(i=tempi;i<tempi+n;i++){
        for(j=tempj;j<tempj+m;j++){
            printf("%d ",mark[i][j]-1);
        }
        printf("\n");
    }
    return 0;
}
