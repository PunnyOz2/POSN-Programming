#include<bits/stdc++.h>
using namespace std;
char a[120],b[120];
int main(){
    int q,j,i,mid,lena,lenb,ch,bac,temp;
    scanf("%d",&q);
    scanf(" %s",a+1);
    lena=strlen(a+1);
    while(q--){
        ch=0;
        scanf(" %s",b+1);
        lenb=strlen(b+1);
        if(lenb<lena-1){printf("No\n");continue;}
        for(i=1;i<=lenb;i++){
            if(a[i]=='*'){
                break;
            }
            else if(a[i]!=b[i]){
                ch=1;break;
            }
        }
        temp=lena;
        for(i=lenb;i>=1;i--){
            if(a[temp]=='*'){
                break;
            }
            else if(a[temp]!=b[i]){
                ch=1;break;
            }
            temp--;
        }
        if(ch==1){printf("No\n");continue;}
        else printf("Yes\n");
    }
    return 0;
}
/*
5
p*ty
peatty
peat
peatt
mrpeatt
pot

5
p*t
peat
peatt
mrpeatt
peatty
pot
*/
