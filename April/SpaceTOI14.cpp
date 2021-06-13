/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,idx,cou,done,chans3;
};
queue<A>q;
char row[2100];
int a[2][2100];
int main()
{
	int m,n,cou,ans1=0,ans2=0,ans3=0,i,j;
	scanf("%d %d",&m,&n);
	for(i=0;i<n;i++){
        scanf(" %s",row);
        cou=0;
        for(j=0;j<=m;j++){
            while(!q.empty() && q.front().i<i-1)q.pop();
            a[i%2][j]=row[j]-'0';
            if(a[i%2][j]==1){
                cou++;
            }
            else if((a[i%2][j]==0||j==m) && cou!=0){
                if(q.front().idx==j-cou/2){
                    if(q.front().cou==cou){
                        if(q.front().done==0)
                            ans1++;
                        q.push({i,j-cou/2,cou,1,0});
                    }
                    else if(q.front().cou==cou-2){
                        if(q.front().done==0)
                            ans3++;
                        q.push({i,j-cou/2,cou,1,1});
                    }
                    else if(q.front().cou==cou+2 && q.front().chans3==1){
                        ans2++;
                        ans3--;
                        q.push({i,j-cou/2,cou,1,0});
                    }
                    else if(q.front().cou==cou+2){
                        if(q.front().done==0)
                            ans3++;
                        q.push({i,j-cou/2,cou,1,0});
                    }
                else if(q.front().idx==j-cou/2-1){
                    if(q.front().done==0)
                        ans3++;
                        q.push({i,j-cou/2,cou,1,0});
                }
                else if(q.front().idx==j-cou/2-1){
                    if(q.front().done==0)
                        ans3++;
                        q.push({i,j-cou/2,cou,1,0});
                    }
                else if(q.front().idx==j-cou/2+1){
                    if(q.front().done==0)
                        ans3++;
                        q.push({i,j-cou/2,cou,1,0});
                    }
                    q.pop();
                }
                else q.push({i,j-cou/2,cou,0,0});
                cou=0;
            }
        }
        printf("%d %d %d\n",ans1,ans2,ans3);
	}
	printf("%d %d %d\n",ans1,ans2,ans3);
    return 0;
}
/*
20 12
00000000000000000000
00100000001111111110
01110000000111111100
11111000000011111000
00000000000001110000
00000000000000100000
00000000000000000000
00011111000000000000
00011111000000000000
00011111000000000000
00011111000000000000
00011111000000000000

20 12
00000000000000000000
00000011000000000000
00000011000000000000
00000000000011110000
00000000000011110000
00000000000011110000
00000000000000000000
00011111000000000000
00011111000000000000
00011111000000000000
00011111000000000000
00011111000000000000
*/
