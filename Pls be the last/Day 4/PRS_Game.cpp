/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q,n,ch,i,last,now;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        ch=1;
        last=-1;
        for(i=0;i<n;i++){
            scanf("%d",&now);
            if(last==2 && now==2) ch=0;
            last=now;
        }
        if(ch)printf("Valid\n");
        else printf("Invalid\n");
    }
    return 0;
}
