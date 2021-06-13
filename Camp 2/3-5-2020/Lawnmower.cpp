/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[110][110],Maxi[110],Maxj[110];
int main()
{
    int q,n,m,i,j,Max,ch,qq=1;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                scanf("%d",&a[i][j]);
                Maxi[i]=max(Maxi[i],a[i][j]);
                Maxj[j]=max(Maxj[j],a[i][j]);
            }
        }
        ch=1;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(a[i][j]<Maxi[i] && a[i][j]<Maxj[j])ch=0;
            }
        }
        if(ch==1){
            printf("Case #%d: YES\n",qq);
        }
        else{
            printf("Case #%d: NO\n",qq);
        }
        qq++;
        memset(Maxi,0,sizeof Maxi);
        memset(Maxj,0,sizeof Maxj);
    }
    return 0;
}
/*
3
3 3
2 1 2
1 1 1
2 1 2
5 5
2 2 2 2 2
2 1 1 1 2
2 1 2 1 2
2 1 1 1 2
2 2 2 2 2
*/
