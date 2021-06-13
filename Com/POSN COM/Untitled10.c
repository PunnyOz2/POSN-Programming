#include <stdio.h>
int main (){
    int a;
    int n;
    int m;
    int o;
    scanf("%d",&n);
    for(a=1;a<=n;a++){

        for (m=1;m<=a;m++){
            printf(" ");}

        for(o=n;o>=a;o--){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
