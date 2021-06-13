/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[600][600];
int mic[10][600][600];
int qs[600][600];
int play(int ni,int topi,int topj){
    if(mic[ni][topi][topj]!=-1)return mic[ni][topi][topj];
    if(ni==0)return mic[ni][topi][topj]=0;
    int mi=(1<<30),midi=topi+(1<<(ni-1)),midj=topj+(1<<(ni-1)),endi=topi+(1<<(ni)),endj=topj+(1<<(ni));
    mi=min(mi,play(ni-1,topi,topj)+play(ni-1,topi,midj)+abs(    qs[endi-1][endj-1]-qs[endi-1][midj-1]-qs[midi-1][endj-1]+qs[midi-1][midj-1]     -((1<<ni)*(1<<ni)/4)     )+qs[endi-1][midj-1]-qs[endi-1][topj-1]-qs[midi-1][midj-1]+qs[midi-1][topj-1]);
    mi=min(mi,play(ni-1,topi,topj)+play(ni-1,topi,midj)+abs(    qs[endi-1][midj-1]-qs[endi-1][topj-1]-qs[midi-1][midj-1]+qs[midi-1][topj-1]     -((1<<ni)*(1<<ni)/4)     )+qs[endi-1][endj-1]-qs[endi-1][midj-1]-qs[midi-1][endj-1]+qs[midi-1][midj-1]);

    mi=min(mi,play(ni-1,topi,topj)+play(ni-1,midi,topj)+abs(    qs[endi-1][endj-1]-qs[endi-1][midj-1]-qs[midi-1][endj-1]+qs[midi-1][midj-1]     -((1<<ni)*(1<<ni)/4)     )+qs[midi-1][endj-1]-qs[midi-1][midj-1]-qs[topi-1][endj-1]+qs[topi-1][midj-1]);
    mi=min(mi,play(ni-1,topi,topj)+play(ni-1,midi,topj)+abs(    qs[midi-1][endj-1]-qs[midi-1][midj-1]-qs[topi-1][endj-1]+qs[topi-1][midj-1]     -((1<<ni)*(1<<ni)/4)     )+qs[endi-1][endj-1]-qs[endi-1][midj-1]-qs[midi-1][endj-1]+qs[midi-1][midj-1]);

    mi=min(mi,play(ni-1,midi,midj)+play(ni-1,midi,topj)+abs(    qs[midi-1][endj-1]-qs[midi-1][midj-1]-qs[topi-1][endj-1]+qs[topi-1][midj-1]     -((1<<ni)*(1<<ni)/4)     )+qs[midi-1][midj-1]-qs[topi-1][midj-1]-qs[midi-1][topj-1]+qs[topi-1][topj-1]);
    mi=min(mi,play(ni-1,midi,midj)+play(ni-1,midi,topj)+abs(    qs[midi-1][midj-1]-qs[topi-1][midj-1]-qs[midi-1][topj-1]+qs[topi-1][topj-1]     -((1<<ni)*(1<<ni)/4)     )+qs[midi-1][endj-1]-qs[midi-1][midj-1]-qs[topi-1][endj-1]+qs[topi-1][midj-1]);

    mi=min(mi,play(ni-1,midi,midj)+play(ni-1,topi,midj)+abs(    qs[midi-1][midj-1]-qs[topi-1][midj-1]-qs[midi-1][topj-1]+qs[topi-1][topj-1]     -((1<<ni)*(1<<ni)/4)     )+qs[endi-1][midj-1]-qs[endi-1][topj-1]-qs[midi-1][midj-1]+qs[midi-1][topj-1]);
    mi=min(mi,play(ni-1,midi,midj)+play(ni-1,topi,midj)+abs(    qs[endi-1][midj-1]-qs[endi-1][topj-1]-qs[midi-1][midj-1]+qs[midi-1][topj-1]     -((1<<ni)*(1<<ni)/4)     )+qs[midi-1][midj-1]-qs[topi-1][midj-1]-qs[midi-1][topj-1]+qs[topi-1][topj-1]);

    mi=min(mi,play(ni-1,midi,midj)+play(ni-1,topi,topj)+abs(    qs[midi-1][endj-1]-qs[midi-1][midj-1]-qs[topi-1][endj-1]+qs[topi-1][midj-1]     -((1<<ni)*(1<<ni)/4)     )+qs[endi-1][midj-1]-qs[endi-1][topj-1]-qs[midi-1][midj-1]+qs[midi-1][topj-1]);
    mi=min(mi,play(ni-1,midi,midj)+play(ni-1,topi,topj)+abs(    qs[endi-1][midj-1]-qs[endi-1][topj-1]-qs[midi-1][midj-1]+qs[midi-1][topj-1]     -((1<<ni)*(1<<ni)/4)     )+qs[midi-1][endj-1]-qs[midi-1][midj-1]-qs[topi-1][endj-1]+qs[topi-1][midj-1]);

    mi=min(mi,play(ni-1,midi,topj)+play(ni-1,topi,midj)+abs(    qs[endi-1][endj-1]-qs[endi-1][midj-1]-qs[midi-1][endj-1]+qs[midi-1][midj-1]     -((1<<ni)*(1<<ni)/4)     )+qs[midi-1][endj-1]-qs[midi-1][midj-1]-qs[topi-1][endj-1]+qs[topi-1][midj-1]);
    mi=min(mi,play(ni-1,midi,topj)+play(ni-1,topi,midj)+abs(    qs[midi-1][endj-1]-qs[midi-1][midj-1]-qs[topi-1][endj-1]+qs[topi-1][midj-1]     -((1<<ni)*(1<<ni)/4)     )+qs[endi-1][endj-1]-qs[endi-1][midj-1]-qs[midi-1][endj-1]+qs[midi-1][midj-1]);
    return mic[ni][topi][topj]=mi;
}
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf(" %c",&a[i][j]);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+a[i][j]-'0';
    memset(mic,-1,sizeof mic);
    printf("%d\n",play(log2(n),1,1));
    return 0;
}
/*
4
0001
0001
0011
1110
*/
