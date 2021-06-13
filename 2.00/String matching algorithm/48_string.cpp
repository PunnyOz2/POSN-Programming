/*
    TASK:Oh my god
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char text[2000100],pat[2000100];
long long cnt[30],ans;
int main()
{
    int q,lena,lenb,i;
    scanf("%d",&q);
    while(q--){
        scanf(" %s %s",pat,text);
        lena=strlen(pat),lenb=strlen(text);
        for(i=0;i<lenb;i++){
            if(i<lena)
                cnt[pat[i]-'a']++;
            ans+=cnt[text[i]-'a'];
            if(i+lena>=lenb)
                cnt[pat[i-lenb+lena]-'a']--;
        }
        printf("%lld\n",ans);
        ans=0;
        memset(cnt,0,sizeof cnt);
    }
    return 0;
}
/*
1
abaab
aababacab
*/
