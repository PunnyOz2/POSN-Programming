/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int fw[500100];
string a;
int main()
{
    int n,m,p,b,c,i,ans;
    scanf("%d %d",&n,&m);
    while(m--){
        cin>>a;
        if(a=="Yoyo"){
            scanf("%d %d %d",&p,&b,&c);
            if(b>c)swap(b,c);
            for(i=b;i<=n;i+=(i&-i))
                fw[i]+=p;
            for(i=c+1;i<=n;i+=(i&-i))
                fw[i]-=p;
        }
        else if(a=="Ask"){
            scanf("%d",&b);
            ans=0;
            for(i=b;i>0;i-=(i&-i))
                ans+=fw[i];
            printf("%d\n",ans);
        }
    }
    return 0;
}
/*
7 6
Yoyo 10 4 7
Yoyo 15 1 5
*/
