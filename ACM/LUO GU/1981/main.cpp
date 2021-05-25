#include <cstdio>
const int mod = 10000;
int x,s,t;
char c;
int main(){
    while(scanf("%d",&t)!=EOF){
            x=0;s=0;
    while(scanf("%c",&c) && c != '\n'){
        scanf("%d",&x);
        if(c == '*') t = t * x % mod;
        else s = (s + t) % mod,t = x;
    }
    printf("%d\n",(s + t) % mod);
    }
    return 0;
}
