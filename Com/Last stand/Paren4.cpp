/*
    TASK: Paren4
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int n,cou=0;
char ans[100000][30],a[30];
void play(int open,int close,int state){
    int i;
    if(open<close||state>2*n) return;
    if(open==n&&close==n){
        a[2*n]='\0';
        strcpy(ans[cou++],a);
        return;
    }
    a[state]='(';
    play(open+1,close,state+1);
    a[state]=')';
    play(open,close+1,state+1);
}
int main()
{
    int i;
    scanf("%d",&n);
    play(0,0,0);
    printf("%d\n",cou);
    for(i=0;i<cou;i++){
        printf("%s\n",ans[i]);
    }

    return 0;
}
