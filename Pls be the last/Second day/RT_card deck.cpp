/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010];
map<int,int> mp1;
map<int,int> mp2;
map<int,int> mp3;
map<int,int> mp4;
int main()
{
    int i,num;
    scanf(" %s",a);
    int len=strlen(a);
    for(i=0;i<len;i+=3){
        num=(a[i+1]-'0')*10+(a[i+2]-'0');
        if(a[i]=='P'){
            if(mp1[num]!=0){printf("Wrong\n");return 0;}
            mp1[num]=1;
        }
        if(a[i]=='K'){
            if(mp2[num]!=0){printf("Wrong\n");return 0;}
            mp2[num]=1;
        }
        if(a[i]=='H'){
            if(mp3[num]!=0){printf("Wrong\n");return 0;}
            mp3[num]=1;
        }
        if(a[i]=='T'){
            if(mp4[num]!=0){printf("Wrong\n");return 0;}
            mp4[num]=1;
        }
    }
    printf("%d ",13-mp1.size());
    printf("%d ",13-mp2.size());
    printf("%d ",13-mp3.size());
    printf("%d ",13-mp4.size());
    return 0;
}
/*
P01K02H03H04
T02T10K11T02
*/
