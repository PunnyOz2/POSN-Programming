/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
int main()
{
    int num;
    int q;
    int g,k,Minw_ok,num10,Num;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&g,&k);
        if((g-10)%100==0)
            Minw_ok=(g-10)/100;
        else if((g-10)%100!=0)
            Minw_ok=(g-10)/100+1;
        if(Minw_ok%k==0)
            num10 = Minw_ok/k;
        else if(Minw_ok%k!=0)
            num10 = Minw_ok/k + 1;
        if((g-10-10*num10)%100==0)
            Num = (g-10-10*num10)/100;
        else if((g-10-10*num10)%100!=0)
            Num = (g-10-10*num10)/100 +1;
    printf("%d",Num);

    }


    return 0;
}
