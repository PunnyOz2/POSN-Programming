/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 500009
char a[50050],b[105],hashh[55][500010][55],mark[55][500010],c[105];
int main()
{
    int n,m,i,j,len,num,h,q,qq;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf(" %s",b);
        len=strlen(b);
        num=0;
        for(j=0;j<len;j++){
            num*=29;
            num+=(b[j]-'a');
            num%=mod;
        }
        h=num;
        while(hashh[len][h][0]!='\0'){
            h++;h%=mod;
        }
        strcpy(hashh[len][h],b);
    }
    scanf("%d",&q);
    for(qq=1;qq<=q;qq++){
        scanf(" %s",a);
        int cnt=0;
        len=strlen(a);
        for(i=0;i<len;i++){
            num=0;
            for(j=0;i+j<len &&j<50 ;j++){
                num*=29;
                num+=(a[i+j]-'a');
                num%=mod;
                h=num;
                while(hashh[j+1][h][0]!='\0'){
                    if(strncmp(&a[i],hashh[j+1][h],j+1)==0){
                        if(mark[j+1][h]==qq)    break;
                        mark[j+1][h]=qq;
                        if(cnt==0)  memset(c,'\0',sizeof c),strcpy(c,hashh[j+1][h]);
                        cnt++;
                    }
                    else h++,h%=mod;
                }
            }
        }
        if(cnt==0)  printf("NO\n");
        else if(cnt==1) printf("%s\n",c);
        else        printf("AMBIGUOUS\n");
    }
    return 0;
}
/*
5
ambiguous
metamorphism
inevitably
impeccable
constellation
3
inevitable
abcdefghijklmetamorphismnopqrstuvwxyz
itsambiguousbecausethereisconstellationtoo
*/
