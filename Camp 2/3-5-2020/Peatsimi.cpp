/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[11][3],cou[11];
int main()
{
    int r,c,n,idx,Min,i,j,k;
    scanf("%d %d %d",&r,&c,&n);
    for(i=1;i<=n;i++){
        scanf("%d %d",&a[i][0],&a[i][1]);
    }
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            Min=1<<30;
            for(k=1;k<=n;k++){
                if(Min>abs(a[k][0]-i)+abs(a[k][1]-j))Min=abs(a[k][0]-i)+abs(a[k][1]-j),idx=k;
            }
            cou[idx]++;
        }
    }
    for(i=1;i<=n;i++){
        printf("%d\n",cou[i]);
    }
    return 0;
}
