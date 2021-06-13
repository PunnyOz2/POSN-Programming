#include<bits/stdc++.h>
using namespace std;
int a[100100],pos[100100];
void update(int idx,int v){
    while(idx<=100003){
        a[idx]+=v;
        idx+=idx & -idx;
    }
}
int query(int idx){
    int sum = 0;
    while(idx>0){
        sum+=a[idx];
        idx-=idx & -idx;
    }
    return sum;
}
int main()
{
	int q,i,num,ansnum=0,ch,n,ans=0,j;
	scanf("%d",&q);
	while(q--){
        ch=1;
        ans=0;
        memset(a,0,sizeof a);
        scanf("%d",&n);
        for(j=1;j<=n;j++){
            scanf("%d",&num);
            pos[j] = num;
        }
        for(int i=n;i>=1;i--){
            ansnum = query(pos[i]-1);
            update(pos[i],1);
            //printf("%d\n",ansnum);
            if(ansnum>2){
                ch = 0;
                break;
            }
            ans+=ansnum;
        }
        if(ch==0){printf("CHEAT\n");}
        else printf("%d\n",ans);
	}
    return 0;
}
/*
2
5
2 1 5 3 4
5
2 5 1 3 4

10
5
2 3 4 5 1
*/
