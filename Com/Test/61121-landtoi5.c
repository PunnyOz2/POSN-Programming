#include<stdio.h>
double a[5][5];
int mark[5][5],m,n,di[8]={1,-1,0,0,1,1,-1,-1},dj[8]={0,0,1,-1,1,-1,1,-1};
double min;
void play(int state,double pay){
    int k,nexti,nextj,i,j;
    if(state==n*m){
        if(pay<min){
                min=pay;}return;
    }
    else{
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(mark[i][j]==1)continue;
            mark[i][j]=1;
            for(k=0;k<8;k++){
                nexti=i+di[k],nextj=j+dj[k];
                if(nexti<0 || nexti>=m || nextj<0 ||nextj >=n){
                    continue;
                }
                a[nexti][nextj]+=0.1*a[i][j];
            }
            play(state+1,pay+a[i][j]);
            mark[i][j]=0;
            for(k=0;k<8;k++){
                nexti=i+di[k],nextj=j+dj[k];
                if(nexti<0 || nexti>=m || nextj<0 ||nextj >=n){
                    continue;
                }
                a[nexti][nextj]-=0.1*a[i][j];
            }
        }
    }
    }
}
int main()
{
    int i,j;
    //double min=10000000000;
    scanf("%d %d",&m,&n);
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%lf",&a[i][j]);
        }
    }
    play(0,0);
    printf("%.2lf",min);
    return 0;
}
/*
2 2
500 750 1000 800
*/
