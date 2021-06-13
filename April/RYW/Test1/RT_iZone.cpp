/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int fw[1000100][3];
char c[1000100];
int main()
{
	int n,m,com,i,j,a,b;
	char col;
	scanf("%d %d",&n,&m);
	for(j=1;j<=n+3;j+=3){
        c[j]='R';
        for(i=j;i<=n+3;i+=(i&-i)){
            fw[i][0]+=1;
        }
	}
	for(j=2;j<=n+3;j+=3){
        c[j]='G';
        for(i=j;i<=n+3;i+=(i&-i)){
            fw[i][1]+=1;
        }
	}
	for(j=3;j<=n+3;j+=3){
	    c[j]='B';
        for(i=j;i<=n+3;i+=(i&-i)){
            fw[i][2]+=1;
        }
	}
	while(m--){
        scanf("%d",&com);
        if(com==1){
            scanf("%d %c",&com,&col);
            if(col=='R'){
                if(c[com]=='G'){
                    for(i=com;i<=n+3;i+=(i&-i)){
                        fw[i][1]-=1;
                    }
                }
                if(c[com]=='B'){
                    for(i=com;i<=n+3;i+=(i&-i)){
                        fw[i][2]-=1;
                    }
                }
                if(c[com]!='R'){
                    for(i=com;i<=n+3;i+=(i&-i)){
                        fw[i][0]+=1;
                    }
                }
                c[com]='R';
            }
            if(col=='G'){
                if(c[com]=='R'){
                    for(i=com;i<=n+3;i+=(i&-i)){
                        fw[i][0]-=1;
                    }
                }
                if(c[com]=='B'){
                    for(i=com;i<=n+3;i+=(i&-i)){
                        fw[i][2]-=1;
                    }
                }
                if(c[com]!='G'){
                    for(i=com;i<=n+3;i+=(i&-i)){
                        fw[i][1]+=1;
                    }
                }
                c[com]='G';
            }
            if(col=='B'){
                if(c[com]=='G'){
                    for(i=com;i<=n+3;i+=(i&-i)){
                        fw[i][1]-=1;
                    }
                }
                if(c[com]=='R'){
                    for(i=com;i<=n+3;i+=(i&-i)){
                        fw[i][0]-=1;
                    }
                }
                if(c[com]!='B'){
                    for(i=com;i<=n+3;i+=(i&-i)){
                        fw[i][2]+=1;
                    }
                }
                c[com]='B';
            }
//            for(i=1;i<=n+3;i++)printf("%c ",c[i]);
//            cout << endl;
        }else{
            scanf("%d %d",&a,&b);
            int ans=0,ans1=0,ans2=0;
            for(i=b;i>0;i-=(i&-i)){
                ans+=fw[i][0];
                ans1+=fw[i][1];
                ans2+=fw[i][2];
            }
            for(i=a-1;i>0;i-=(i&-i)){
                ans-=fw[i][0];
                ans1-=fw[i][1];
                ans2-=fw[i][2];
            }
            //printf("%d %d %d\n",ans,ans1,ans2);
            if(ans>ans1 && ans>ans2)printf("R\n");
            else if(ans1>ans && ans1>ans2)printf("G\n");
            else if(ans2>ans && ans2>ans1)printf("B\n");
            else printf("None\n");
        }
	}
    return 0;
}
/*
10 7
1 2 R
2 1 5
1 5 B
1 3 G
2 4 8
2 1 8
2 5 6
*/
