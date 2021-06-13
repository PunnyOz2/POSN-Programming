/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[110][110],mi[110],mj[110];
int main(){
    int q,i,j,r,c,cou=0,ch;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&r,&c);
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                scanf("%d",&a[i][j]);
                mi[i]=max(mi[i],a[i][j]);
                mj[j]=max(mj[j],a[i][j]);
            }
        }
        for(i=0,ch=1;i<r;i++){
            for(j=0;j<c;j++){
                if(a[i][j]<mi[i]&&a[i][j]<mj[j]) ch=0;
            }
        }
        printf("Case #%d: ",++cou);
        printf((ch)?"YES\n":"NO\n");
        memset(mi,0,sizeof mi);
        memset(mj,0,sizeof mj);


    }

    return 0;
}
/*
4 4
B R D N
D R B D
R R R D
N N N N
*/
