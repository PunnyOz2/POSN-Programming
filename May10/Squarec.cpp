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
    int n,Maxx=-1,Minx=1000,Miny=1000,Maxy=-1,i,x,y;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&x,&y);
        Maxx=max(Maxx,x);
        Minx=min(Minx,x);
        Maxy=max(Maxy,y);
        Miny=min(Miny,y);
    }
    int num=max(Maxx-Minx,Maxy-Miny);
    num=num*num;
    printf("%d\n",num);
    return 0;
}
