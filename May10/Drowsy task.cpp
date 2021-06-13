/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int mic[100100][26];
int mark[26][26];
char a[100100];
char b[3];
int main()
{
    int n,lena,i,j,k;
    scanf(" %s",a+1);
    scanf("%d",&n);
    lena=strlen(a+1);
    for(i=1;i<=lena;i++){
        for(j=0;j<26;j++)mic[i][j]=1<<30;
    }
    mic[0][0]=0;
    for(k=0;k<n;k++){
        scanf(" %s",b);
        mark[b[0]-'a'][b[1]-'a'] = mark[b[1]-'a'][b[0]-'a'] = 1;
    }
    for(i=1;i<=lena;i++){
        for(j=0;j<26;j++){
            mic[i][j]=min(mic[i][j],mic[i-1][j]+1);
            if(!mark[j][a[i]-'a']){
                mic[i][a[i]-'a']=min(mic[i][a[i]-'a'],mic[i-1][j]);
            }
        }
    }
    int Min=1<<30;
    for(i=0;i<26;i++){
        Min=min(Min,mic[lena][i]);
    }
    printf("%d\n",Min);
    return 0;
}
/*
minicontest
2
oc
mt
*/
