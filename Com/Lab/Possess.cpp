/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    double k,D,Angle,x,y,a,b,ii,jj;
    scanf("%lf %lf",&k,&D);
    a = sqrt(pow(15-k,2)+pow(15,2));
    b = D/a;
    x = b*15+15;
    y = b*abs(15-k)+40;
    printf("%lf %lf",x,y);
    int jround = x/60;
    int iround = y/60;
    if(jround%2==1){
        jj=60-fmod(x,60);
    }
    else {
        jj=fmod(x,60);
    }
    printf("%.1lf",jj);

    return 0;
}
