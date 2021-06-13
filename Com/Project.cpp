#include<bits/stdc++.h>
char a[40],b[40];
long long lena,n,sum=0,c,n2,sum2;
int main(){
    int i,ch=1;
    scanf("%lld",&n);
    scanf("%lld",&n2);
    scanf(" %s",a);
    lena=strlen(a);
    for(i=0;i<lena;i++){
        if(isdigit(a[i])){
            if((a[i]-'0'>=n))printf("ERROR"),ch=0;
        }
        else{
            if((a[i]-'A'+10>=n))printf("ERROR"),ch=0;
        }
    }
    if(ch==1){
        for(i=lena-1,c=0;i>=0;i--,c++){
        if(isdigit(a[i]))sum+=(a[i]-'0')*pow(n,c);
        else sum+=(a[i]-'A'+10)*pow(n,c);
    }
    i=0;
    while(sum!=0){
        i++;
        sum2=sum%n2;
        if(sum2>=10) b[i]=(char)sum2-10+'A';
        else b[i]=(char)sum2+'0';
        sum/=n2;
    }
    for(i;i>=1;i--)
        printf("%c",b[i]);
    }
    return 0;
}
