/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[10002];
int qs[2][10002];
int Maxh[2][10002];
int Maxw[2][10002];
int cou[2][10002];
int ch=1,ch2,jj;
int st,en;
int main()
{
    int n,m,i,j,Max=-1;
    int ans=0,ans2=0,ans3=0;
    scanf("%d %d",&m,&n);
    for(i=1;i<=n+1;i++){
        if(i==n+1)for(j=1;j<=m;j++)a[j]='0';
        else scanf(" %s",a+1);
        for(int j=1;j<=m;j++)   qs[i%2][j]=Maxh[i%2][j]=Maxw[i%2][j]=cou[i%2][j]=0;
        for(j=1;j<=m;j++){
            if(a[j]=='1'){
                qs[i%2][j]=qs[i%2][j-1]+1;
            }
            else qs[i%2][j]=0;
        }
        Max=-1;
        for(j=m;j>0;j--){
            if(a[j]=='1'){
                Max=max(qs[i%2][j],Max);
                qs[i%2][j]=Max;
            }
            else qs[i%2][j]=0,Max=-1;
        }
        for(j=1;j<=m;j++){
            if(a[j]=='0'){
                Maxh[i%2][j]=0;
                Maxw[i%2][j]=0;
                cou[i%2][j]=0;
                continue;
            }
            Maxh[i%2][j]=Maxh[(i+1)%2][j]+1;
            Maxw[i%2][j]=max(qs[i%2][j],Maxw[(i+1)%2][j]);
            cou[i%2][j]=qs[i%2][j]+cou[(i+1)%2][j];
        }
        for(j=1;j<=m;j++){
            if(a[j]=='0'){
                Maxh[i%2][j]=0;
                Maxw[i%2][j]=0;
                cou[i%2][j]=0;
                continue;
            }
            Maxh[i%2][j]=max(Maxh[i%2][j],Maxh[i%2][j-1]);
            Maxw[i%2][j]=max(Maxw[i%2][j],Maxw[i%2][j-1]);
            cou[i%2][j]=max(cou[i%2][j],cou[i%2][j-1]);
        }
        for(j=m;j>0;j--){
            if(a[j]=='0'){
                Maxh[i%2][j]=0;
                Maxw[i%2][j]=0;
                cou[i%2][j]=0;
                continue;
            }
            Maxh[i%2][j]=max(Maxh[i%2][j],Maxh[i%2][j+1]);
            Maxw[i%2][j]=max(Maxw[i%2][j],Maxw[i%2][j+1]);
            cou[i%2][j]=max(cou[i%2][j],cou[i%2][j+1]);
        }
        for(j=1;j<=m;j++){
            if(ch==1 && cou[(i+1)%2][j]!=0 )st=j,ch=0,en=j;
            if(ch==0 && cou[(i+1)%2][j]!=0)en=j;
            if(ch==0 && cou[(i+1)%2][j]==0){
                ch=1;
                ch2=1;
                for(jj=st;jj<=en;jj++){
                    if(cou[i%2][jj]!=0)ch2=0;
                }
                if(ch2==1){
                    if(Maxw[(i+1)%2][j-1]*Maxh[(i+1)%2][j-1]==cou[(i+1)%2][j-1])ans++;
                    else if(min(Maxw[(i+1)%2][j-1],Maxh[(i+1)%2][j-1])*min(Maxw[(i+1)%2][j-1],Maxh[(i+1)%2][j-1])==cou[(i+1)%2][j-1])ans3++;
                    else ans2++;
                    j=en;
                }
            }
        }
        //printf("%d %d %d %d\n",i,ans,ans2,ans3);
    }
    printf("%d %d %d\n",ans,ans2,ans3);
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
*/
