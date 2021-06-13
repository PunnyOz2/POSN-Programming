/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
#include<math.h>
int main()
{double x1,y1,x2,y2,x3,y3,r,a,b,c,s,Area1,Area2;
    scanf("%lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3,&r);
    a=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
    b=sqrt(pow(x3-x1,2)+pow(y3-y1,2));
    c=sqrt(pow(x3-x2,2)+pow(y3-y2,2));
    s=(a+b+c)/2;
    Area1=sqrt(s*(s-a)*(s-b)*(s-c));
    printf("%.2f\n",Area1);
    Area2=r*a+r*b+r*c+M_PI*pow(r,2);
    printf("%.2f\n",Area2);
    return 0;
}
