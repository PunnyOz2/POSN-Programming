/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
int ans[100100][20],mark[20],a[20],b,c,d[20],cou;
void play(int state,int sum){
    if(state>c||sum>b) return;
    int i;
    if(sum==b){
        ans[cou][0]=state;
        for(i=0;i<state;i++)
            ans[cou][i+1]=d[i];
        cou++;
        return;
    }
    for(i=0;i<6;i++){
        d[state] = a[i];
        play(state+1,sum+a[i]);
    }
}
int main()
{
    int i,j;
    scanf("%d %d",&b,&c);
    for(i=0;i<6;i++)
        scanf("%d",&a[i]);
    play(0,0);
    printf("%d\nE\n",cou);
    for(i=0;i<cou;i++){
        printf("%d ",ans[i][0]);
        for(j=0;j<ans[i][0];j++)
            printf("%d ",ans[i][j+1]);
        printf("\nE\n");
    }

    return 0;
}
