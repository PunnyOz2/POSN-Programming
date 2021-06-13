/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int up,left,right,bottom;
};
A a[120][120];
int mark[120][120];
struct B{
    int i,j,tim;
};
queue<B>q;
int main()
{
    int n,m,i,j,tim;
    char lett;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf(" %c",&lett);
            if(lett=='B'){//east & bottom
                a[i][j].right=1;
                a[i][j].bottom=1;
                a[i][j+1].left=1;
                a[i+1][j].up=1;
            }
            if(lett=='R'){//east
                a[i][j].right=1;
                a[i][j+1].left=1;
            }
            if(lett=='D'){//bottom
                a[i][j].bottom=1;
                a[i+1][j].up=1;
            }
            if(lett=='N'){//No

            }
        }
    }
    q.push({1,1,1});
    mark[1][1]=1;
    while(!q.empty()){
        i=q.front().i;
        j=q.front().j;
        tim=q.front().tim;
        //printf("%d %d %d\n",i,j,tim);
        q.pop();
        if(a[i][j].up==1){
                //printf("    %d %d %d\n",i-1,j,tim+1);
            if(mark[i-1][j]==0){
                q.push({i-1,j,tim+1});
                mark[i-1][j]=tim+1;
            }
            else if(mark[i-1][j]==tim+1){
                printf("%d\n",tim+1);
                printf("%d %d\n",i-1,j);
                return 0;
            }
            else if(mark[i-1][j]==tim){
                printf("%d\n",tim);
                printf("%d %d\n",i,j);
                return 0;
            }
        }
        if(a[i][j].left==1){
                //printf("    %d %d %d\n",i,j-1,tim+1);
            if(mark[i][j-1]==0){
                q.push({i,j-1,tim+1});
                mark[i][j-1]=tim+1;
            }
            else if(mark[i][j-1]==tim+1){
                printf("%d\n",tim+1);
                printf("%d %d\n",i,j-1);
                return 0;
            }
            else if(mark[i][j-1]==tim){
                printf("%d\n",tim);
                printf("%d %d\n",i,j);
                return 0;
            }
        }
        if(a[i][j].right==1){
                //printf("    %d %d %d\n",i,j+1,tim+1);
            if(mark[i][j+1]==0){
                q.push({i,j+1,tim+1});
                mark[i][j+1]=tim+1;
            }
            else if(mark[i][j+1]==tim+1){
                printf("%d\n",tim+1);
                printf("%d %d\n",i,j+1);
                return 0;
            }
            else if(mark[i][j+1]==tim){
                printf("%d\n",tim);
                printf("%d %d\n",i,j);
                return 0;
            }
        }
        if(a[i][j].bottom==1){
                //printf("    %d %d %d\n",i+1,j,tim+1);
            if(mark[i+1][j]==0){
                q.push({i+1,j,tim+1});
                mark[i+1][j]=tim+1;
            }
            else if(mark[i+1][j]==tim+1){
                printf("%d\n",tim+1);
                printf("%d %d\n",i+1,j);
                return 0;
            }
            else if(mark[i+1][j]==tim){
                printf("%d\n",tim);
                printf("%d %d\n",i,j);
                return 0;
            }
        }
    }
    return 0;
}
/*
4 4
B R D N
D B N N
R R N N
N N N N
*/
