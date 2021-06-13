/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int x[100003],y[100003];
int l[100003],r[100003],r2[100003];
int main()
{
    int n,m,i,j,cou,Max=0,ii,jj,ans=-1,temp;
    scanf("%d %d",&n,&m);
    int ch=0;
    for(i=1;i<=n;i++){
        scanf("%d %d",&ii,&jj);
        if(ch==1)continue;
        x[jj]++;
        y[ii]++;
        l[ii+jj]++;
        if(ii>=jj){
            r[ii-jj]++;
            if(r[ii-jj]>=m){ans=i;ch=1;}
        }
        if(jj>=ii){
            r2[jj-ii]++;
            if(r2[jj-ii]>=m){ans=i;ch=1;}
        }
        if(x[jj]>=m || y[ii]>=m || l[ii+jj]>=m ){ans=i;ch=1;}
    }
    printf("%d\n",ans);
    return 0;
}
/*
5 3
1 3
3 5
3 3
4 6
5 7
*/
