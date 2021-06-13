/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<stdio.h>
using namespace std;
int path[60][60],in[60],out[60];
int main()
{
    int n,q,i,j,k,temp=1;
    char a;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){//incoming
            scanf(" %c",&a);
            path[i][i]=1;
            if(a=='Y'){
                in[i]=1;
            }
            else in[i]=0;
        }
        for(i=1;i<=n;i++){//outgoing
            scanf(" %c",&a);
            if(a=='Y'){
                out[i]=1;
            }
            else out[i]=0;
        }
        for(i=2;i<=n;i++){
            if(in[i-1]==1 && out[i]==1) path[i][i-1]=1;
            if(out[i-1]==1 && in[i]==1) path[i-1][i]=1;
        }
        for(i=1;i<=n-1;i++){
            if(out[i]==1 && in[i+1]==1)path[i][i+1]=1;
            if(in[i]==1 && out[i+1]==1)path[i+1][i]=1;
        }
        for(k=1;k<=n;k++){
            for(i=1;i<=n;i++){
                for(j=1;j<=n;j++){
                    if(path[i][k]==1 && path[k][j]==1)path[i][j]=1;
                }
            }
        }
        printf("Case #%d:\n",temp);
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(path[i][j]==1)printf("Y");
                else printf("N");
            }
            printf("\n");
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                path[i][j]=0;
            }
        }
        temp++;
    }
    return 0;
}
/*
5
2
YY
YY
2
NY
YY
2
NN
YY
5
YNNYY
YYYNY
10
NYYYNNYYYY
YYNYYNYYNY

8
2
YY
YY
2
NY
YY
2
NN
YY
5
YNNYY
YYYNY
10
NYYYNNYYYY
YYNYYNYYNY
20
YYNYNYNYNNYYYYYYNYNY
NYYYNYNYYNNYNYYNNYYY
50
NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
50
YNYYYYNYNYYYNYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYNYNYYYY
YYYYYYYYYYYYYYNYYYYYYYNYYYYYNYYYYNYYNYYYYNNYYYYYYY
*/
