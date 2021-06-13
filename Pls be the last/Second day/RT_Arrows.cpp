/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int n[1000100],cnt[1000100];
int main()
{
    int n,i,num,cou=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&num);
        if(cnt[num+1]>0){
            cnt[num+1]--;
            cnt[num]++;
        }
        else{
            cnt[num]++;
            cou++;
        }
    }
    printf("%d\n",cou);
    return 0;
}
