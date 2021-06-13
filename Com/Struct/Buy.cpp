/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
struct prod{
    char a[4];
    int b;
    int c;
}prod[3];
int main()
{
    FILE *fp;
    fp = fopen("C:receipt.txt","w");
    int sum=0,i;
    for(i=0;i<3;i++)
        scanf(" %s %d %d",prod[i].a,&prod[i].b,&prod[i].c);
    fprintf(fp,">>>>> Report Output <<<<<\n");
    fprintf(fp,"ID\tprice\tamount\n");
    for(i=0;i<3;i++){
        fprintf(fp,"%s\t%d\t%d\n",prod[i].a,prod[i].b,prod[i].c);
        sum+=prod[i].b*prod[i].c;
    }
    fprintf(fp,"Total : %d",sum);
    fclose(fp);
    return 0;
}
