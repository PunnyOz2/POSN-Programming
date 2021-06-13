/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[200100];
int b[200100];
int pi[200100];
int mark[12][200100];
int space1[12];
int main()
{
    int i,j=0,idx=0,n,m,no1=1,cou=0,ii;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=m;i++){
        scanf("%d",&b[no1]);
        if(b[no1]==1 && no1>1 && i!=m && b[no1-1]!=1){
            j=0;
            space1[idx]=no1;
            no1--;
            for(ii=2;ii<=no1;ii++){
                while(j>0 && b[j+1]!=b[ii])j=pi[j];
                if(b[j+1]==b[ii])j++;
                pi[ii]=j;
            }
            j=0;
            for(ii=1;ii<=n;ii++){
                while(j>0 && b[j+1]!=a[ii])j=pi[j];
                if(b[j+1]==a[ii])j++;
                if(j==no1){
                    //printf("%d ",ii);
                    mark[idx][ii]=1;
                }
            }
            no1=0;
            idx++;
        }
        else if(b[no1]==1)no1=0;
        no1++;
    }
    j=0;
    if(b[no1]==1)no1--;
    for(i=2;i<=no1;i++){
        while(j>0 && b[j+1]!=b[i])j=pi[j];
        if(b[j+1]==b[i])j++;
        pi[i]=j;
        //printf("%d ",pi[i]);
    }
    j=0;
    for(i=1;i<=n;i++){
        while(j>0 && b[j+1]!=a[i])j=pi[j];
        if(b[j+1]==a[i])j++;
        if(j==no1){
            mark[idx][i]=1;
            //printf("%d ",i);
        }
    }
    idx++;
    cou=0;
//    for(i=0;i<=3;i++){
//        for(j=1;j<=n;j++)printf("%d ",mark[i][j]);
//        printf("\n");
//    }
    for(i=0;i<=m;i++){
        printf("%d ",space1[i]);
    }
    int now;
    for(i=1;i<=n;i++){
        if(mark[0][i]==1){
            now=i;
            for(j=1;j<idx;j++){
                if(mark[j][now+space1[j]+1]!=1)break;
                now+=space1[j];
            }
            if(j==idx){
                cou++;
            }
        }
    }
    //for(i=0;i<idx;i++)printf("%d ",space1[i]);
    printf("%d\n",cou);
    return 0;
}
/*
8 3
2 3 2 2 3 2 3 2
2 3 2

8 5
13 11 13 11 13 17 13 13
11 1 1 13 1

*/
