/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
#include<math.h>
char a[10000000];
int main()
{
    int n,i,m,j;
    scanf("%d",&n);
    if(n==1){
        printf("2\n");return 0;
    }
    for(i=3;i<10000000;i+=2)
        a[i]=1;
    m=sqrt(10000000);
    for(i=3;i<m;i+=2){
        if(a[i]!=0)
            for(j=i*i;j<10000000;j+=i)
                a[j]=0;

    }
    for(i=3,j=1; 1 ;i+=2){
        if(a[i]){
            j++;
            if(j==n){
                printf("%d\n",i); return 0;
            }
        }
    }

    return 0;
}
