#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
using namespace std;
char a[100100];
int main(){
    freopen ("in.txt","r",stdin);
    freopen ("out2.txt","w",stdout);
    int q,n,i,cou1,temp=1,cou2;
    scanf("%d",&q);
    while(q--){
        cou1=0;
        cou2=0;
        scanf("%d",&n);
        scanf("%s",a);
        for(i=0;i<n;i++){
            //printf("%d ",i);
            if(a[i]==65)cou1++;
            else if(a[i]==66)cou2++;
        }
        if(cou1-cou2>1 || cou1-cou2<-1)cout << "Case #" << temp <<": N\n" ;
        else cout << "Case #" << temp <<": Y\n" ;
        temp++;
    }
    fclose (stdout);
}
/*
6
3
BAB
3
BBB
5
AABBA
7
BAAABAA
11
BBBAABAAAAB
11
BABBBABBABB
*/
