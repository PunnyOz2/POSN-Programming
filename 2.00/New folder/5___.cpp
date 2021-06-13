/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[1000010],b[1000010];
int main()
{
	int q,cou,lena,lenb,j,i;
	scanf("%d",&q);
	while(q--){
        scanf(" %s %s",a,b);
        lena=strlen(a),lenb=strlen(b);
        cou=0;
        if(lenb<lena){printf("No\n");continue;}
        i=0,j=0;
        while(i<lena&&j<lenb){
            if(a[i]==b[j])
                i++,j++;
            else j++;
            if(i==lena){
                printf("Yes\n");goto jump;
            }
        }
        printf("No\n");
        jump :;
    }
    return 0;
}
/*
2
Patanome
Peathandsome
Peta
Peatt
*/
