/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int fw[500100];
char c[6];
int main()
{
	int n,m,v,a,b,i;
	scanf("%d %d",&n,&m);
	while(m--){
        scanf(" %s",c);
        if(c[0]=='Y'){
            scanf("%d %d %d",&v,&a,&b);
            if(a>b)swap(a,b);
            for(i=a;i<=n;i+=(i&-i)){
                fw[i]+=v;
            }
            for(i=b+1;i<=n;i+=(i&-i)){
                fw[i]-=v;
            }
        }
        else{
            scanf("%d",&a);
            int ans=0;
            for(i=a;i>0;i-=(i&-i)){
                ans+=fw[i];
            }
            printf("%d\n",ans);
        }
	}
    return 0;
}
/*
7 6
Y 10 4 7
Y 15 1 5
Ask 4
Y 5 3 6
A 5
A 7
*/
