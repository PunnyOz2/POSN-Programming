/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[100100];
int main()
{
    int n,lena,ans=0,i;
    scanf("%d",&n);
    while(n--){
        scanf(" %s",a);
        lena=strlen(a);
        for(i=0;i<lena;i++){
            if(a[i]=='J')ans++;
            if(a[i]=='Q')ans+=2;
            if(a[i]=='K')ans+=3;
            if(a[i]=='A')ans+=4;
        }
        printf("%d\n",ans);
        ans=0;
    }
    return 0;
}
/*
10
a 0
a 1
a 2
a 3
a 2
c 4 5
a 5
b 7
b 7
c 9 7
*/
