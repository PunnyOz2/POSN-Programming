/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[1000007],tmp[1000007],ans[1000007];
int p[1000007],sta[1000007];
int main()
{
    int q,j,i,lena,lentmp;
    scanf("%d",&q);
    while(q--){
        memset(p,0,sizeof p);
        scanf(" %s",a+1);
        scanf(" %s",tmp+1);
        j=0;
        lentmp=strlen(tmp+1);
        lena=strlen(a+1);
        for(i=2;i<=lentmp;i++){
            while(j!=0 && tmp[j+1]!=tmp[i])j=p[j];
            if(tmp[j+1]==tmp[i])j++;
            p[i]=j;
        }
        int top =0;
        j=0;
        for(i=1;i<=lena;i++){
            while(j!=0 && tmp[j+1]!=a[i])j=p[j];
            if(tmp[j+1]==a[i])j++;
            if(j==lentmp){
                top-=lentmp-1;
                j=sta[top];
            }
            else{
                sta[++top]=j;
                ans[top]=a[i];
            }
        }
        if(top==0)printf("No COI Secret Code\n");
        else{
            ans[top+1]=0;
            printf("%s\n",ans+1);
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
