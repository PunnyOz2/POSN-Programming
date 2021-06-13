/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q,n,i,j;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            for(j=0;j<2*n+2+n-1-i;j++)
                printf(" ");
            for(j=0;j<1+2*i;j++)
                printf("*");
                printf("\n");
        }


        for(i=0;i<n;i++) printf(" ");
        for(i=0;i<n;i++) printf("*");
        for(j=0;j<3+n*2;j++)printf(" ");
        for(i=0;i<n;i++) printf("*");
        printf("\n");


        for(i=0;i<n-1;i++){
            for(j=0;j<n;j++) printf(" ");
            for(j=0;j<n-i-1;j++)printf("*");
            printf(" ");
            for(j=0;j<3+n*2+2*i;j++)printf("+");
            printf(" ");
            for(j=0;j<n-i-1;j++)printf("*");
            printf("\n");
        }


        for(j=0;j<n+1;j++) printf(" ");
        for(j=0;j<3+n*2+2*(n-1);j++)printf("+");
        printf("\n");


        for(i=0;i<n;i++){
            for(j=0;j<n-1-i;j++) printf(" ");
            for(j=0;j<i+1;j++)
                printf("*");
            printf(" ");
            for(j=0;j<3+n*2+2*(n-1);j++)printf("+");
            printf(" ");
            for(j=0;j<i+1;j++)
                printf("*");
            printf("\n");
        }


        for(i=0;i<n-1;i++){
            for(j=0;j<i+1;j++)printf(" ");
            for(j=n;j>i+1;j--)printf("*");
            printf(" ");
            for(j=0;j<3+n*2+2*(n-1);j++)printf("+");
            printf(" ");
            for(j=n;j>i+1;j--)printf("*");
            printf("\n");
        }


        for(j=0;j<n+1;j++) printf(" ");
        for(j=0;j<3+n*2+2*(n-1);j++)printf("+");
        printf("\n");


        for(i=0;i<n-1;i++){
            for(j=0;j<n;j++) printf(" ");

            for(j=0;j<i+1;j++)printf("*");
            printf(" ");

            for(j=0;j<3+n*2+2*(n-1)-2*i-2;j++)printf("+");

            printf(" ");
            for(j=0;j<i+1;j++)printf("*");

            printf("\n");
        }


        for(i=0;i<n;i++) printf(" ");
        for(i=0;i<n;i++) printf("*");
        for(j=0;j<3+n*2;j++)printf(" ");
        for(i=0;i<n;i++) printf("*");
        printf("\n");


        for(i=0;i<n;i++){
            for(j=0;j<2*n+2+i;j++)
                printf(" ");
            for(j=0;j<2*n-1-2*i;j++)
                printf("*");
                printf("\n");
        }


    }

    return 0;
}
