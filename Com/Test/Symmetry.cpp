/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
int main()
{
    int n[1200],ni[1200];
    int i,ch;
    int q;
    int d,Max,ques;
    int cou,couold=-1;
    scanf("%d",&ques);
    while(ques--){
        scanf("%d",&q);
        for(i=0;i<q;i++)
            scanf("%d",&n[i]);
        cou = 0;
        for(i=0;i<q;i++){
            if(n[i]==0){
                cou++;
            }
            if(n[i]==1){
                if(cou%2==1 && cou>couold ){
                Max=i-cou/2;
                couold=cou;
                }
                cou=0;
            }

        }
        if(cou%2==1 && cou>couold)  Max=i-cou/2,couold=cou;
        if(couold==-1)printf("-1\n");
        else printf("%d\n",Max-1);
        cou = 0;
        couold=-1;
    }


    return 0;
}
/*
4
12
1 0 0 0 1 0 0 0 0 0 1 1
12
0 0 0 1 0 0 0 1 0 0 0 0
12
1 1 1 0 1 1 1 0 1 1 1 1
12
0 0 1 1 0 0 1 1 0 0 0 0 */
