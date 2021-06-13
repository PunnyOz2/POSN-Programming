/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
#include <math.h>
int main()
{
    double a,b,c,Ans;
    scanf("%lf %lf %lf",&a,&b,&c);
    if(c==0.00){
        Ans=sqrt(pow(a,2)+pow(b,2));
        printf("%.2lf",Ans);
    }
    else if(b==0.00){
        Ans=sqrt(pow(c,2)-pow(a,2));
        printf("%.2lf",Ans);
    }
    else if(a==0.00){
        Ans=sqrt(pow(c,2)-pow(b,2));
        printf("%.2lf",Ans);
    }


    return 0;
}
