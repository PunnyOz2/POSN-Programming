/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
int main()
{
    int a,b,c,d,A,B,C;
    scanf("%d %d %d",&A,&B,&C);
    for(a=1;a<=100;a++){
        for(b=-100;b<=100;b++){
            for(c=1;c<=100;c++){
                    for(d=-100;d<=100;d++){
                        if (a*c==A && a*d+b*c==B && b*d==C){
                            printf("%d %d %d %d\n",a,b,c,d);
                            return 0;
                        }
                    }
            }
        }
    }
    printf("No Solution\n");
    return 0;
}
