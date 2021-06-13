/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
int main()
{
    int i;
    int n;
    float Ans;
    float a[20];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%f",&a[i]);
    }
    for(i=0;i<n;i++){
        Ans=Ans+a[i];
        //Ans+=a[i]

    }
    printf("%.3lf\n",Ans);
    printf("%.3lf\n",Ans/n);
    return 0;
}
