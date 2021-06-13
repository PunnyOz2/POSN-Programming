/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    char p[120];
    int n,pl,i,ans=0,cou=0;
    scanf("%d",&n);
    while(n--){
        scanf(" %s",p);
        pl=strlen(p);
        p[pl++]='+';
        for(i=1,ans=0;i<pl;i++){
            if(p[i]!=p[i-1])ans++;
        }
    printf("Case #%d: %d\n",++cou,ans);
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
