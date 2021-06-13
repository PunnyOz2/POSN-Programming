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
    char N[6];
    int i,a,b,c,d,e,A,B,C,D,E;
    int val;
    for(i=0;i<5;i++){
        scanf("%s",N);
        val=atoi(N);
        a=(val/10000);
        b=(val-a*10000)/1000;
        c=(val-a*10000-b*1000)/100;
        d=(val-a*10000-b*1000-c*100)/10;
        e=(val-a*10000-b*1000-c*100-d*10);
        if(a!=0){
             A = a;
             B = pow(b,2);
             C = pow(c,3);
             D = pow(d,4);
             E = pow(e,5);
        }
        else if(b!=0){
             A = 0;
             B = b;
             C = pow(c,2);
             D = pow(d,3);
             E = pow(e,4);
        }
        else if(c!=0){
             A = 0;
             B = 0;
             C = c;
             D = pow(d,2);
             E = pow(e,3);
            }
        else if(d!=0){
             A = 0;
             B = 0;
             C = 0;
             D = d;
             E = pow(e,2);
        }
        else{
             A = 0;
             B = 0;
             C = 0;
             D = 0;
             E = e;
        }
        if(val==A+B+C+D+E){
            printf("Y");
        }
        else{
            printf("N");
        }
    }

    return 0;
}
