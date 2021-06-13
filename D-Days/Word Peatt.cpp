/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[1200];
int main()
{
    int n,ch,i=0,cou=0,len;
    scanf("%d",&n);
    ch=0;
    while(n>0){
        ch=0;
        scanf(" %s",a);
        len=strlen(a);
        if(a[0]>=65 && a[0]<=90)ch=1;
        for(i=1;i<len;i++){
            if(a[i]=='.' || a[i]=='?' || a[i]=='!'){
                if(ch==1)cou++;
                printf("%d\n",cou),cou=0,n--,ch=0;
            }
            else if(a[i]<97 || a[i]>122)ch=0;
        }
        if(ch==1)cou++;
    }
    return 0;
}
/*
2
An3 ant Peatty. Pen apple Pie pen!
*/
