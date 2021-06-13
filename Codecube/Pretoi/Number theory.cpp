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
int c[200100];
int pi[200100];
int mark[12][200100];
int len[12];
int en[12];
int main()
{
    int i,j=0,idx=0,n,m,no1=1,cou=0,ii,ch=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=m;i++){
        scanf("%d",&c[i]);
        if(c[i]==1)ch=1;
    }
    if(ch==0){
        j=0;
        for(i=2;i<=m;i++){
            while(j>0 && c[j+1]!=c[i])j=pi[j];
            if(c[j+1]==c[i])j++;
            pi[i]=j;
        }
        j=0;
        for(i=1;i<=n;i++){
            while(j>0 && c[j+1]!=a[i])j=pi[j];
            if(c[j+1]==a[i])j++;
            if(j==m){
                cou++;
            }
        }
        printf("%d\n",cou);
    }
    else{
        for(i=1;i<=m;i++){
            if(c[i]!=1)break;
        }
        int sti=i;
        for(i=m;i>0;i--){
            if(c[i]!=1)break;
        }
        idx=1;
        int eni=i;
        int run=1;
        c[eni+1]=1;
        for(ii=sti;ii<=eni+1;ii++){
            if(c[ii]==1){
                if(run==1)continue;
                    printf("hi\n");
                    j=0;
                    run--;
                    for(i=2;i<=run;i++){
                        while(j>0 && b[j+1]!=b[i])j=pi[j];
                        if(b[j+1]==b[i])j++;
                        pi[i]=j;
                    }
                    j=0;
                    for(i=1;i<=n;i++){
                        while(j>0 && b[j+1]!=a[i])j=pi[j];
                        if(b[j+1]==a[i])j++;
                        if(j==run){
                            mark[idx][i]=1;
                        }
                    }
                len[idx]=ii-1-en[idx-1];
                en[idx++]=ii-1;
                run=1;
                memset(b,0,sizeof b);
                //memset(pi,0,sizeof pi);
            }
            else b[run]=c[i],run++;
        }
        for(i=0;i<idx;i++){
            for(j=1;j<=n;j++){
                printf("%d ",mark[i][j]);
            }
            printf("\n");
        }
        int now;
        for(i=en[1];i<=n;i++){
            now=i;
            if(mark[1][i]==1){
                for(j=2;j<idx;j++){
                    now=now+len[j];
                    if(mark[i][now]!=1)goto jump;
                }
                cou++;
                jump:;
            }
        }
        printf("%d\n",cou);
    }
    return 0;
}
/*
9 6
2 3 2 3 2 3 2 3 2
2 3 2 3 2 3

8 5
13 11 13 11 13 17 13 13
11 1 1 13 1

*/
