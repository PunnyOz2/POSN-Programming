/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[1200],b[1200],mic[1200][1200],c[2400];
int main()
{
	scanf(" %s",a+1);
	scanf(" %s",b+1);
	int lena=strlen(a+1);
	int lenb=strlen(b+1);
	int q,i,j;
	scanf("%d",&q);
	while(q--){
        mic[0][0]=1;
        scanf(" %s",c+1);
        for(i=1;i<=lena;i++){
            if(mic[i-1][0]==1 && a[i]==c[i])
                mic[i][0]=1;
        }
        for(i=1;i<=lenb;i++){
            if(mic[0][i-1]==1 && b[i]==c[i])
                mic[0][i]=1;
        }
        for(i=1;i<=lena;i++){
            for(j=1;j<=lenb;j++){
                if(mic[i][j-1]==1 && b[j]==c[i+j])mic[i][j]=1;
                else if(mic[i-1][j]==1 && a[i]==c[i+j])mic[i][j]=1;
            }
        }
        if(mic[lena][lenb]==1)printf("Yes\n");
        else printf("No\n");
        memset(mic,0,sizeof mic);
	}
    return 0;
}
/*
BAB
AB
4
BAABB
BABAB
ABBAB
BBABA
*/
