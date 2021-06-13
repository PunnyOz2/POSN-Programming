/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[102][22];
//string anss;
int main()
{
    int n,aa,b,Max=-1,cou=0,ans=0,temp,anss;
    scanf("%d",&n);
    while(n--){
        scanf(" %s",a[n]);
        scanf("%d %d",&aa,&b);
        cou=0;
        while(b>=aa){
            temp=b/aa;
            b-=aa*temp;
            cou+=temp;
            b+=temp*2;
        }
        if(Max<cou)Max=cou,anss=n;
        ans+=cou;
    }
    printf("%d\n",ans);
    printf("%s\n",a[anss]);
    return 0;
}
