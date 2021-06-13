/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[6];
int fw[800000];
int main()
{
	int n,m,u,v,pl,i;
	scanf("%d %d",&n,&m);
	while(m--){
        scanf(" %s",a);
        if(a[0]=='B'){
            scanf("%d %d",&v,&pl);
            for(i=pl;i<=n;i+=(i&-i)){
                fw[i]+=v;
            }
        }
        else{
            scanf("%d %d",&v,&pl);
            int ans=0;
            for(i=pl;i>0;i-=(i&-i)){
                ans+=fw[i];
            }
            for(i=v-1;i>0;i-=(i&-i)){
                ans-=fw[i];
            }
            printf("%d\n",ans);
        }
	}
    return 0;
}
