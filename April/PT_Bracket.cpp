/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[50500];
long long br[50500],brcl[50500];
priority_queue<int> h;
int main()
{
	long long q,lena,cou,open,close,i,j,ans;
	scanf("%lld",&q);
	while(q--){
        scanf(" %s",a);
        lena=strlen(a);
        cou=0;
        for(i=0;i<lena;i++){
            if(a[i]=='?')cou++;
        }
        for(i=0;i<cou;i++){
            scanf("%lld %lld",&open,&close);
            br[i]=open-close;
            brcl[i]=close;
        }
        cou=0;
        ans=0;
        j=0;
        for(i=0;i<lena;i++){
            if(a[i]=='(')cou++;
            else if(a[i]=='?')cou--,h.push(br[j]*-1),ans+=brcl[j++];
            else if(a[i]==')')cou--;
            while( !h.empty() && cou<0){
                cou+=2;
                ans-=h.top();
                h.pop();
            }
            if(cou<0){printf("-1\n");goto jump;}
        }
        if(cou!=0)printf("-1\n");
        else printf("%lld\n",ans);
        jump:;
        while(!h.empty())h.pop();
	}
    return 0;
}
/*
1
(??)
1 2
2 8
*/
