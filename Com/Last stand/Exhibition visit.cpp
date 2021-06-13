/*
    TASK: Exhibition Visit
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int room[15][5],n,mark[20];
int play(int state,int i,int j){
    int sum=1,l;
    for(l=0;l<n;l++){
        if(mark[l]!=1){
        if(room[l][0]==i&&room[l][1]==room[state][2]+1){
                mark[l]=1;
                sum+= play(l,room[l][0],room[l][1]);
                mark[l]=0;
            }
        else if(room[l][0]==i-1&&room[l][1]<=room[state][2]&&j<=room[l][2]){
                mark[l]=1;
                sum+= play(l,room[l][0],max(room[l][1],j));
                mark[l]=0;
            }
        else if(room[l][0]==i+1&&room[l][1]<=room[state][2]&&j<=room[l][2]){
                mark[l]=1;
                sum+= play(l,room[l][0],max(room[l][1],j));
                mark[l]=0;
            }
        }
    }
    return sum;
}
int main()
{
    int q,i;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d %d %d",&room[i][0],&room[i][1],&room[i][2]);
        mark[0]=1;
        printf("%d\n",play(0,room[0][0],room[0][1]));
    }

    return 0;
}
/*
1 5 1 0 3 0 2 6 1 6 9 2 3 8 3 7 9
*/
