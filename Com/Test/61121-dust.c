#include<stdio.h>
int main()
{
    int n,i,j,o,g,o2,cou=0;
    scanf("%d",&n);
    o = n*2-1;
    o2 = n;
    for(i=0;i<o2;i++){
        for(g=0;g<n-i-1;g++){
            printf("-");}
        for(g=0;g<=i;g++){
            if(i==n-1 && g==i){
                printf("*");
            }
            else {printf("+");}
            }
        for(g=0;g<i;g++){
                printf("+");}
        for(g=0;g<n-i-1;g++){
            printf("-");}
            printf("\n");
        cou++;
        }
    for(i=0;i<o2-1;i++){
        for(g=0;g<=i;g++){
                printf("-");}
        for(g=0;g<n-i-1;g++){
            printf("+");}
        for(g=1;g<n-i-1;g++){
            printf("+");}
        for(g=0;g<=i;g++){
                printf("-");}

        printf("\n");


    }




    return 0;
}
