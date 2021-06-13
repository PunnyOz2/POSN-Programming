/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
int main()
{
    int n,a=0,b=0,c=0,d=0,e=0,ans=0,A,B,C,D,E;
    int quarter,eight;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d %d %d %d",&A,&B,&C,&D,&E);
        a+=A, b+=B, c+=C, d+=D, e+=E;
    }
    ans = a+b+(c/2);
    quarter = b;
    if(c%2==1)
        ans++,quarter+=2;
    if(quarter>=d)
        eight = (quarter-d)*2;
    else{
        ans+=(d-quarter)/4;
        if((d-quarter)%4!=0)
            ans++,eight=(4-((d-quarter))%4*2);
    }
    if(eight < e){
        ans+=(e-eight)/8;
        if((e-eight)%8!=0)
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}
