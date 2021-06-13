#include<bits/stdc++.h>
using namespace std;
char a[120],b[120];
int main()
{
    int n,ch,lena,lenb,i,j,pause,temp;
    scanf("%d",&n);
    scanf(" %s",a+1);
    lena=strlen(a+1);
    lena--;
    for(i=0;i<n;i++){
        ch=0;
        scanf(" %s",b+1);
        lenb=strlen(b+1);
        temp=lena+1;
        if(lena>lenb){printf("No\n");continue;}
        for(j=1;j<=lenb;j++){
            if(a[j]=='*'){pause=j;break;}
            if(a[j]!=b[j]){ch=1;break;}
        }
        for(j=lenb;j>pause;j--){
            if(a[temp]=='*'){pause=j;break;}
            if(a[temp]!=b[j]){ch=1;break;}
            temp--;
        }
        if(ch==1)printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
/*
5
p*t
peat
peatt
mrpeatt
peatty
pot
*/
