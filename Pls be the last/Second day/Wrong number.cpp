/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char num[10];
int main()
{
    int n,sum=0,ans=0,i,len,j,sum2=0,temp;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf(" %s",num);
        len=strlen(num);
        sum=0;
        for(j=0;j<len-1;j++){
            sum*=10;
            sum+=num[j]-'0';
        }
        temp=num[len-1]-'0';
        sum2=1;
        while(temp--){
            sum2*=sum;
        }
        ans+=sum2;
    }
    printf("%d\n",ans);
    return 0;
}
/*
2
212
1253
*/
