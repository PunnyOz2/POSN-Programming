/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int type,i,j,w;
    bool operator<(const A&o)const{
        if(w!=o.w)return w>o.w;
        return type<o.type;
    }
};
priority_queue<A> q;
int di[4]={1,-1,0,0},dj[4]={0,0,1,-1},Max;
char a[750][750];
int mark[750][750],mark2[750][750];
int main()
{
    int Q,r,c,ni,j,n,t,sti,stj,i,ii,jj,w,k,nj,T,type,cou,TIM;
    scanf("%d",&Q);
    while(Q--){
        scanf("%d %d %d %d %d %d",&r,&c,&n,&t,&sti,&stj);
        sti++;stj++;
        for(i=1;i<=n;i++){
            scanf("%d %d %d",&T,&ii,&jj);
            ii++,jj++;
            q.push({1,ii,jj,T});
            if(T==0)mark[ii][jj]=1;
        }
        for(i=1;i<=r;i++){
            scanf(" %s",a[i]+1);
        }
        if(mark[sti][stj]==1){printf("NO -1\n");goto jump;}
        q.push({0,sti,stj,0});
        mark2[sti][stj]=1;
        cou=1;
        //GHOST TABLE
        t++;
        TIM=-1;
        while(t--){
            TIM++;
            while(!q.empty() && q.top().w<=TIM){
                type=q.top().type;
                i=q.top().i;
                j=q.top().j;
                w=q.top().w;
                q.pop();
//                printf("%d %d %d %d %d\n",type,i,j,w,cou);
                //if(type==0 && mark[i][j]==1)continue;
                if(type==1 && mark2[i][j]==1 && (mark[i][j]==0 || mark[i][j]==w+1)){
                    mark[i][j]=w;
                    cou--;
//                    printf("HI\n");
                }
                for(k=0;k<4;k++){
                    ni=i+di[k];
                    nj=j+dj[k];
                    if(ni<1 || nj<1 || ni>r || nj>c)continue;
                    if(a[ni][nj]=='#')continue;
                    if(type==1 && mark[ni][nj]==0){
                        if(mark2[ni][nj]==1)cou--;
                        mark[ni][nj]=w+1,q.push({1,ni,nj,w+1});
                    }
                    if(type==0 && mark2[ni][nj]==0 && mark[ni][nj]==0){
                        q.push({0,ni,nj,w+1}),cou++,mark2[ni][nj]=1;
                    }
                }
//                printf("%d\n",cou);
                if(cou<=0){
                    printf("NO %d\n",TIM-1);
                    break;
                }
            }
        }
        if(cou>0)printf("YES\n");
        jump:;
        while(!q.empty())q.pop();
        memset(mark,0,sizeof mark);
        memset(mark2,0,sizeof mark2);
    }
    return 0;
}
/*
4
2 5 1 1 0 2
1 0 2
.#.#.
..#..
2 5 1 1 0 2
0 0 2
.....
.....


2 5 4 1 0 2
1 0 2
1 0 3
1 0 1
1 1 2
.....
.....

5 5 2 10 2 2
0 0 0
0 4 4
.....
.###.
.#.#.
.###.
.....

*/
