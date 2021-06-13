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
    int i,j=0,idx=0,n,m,no1,cou=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=m;i++){
        scanf("%d",&b[no1]);
        if(b[no1]==1){
            j=0;
            for(i=2;i<=no1;i++){
                if(j>0 && b[j+1]!=b[i])j=pi[j];
                if(b[j+1]==b[i])j++;
                pi[i]=j;
            }
            j=0;
            for(i=1;i<=n;i++){
                if(j>0 && b[j+1]!=a[i])j=pi[j];
                if(b[j+1]==a[i])j++;
                if(j==m){
                    mark[idx][i]=1;
                }
                idx++;
            }
            no1=0;
        }
        no1++;
    }
    j=0;
    for(i=2;i<=no1;i++){
        if(j>0 && b[j+1]!=b[i])j=pi[j];
        if(b[j+1]==b[i])j++;
        pi[i]=j;
    }
    j=0;
    for(i=1;i<=n;i++){
        if(j>0 && b[j+1]!=a[i])j=pi[j];
        if(b[j+1]==a[i])j++;
        if(j==m){
            mark[idx][i]=1;
        }
        idx++;
    }
    return 0;
}
