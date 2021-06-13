#include<bits/stdc++.h>
using namespace std;
char a[1000100],b[1000100];
int sz;
int st[1000100],kmp[1000100];
char st2[1000100];
int main(){
    int q,i,lena,lenb,temp,cou,tempi,j;
    scanf("%d",&q);
    while(q--){
        memset(kmp,0,sizeof kmp);
        cou=0;
        sz=0;
        scanf(" %s",a+1);
        scanf(" %s",b+1);
        lena=strlen(a+1);
        lenb=strlen(b+1);
        j=0;
        for(i=2;i<=lenb;i++){
            while(j>0 && b[j+1]!=b[i])j=kmp[j];
            if(b[j+1]==b[i])j++;
            kmp[i]=j;
        }
        j=0;
        for(i=1;i<=lena;i++){
            while(j>0 && b[j+1]!=a[i])j=kmp[j];
            if(b[j+1]==a[i])j++;
            if(j==lenb){
                sz-=lenb-1;
                j=st[sz];
            }
            else{
                sz++;
                st[sz]=j;
                st2[sz]=a[i];
            }
        }
        if(sz==0){
            printf("No COI Secret Code\n");
        }
        else{
            st2[sz+1]=0;
            printf("%s\n",st2+1);
        }
    }
    return 0;
}
/*
3
CodeCodecubeCodecubecute
Codecube
CodeCodecubecubeCodecube
Codecube
CasecaseSensitive191
case
*/
