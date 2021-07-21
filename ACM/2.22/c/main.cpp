#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ul;
int line(ul x,ul y){
    int ans=0;
    int tmp=y;
    while(y){
        y=y/10;
        ans++;
    }
    return x*pow(10,ans)+tmp;
}

bool judge (ul x,ul y){
     int tmp1=x*y;
     int tmp2=line(x,y)-x-y;
     if(tmp1==tmp2)
        return 1;
     else
        return 0;
}

int main()
{
    int n,cnt;
    scanf("%d",&n);
    ul x,y;
    while(n--){
        cnt=0;
        scanf("%llu%llu",&x,&y);
        for(ul i=1;i<=x;i++){
            for(ul j=1;j<=y;j++){
                  if(judge(i,j))
                  cnt++;
            }
        }
       printf("%d\n",cnt);
    }
    return 0;
}
