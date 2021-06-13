#include <stdio.h>
#define HASH 500009;
char cat[35];
char a[1000100];
int H[500100];
int val[100100];
int POW[35];
int mark[100100];
int main(){
    int n,m,i,j,sum,temp,q,cou,len,cc,ii;
    POW[0]=1;
    for(i=1;i<=30;i++)POW[i]=POW[i-1]*2;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf(" %s",cat+1);
        sum=cat[1]-'0';
        for(j=2;j<=m;j++){
            sum*=2;
            sum+=cat[j]-'0';
        }
        temp=sum;
        temp%=HASH;
        while(H[temp]!=0){
            temp*=2;
            temp%=HASH;
        }
        H[temp]=i;
        val[i]=sum;
    }
    scanf("%d",&q);
    for(ii=1;ii<=q;ii++){
        cc=0;
        scanf("%d",&len);
        scanf(" %s",a+1);
        if(len<m){
            printf("OK\n");
            continue;
        }
        a[0]='0';
        sum=a[1]-'0';
        for(j=2;j<m;j++){
            sum*=2;
            sum+=a[j]-'0';
        }
        for(j=m;j<=len;j++){
            sum-=(a[j-m]-'0')*POW[m-1];
            sum*=2;
            sum+=(a[j]-'0');
            temp=sum;
            temp%=HASH;
            while(H[temp]!=0){
                if(val[H[temp]]==sum){
                    cc++;
                    mark[H[temp]]=ii;
                    break;
                }
                temp*=2;
                temp%=HASH;
            }
        }
        if(cc==0)printf("OK\n");
        else{
            for(i=1;i<=n;i++){
                if(mark[i]==ii)printf("%d ",i);
            }
            printf("\n");
        }
    }
}
/*
5 5
01001
10110
11100
10100
11111
2
15
101010101010101
20
11110110011111000010
*/
