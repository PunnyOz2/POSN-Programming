/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int mark[5][105][105][105];
int play(int a,int b,int c,int last){
    if(a==1 && b==0 && c==0 && last!=0)return 1;
    if(a==0 && b==1 && c==0 && last!=1)return 1;
    if(a==0 && b==0 && c==1 && last!=2)return 1;
    if(mark[last][a][b][c]!=-1)return mark[last][a][b][c];
    int ans=0;
    if(last==0){
        if(b>0)
            ans+=play(a,b-1,c,1);
        if(c>0)
            ans+=play(a,b,c-1,2);
    }
    else if(last==1){
        if(a>0)
            ans+=play(a-1,b,c,0);
        if(c>0)
            ans+=play(a,b,c-1,2);
    }
    else if(last==2){
        if(a>0)
            ans+=play(a-1,b,c,0);
        if(b>0)
            ans+=play(a,b-1,c,1);
    }
    return mark[last][a][b][c]=ans%100003;
}
int main()
{
	int q,sum,a,b,c;
	scanf("%d",&q);
	memset(mark,-1,sizeof mark);
	while(q--){
        sum=0;
        scanf("%d %d %d",&a,&b,&c);
        if(a>0)
            sum+=play(a-1,b,c,0);
        if(b>0)
            sum+=play(a,b-1,c,1);
        if(c>0)
            sum+=play(a,b,c-1,2);
        if(a==1 && b==0 && c==0)sum=1;
        if(a==0 && b==1 && c==0)sum=1;
        if(a==0 && b==0 && c==1)sum=1;
        printf("%d\n",sum%100003);
	}
    return 0;
}
