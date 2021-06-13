/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int fw[2500][2500];
int main()
{
	int n,m,a,b,v,a2,b2,c,i,j;
	scanf("%d %d",&m,&n);
	while(1){
        scanf("%d",&c);
        if(c==1){
            scanf("%d %d %d",&a,&b,&v);
            for(i=a+1;i<=n;i+=(i&-i)){
                for(j=b+1;j<=n;j+=(j&-j)){
                    fw[i][j]+=v;
                }
            }
        }
        if(c==2){
            scanf("%d %d %d %d",&a,&b,&a2,&b2);
            v=0;
            for(i=a2+1;i>0;i-=(i&-i)){
                for(j=b2+1;j>0;j-=(j&-j)){
                    v+=fw[i][j];
                }
            }
            for(i=a;i>0;i-=(i&-i)){
                for(j=b;j>0;j-=(j&-j)){
                    v+=fw[i][j];
                }
            }
            for(i=a2+1;i>0;i-=(i&-i)){
                for(j=b;j>0;j-=(j&-j)){
                    v-=fw[i][j];
                }
            }
            for(i=a;i>0;i-=(i&-i)){
                for(j=b2+1;j>0;j-=(j&-j)){
                    v-=fw[i][j];
                }
            }
            printf("%d\n",v);
        }
        if(c==3){
            return 0;
        }
	}
    return 0;
}
