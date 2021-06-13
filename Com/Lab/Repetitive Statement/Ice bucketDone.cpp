/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
int main()
{
    int q,money,num,i,ans,ni;
    scanf("%d",&q);
    while(q--){
        ans=0;
        scanf("%d %d",&money,&num);
        if(money-100<=0){
            printf("0");
            continue;
        }
        ans++;
        money-=10;
        while((money)>(num)*100){
            if(money<=(num)*100){
                ans++;
                break;
            }
            else if(money-10>(num-1)*100){money-=10; ans++; money-=(num-1)*100 ;}
            }
            printf("%d",ans);
            printf("\n");
        }


    return 0;
}
