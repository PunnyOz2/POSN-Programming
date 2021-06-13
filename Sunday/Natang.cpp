/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[360][640];
int main()
{
    char opr;
    int n,m,num,sti,stj,eni,enj,i,j;
    scanf(" %c %d %d",&opr,&m,&n);
    while(1){
        scanf(" %c",&opr);
        if(opr=='T')return 0;
        if(opr=='C'){
            scanf("%d %d %d %d %d",&num,&stj,&sti,&eni,&enj);
            if(sti>=n || stj>=m)continue;
            for(i=sti;i<min(n,sti+enj);i++){
                for(j=stj;j<min(m,stj+eni);j++){
                    a[i][j]=num;
                }
            }
        }
        if(opr=='G'){
            scanf("%d %d",&i,&j);
            printf("%d\n",a[j][i]);
        }
//        for(i=0;i<n;i++){
//            for(j=0;j<m;j++){
//                printf("%d ",a[i][j]);
//            }
//            printf("\n");
//        }
    }
    return 0;
}
/*
I 10 5
C 23 1 1 3 4
C 194 3 2 9 9
G 1 2
G 3 4
*/
